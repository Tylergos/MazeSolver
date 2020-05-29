//David Tyler Gosbee
//201905838
//x2019fep@stfx.ca

#pragma once

#include "PriorityNode.h"

template <class T>
class LinkedMinPriorityQueue
{
private: 
	int _size; //int representing size of queue
	PriorityNode<T>* _front; //pointer to front of queue
	PriorityNode<T>* _rear; //pointer to back of queue

public:
	LinkedMinPriorityQueue();
	LinkedMinPriorityQueue(const LinkedMinPriorityQueue<T>& obj);
	~LinkedMinPriorityQueue();

	void enqueue(T element, double priority);
	T dequeue();
	int size();
	bool is_empty();
};


template <class T>
LinkedMinPriorityQueue<T>::LinkedMinPriorityQueue()
{
	//default constructor with default values
	_size = 0;
	_front = nullptr;
	_rear = nullptr;
}

template <class T>
LinkedMinPriorityQueue<T>::LinkedMinPriorityQueue(const LinkedMinPriorityQueue<T>& obj)
{
	//copy constructors to copy other queue
	_front = new PriorityNode<T>(*obj._front);
	PriorityNode<T>* otherCur = obj._front->getNext(); //other objects current node
	PriorityNode<T>* cur = _front; //this objects current node
	while (otherCur != nullptr)
	{
		cur->setNext(new PriorityNode<T>(*otherCur));
		if (otherCur == obj._rear)
		{
			_rear = cur->getNext();
		}
		otherCur = otherCur->getNext();
		cur = cur->getNext();
	}
	_size = obj._size;
}

template <class T>
LinkedMinPriorityQueue<T>::~LinkedMinPriorityQueue()
{
	//deconstructor deletes queue
	while (!is_empty())
	{
		dequeue();
	}
}

template <class T>
void LinkedMinPriorityQueue<T>::enqueue(T element, double priority)
{
	//enqueues an element with a priority from the parameters in the correct order

	//Checks if queue is empty, and sets front and rear accordingly
	if (is_empty())
	{
		_front = new PriorityNode<T>(element, priority);
		_rear = _front;
	}
	else
	{
		PriorityNode<T>* temp;
		PriorityNode<T>* cur = _front;

		//if the new element is lower priority than the front, sets the front accordingly
		if (cur->getPriority() > priority)
		{
			temp = cur;
			_front = new PriorityNode<T>(element, priority);
			_front->setNext(temp);
		}
		else
		{
			//while there is a next cell and it has a lower priority than the one being enqueued
			while (cur->getNext() != nullptr && cur->getNext()->getPriority() <= priority)
			{
				cur = cur->getNext();
			}

			//if current cell is rear, sets the rear accordingly after being enqueued
			if (cur == _rear)
			{
				cur->setNext(new PriorityNode<T>(element, priority));
				_rear = cur->getNext();
			}
			else
			{
				temp = cur->getNext();
				cur->setNext(new PriorityNode<T>(element, priority));
				cur->getNext()->setNext(temp);
			}
		}
	}
	_size++;
}

template <class T>
T LinkedMinPriorityQueue<T>::dequeue()
{
	//dequeues and returns the first element in the queue

	//if the queue is empty, throw an error
	if (is_empty())
	{
		//throw std::exception();
	}

	T temp = _front->getData();
	PriorityNode<T>* tempNode = _front;
	_front = _front->getNext();
	_size--;
	delete tempNode;
	return temp;
}

template <class T>
int LinkedMinPriorityQueue<T>::size()
{
	//returns the size of the queue
	return _size;
}

template <class T>
bool LinkedMinPriorityQueue<T>::is_empty()
{
	//returns whether the queue is empty
	return _size == 0;
}