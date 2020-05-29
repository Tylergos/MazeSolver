//David Tyler Gosbee
//201905838
//x2019fep@stfx.ca

#include "Maze.h"

Maze::Maze()
{
	//default constructor sets up maze with default values
	_height = 0;
	_width = 0;
	_startX = 0;
	_startY = 0;
	_endX = 0;
	_endY = 0;
	_maze = nullptr;
}


Maze::Maze(std::string fileName)
{
	//constructor sets up maze with values from a file
	std::ifstream mazeFile(fileName);
	std::string line;

	// Read height and width
	std::getline(mazeFile, line);
	_height = std::stoi(line);
	std::getline(mazeFile, line);
	_width = std::stoi(line);

	// Start the 2D array of Cell pointers
	_maze = new Cell**[_height];

	// Create the maze
	for (int i = 0; i < _height; i++)
	{
		std::getline(mazeFile, line);
		_maze[i] = new Cell*[_width];

		for (int j = 0; j < _width; j++)
		{
			_maze[i][j] = new Cell(line[j], j, i);

			if (_maze[i][j]->isStart())
			{
				_startX = j;
				_startY = i;
			}
			if (_maze[i][j]->isEnd())
			{
				_endX = j;
				_endY = i;
			}
		}
	}
}

// The maze object is the one making the cells, so it's 
// responsible for deleting all the cells
Maze::~Maze()
{
	for (int i = 0; i < _height; i++)
	{
		for (int j = 0; j < _width; j++)
		{
			delete _maze[i][j];
		}
		delete[] _maze[i];
	}
	delete[] _maze;
}

Cell* Maze::getStart()
{
	//Returns pointer to the starting cell
	return _maze[_startY][_startX];
}

void Maze::draw()
{
	//draws the maze
	std::cout << this->to_string() << "\n" << std::endl;
}

bool Maze::isLocationValid(int x, int y)
{
	//returns whether the location is valid
	return y >= 0 && y < _height && x >= 0 && x < _width;
}

std::string Maze::to_string()
{
	//returns the maze as a string
	std::string s = "";

	for (int i = 0; i < _height; i++)
	{
		for (int j = 0; j < _width; j++)
		{
			s+= _maze[i][j]->getSymbol();
		}
		s += "\n";
	}
	return s;
}

Cell* Maze::getNextNeighbour(Cell* cur)
{
	//returns the next valid cell
	int x = cur->getX();
	int y = cur->getY();

	// Go clockwise
	// note, y-1 means up, not down
	int xs[4] = { x,     x + 1, x,     x - 1 };
	int ys[4] = { y - 1, y,     y + 1, y };

	int nX = 0;
	int nY = 0;

	// Iterate over the 4 possible neighbours 
	for (int i = 0; i < 4; i++)
	{
		nX = xs[i];
		nY = ys[i];

		// If the location is in the map 
		if (isLocationValid(nX, nY))
		{
			// If the cell is eligible to move into (not currently in stack, or looked)
			// Basically, if it's open or it's the end. 
			if (_maze[nY][nX]->getSymbol() == ' ' || _maze[nY][nX]->getSymbol() == 'E')
			{
				return _maze[nY][nX];
			}
		}
	}

	// If we get here, then there is no eligible neighbour
	return nullptr;
}

Cell* Maze::getEnd()
{
	//returns the end of the maze
	return _maze[_endY][_endX];
}

double Maze::distanceToEnd(Cell* cur)
{
	//returns the distance to the end
	double curX = (double)cur->getX();
	double curY = (double)cur->getY();

	return std::sqrt(std::pow(_endX - curX, 2) + std::pow(_endY - curY, 2));
}


int Maze::drawFinalPath()
{
	//draws the maze and the steps that were taken to reach the end,
	//and returns the number of steps taken
	int steps = 1;
	Cell* cur = getEnd();
	int stm = cur->getStepsToMe();

	while (stm >= 0)
	{
		steps++;
		cur->setSymbol('@');

		int x = cur->getX();
		int y = cur->getY();

		int nX = 0;
		int nY = 0;

		// Go clockwise
		// note, y-1 means up, not down
		int xs[4] = { x,     x + 1, x,     x - 1 };
		int ys[4] = { y - 1, y,     y + 1, y };

		for (int i = 0; i < 4; i++)
		{
			nX = xs[i];
			nY = ys[i];

			// If the location is in the map 
			if (isLocationValid(nX, nY))
			{
				if (_maze[nY][nX]->getStepsToMe() == cur->getStepsToMe() - 1  && _maze[nY][nX]->getSymbol() == '.')
				{
					cur = _maze[nY][nX];
					stm = cur->getStepsToMe();
					break;
				}
			}
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(250));
		draw();

		if (stm == 0)
		{
			cur->setSymbol('@');
			break;
		}
	}
	return steps;
}