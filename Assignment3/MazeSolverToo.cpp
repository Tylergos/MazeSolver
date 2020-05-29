//David Tyler Gosbee
//201905838
//x2019fep@stfx.ca

#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h> 

#include <chrono>
#include <thread>
#include <iostream>

#include "Cell.h"
#include "LinkedMinPriorityQueue.h"
#include "Maze.h"
#include "PriorityNode.h"

int main(int argc, char* argv[])
{
	std::chrono::milliseconds timespan(300); //Time delay between steps
	//Opens maze file
	Maze* maze = new Maze(argv[1]);
	Cell* start = maze->getStart();

	start->setStepsToMe(0);
	Cell* curCell;

	LinkedMinPriorityQueue<Cell*>* queue = new LinkedMinPriorityQueue<Cell*>();

	//starts the queue at start of maze
	queue->enqueue(start, maze->distanceToEnd(start));
	maze->draw();

	int i = 0;
	Cell* temp;

	//Runs until queue is empty or until end is reached
	while (!queue->is_empty())
	{
		//current cell is set as first in queue
		curCell = queue->dequeue();
		i++;

		//Exits loop if its the end
		if (curCell->isEnd())
		{
			curCell->setSymbol('X');
			break;
		}


		curCell->setSymbol('O');
		maze->draw();
		
		//For each of the neighbours
		for (int j = 0; j < 4; j++)
		{
			//gets neighbour and sets information of the checked neighbour
			//and is added to queue
			temp = maze->getNextNeighbour(curCell);
			if (temp != nullptr)
			{
				temp->setStepsToMe(curCell->getStepsToMe() + 1);
				queue->enqueue(temp, maze->distanceToEnd(temp));
				temp->setSymbol('o');
			}
		}

		std::this_thread::sleep_for(timespan);
		maze->draw();
		curCell->setSymbol('.');
	}

	//output final screen
	int steps = maze->drawFinalPath();
	std::cout << "Steps: " << steps << "\tIterations: " << i << std::endl;
	maze->draw();

	//deletes stuff
	delete maze;
	delete queue;
	_CrtDumpMemoryLeaks();
}
