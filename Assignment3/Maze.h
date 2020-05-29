//David Tyler Gosbee
//201905838
//x2019fep@stfx.ca

#pragma once

#include <chrono>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <thread>

#include "Cell.h"

class Maze
{
private:
	int _height; //Height of maze
	int _width; //Width of maze
	int _startX; //X location of start
	int _startY; //Y location of start
	int _endX; //X location of end
	int _endY; //Y location of end

	Cell*** _maze; //Array of cell pointers

public:
	Maze();
	Maze(std::string fileName);
	~Maze();

	Cell* getStart();
	bool isLocationValid(int x, int y);
	
	void draw();
	std::string to_string();

	// Changed a little
	Cell* getNextNeighbour(Cell* cur);

	// New
	Cell* getEnd();
	double distanceToEnd(Cell* cur);
	int drawFinalPath();

};

