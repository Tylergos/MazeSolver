//David Tyler Gosbee
//201905838
//x2019fep@stfx.ca

#pragma once
class Cell
{
private:
	char _symbol; //character representing symbol of cell
	bool _isStart; //boolean stating whether cell is start
	bool _isEnd; //boolean stating whether cell is end
	int _x; //x coordinate of cell
	int _y; //y coordinate of cell

	// New
	int _stepsToMe; //int representing steps from start


public:
	Cell();
	Cell(char c, int x, int y);
	Cell(const Cell& obj);
	~Cell();

	bool isEnd();
	bool isStart();
	char getSymbol();
	void setSymbol(char c);
	int getX();
	int getY();

	// New
	int getStepsToMe();
	void setStepsToMe(int steps);
};

