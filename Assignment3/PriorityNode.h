//David Tyler Gosbee
//201905838
//x2019fep@stfx.ca

#pragma once

template <class T>
class PriorityNode
{
private:
	PriorityNode<T>* _next; //pointer to next node
	T _data; //data in the node
	double _priority; //priority of the node

public:
	PriorityNode();
	PriorityNode(T data, double priority);
	PriorityNode(const PriorityNode<T>& obj);
	~PriorityNode();

	PriorityNode<T>* getNext();
	void setNext(PriorityNode<T>* node);
	T getData();
	void setData(T data);

	double getPriority();
};

template <class T>
PriorityNode<T>::PriorityNode()
{
	//default constructor creates node with default data
	_next = nullptr;
	_data = 0;
	_priority = 0;
}

template <class T>
PriorityNode<T>::PriorityNode(T data, double priority)
{
	//Constructor creates node with data and priority from parameters
	_data = data;
	_priority = priority;
	_next = nullptr;
}

template <class T>
PriorityNode<T>::PriorityNode(const PriorityNode<T>& obj)
{
	//Copy constructor to copy another node
	_data = obj._data;
	_priority = obj._priority;
	_next = obj._next;
}

template <class T>
PriorityNode<T>::~PriorityNode()
{
	//not deleting anything
}

template <class T>
PriorityNode<T>* PriorityNode<T>::getNext()
{
	//returns the next pointer
	return _next;
}

template <class T>
void PriorityNode<T>::setNext(PriorityNode<T>* node)
{
	//sets the next pointer
	_next = node;
}

template <class T>
T PriorityNode<T>::getData()
{
	//returns the data
	return _data;
}

template <class T>
void PriorityNode<T>::setData(T data)
{
	//sets the data
	_data = data;
}

template <class T>
double PriorityNode<T>::getPriority()
{
	//returns the priority
	return _priority;
}