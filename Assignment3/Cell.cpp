//David Tyler Gosbee
//201905838
//x2019fep@stfx.ca

#include "Cell.h"

Cell::Cell()
{
	//default constructor sets up the cell with default values
	_symbol = ' ';
	_isStart = false;
	_isEnd = false;
	_x = 0;
	_y = 0;
	_stepsToMe = -1;
}

Cell::Cell(char c, int x, int y)
{
	//constructor sets up cell with character, and position
	_symbol = c;
	_x = x;
	_y = y;
	_isStart = (_symbol == 'S');
	_isEnd = (_symbol == 'E');
	_stepsToMe = -1;
}


Cell::Cell(const Cell& obj)
{
	//Copy constructor, copies other cell attributes
	_symbol = obj._symbol;
	_isStart = obj._isStart;
	_isEnd = obj._isEnd;
	_x = obj._x;
	_y = obj._y;
	_stepsToMe = obj._stepsToMe;
}

Cell::~Cell()
{
	// Nothing special
}

char Cell::getSymbol()
{
	//returns character symbol
	return _symbol;
}

void Cell::setSymbol(char c)
{
	//sets the symbol of the cell
	_symbol = c;
}

bool Cell::isStart()
{
	//returns whether the cell is the start
	return _isStart;
}

bool Cell::isEnd()
{
	//returns whether the cell is the end
	return _isEnd;
}

int Cell::getX()
{
	//returns the x coordinate of the cell
	return _x;
}

int Cell::getY()
{
	//returns the y coordinate of the cell
	return _y;
}

// New

int Cell::getStepsToMe()
{
	//returns the attribute stepsToMe
	return _stepsToMe;
}


void Cell::setStepsToMe(int steps)
{
	//sets the attribute stepsToMe
	_stepsToMe = steps;
}
