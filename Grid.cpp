#include <vector> //For storing all of the cell objects
#include <iostream> //For writing the grid to the console
#include <time.h> //Helps to provide a "random" seed upon each run 
				  //on randomize()
#include <stdlib.h> //Contains srand and rand

//To read from a user provided file
#include <fstream>
#include <string>

//Project specific classes
#include "Grid.h"
#include "Cell.h"

using namespace std;

//------------------------------------------
//---------Constructors---------------------
//------------------------------------------

	Grid::Grid(int size)
	{
		width_ = size;
		height_ = size;

		init();
	}

	Grid::Grid(int w, int h)
	{
		width_ = w;
		height_ = h;

		init();
	}

	Grid::Grid(string filename)
	{
		init(filename);
	}

//------------------------------------------
//---------Destructor-----------------------
//------------------------------------------

	Grid::~Grid(void) { }

//------------------------------------------
//---------Inspectors-----------------------
//------------------------------------------

	int Grid::getWidth() const
	{
		return width_;
	}

	int Grid::getHeight() const
	{
		return height_;
	}

	vector<Cell> Grid::getCells() const
	{
		return cells_;
	}

//------------------------------------------
//---------Facilitators---------------------
//------------------------------------------

	void Grid::init()
	{
		for (int i = 0; i < width_*height_; i++)
		{
			int xPos = i / height_;
			int yPos = i % width_;

			Cell c(xPos,yPos);
			cells_.push_back(c);
		}
	}

	void Grid::init(string filename)
	{
		ifstream infile(filename.c_str());
		string line;

		int yPos = 0;

		while (getline(infile, line))
		{
			int xPos = 0;

			for (int i = 0; i < line.length(); i++)
			{
				if (line[i] == '0')
				{
					Cell c(xPos, yPos, false);

					cells_.push_back(c);

					xPos++;
				}
				
				if (line[i] == '1')
				{
					Cell c(xPos, yPos, true);

					cells_.push_back(c);

					xPos++;
				}
			}

			yPos++;

			width_ = xPos;
		}

		height_ = yPos;

	}

	void Grid::randomize(int prob)
	{
		srand(time(NULL));

		for (int i = 0; i < width_*height_; i++)
		{
			int coinFlip = rand()%prob;
			bool alive;

			if (coinFlip == 0)
				alive = true;
			else
				alive = false;

			cells_[i].setAlive(alive);
		}
	}

	void Grid::newGeneration()
	{	
		for (int i = 0; i < width_*height_; i++)
		{
			cells_[i].setNeighbors(neighborCount(i));
		}

		for (int i = 0; i < width_*height_; i++)
		{
			int neighbors = cells_[i].getNeighbors();

			if (cells_[i].isAlive())
			{
				if ((neighbors == 2) || (neighbors == 3))
					cells_[i].setAlive(true);
				else
					cells_[i].setAlive(false);
			} else {
				if (neighbors == 3)
					cells_[i].setAlive(true);
			}
		}
	}

	int Grid::neighborCount(int i)
	{
		//Compensating for zero-indexing on the cells_ x and y
		//But the positional shifts later on need the original
		//width and height, so I created an extra set of variables
		int width = width_ - 1;
		int height = height_ - 1;

		int x = cells_[i].getX();
		int y = cells_[i].getY();

		int neighbors = 0;

		if (i % width_ == 0)
			cout << endl;

		//Horizontal
		if (x != 0)
		{
			if (cells_[i - 1].isAlive())
			{
				neighbors++;
			}
		}

		if (x != width)
		{
			if (cells_[i + 1].isAlive())
			{
				neighbors++;
			}
		}

		//Vertical
		if (y != 0)
		{
			if (cells_[i - width_].isAlive())
			{
				neighbors++;
			}
		}

		if (y != height)
		{
			if (cells_[i + width_].isAlive())
			{
				neighbors++;
			}
		}

		//Diagonal
		if ((x != 0) && (y != 0))
		{
			if (cells_[i - (width_ + 1)].isAlive())
			{
				neighbors++;
			}
		}

		if ((x != width) && (y != height))
		{
			if (cells_[i + (width_ + 1)].isAlive())
			{
				neighbors++;
			}
		}

		if ((x != 0) && (y != height))
		{
			if (cells_[i + (width_ - 1)].isAlive())
			{
				neighbors++;
			}
		}

		if ((x != width) && (y != 0))
		{
			if (cells_[i - (width_ - 1)].isAlive())
			{
				neighbors++;
			}
		}

		return neighbors;
	}

	//CLI Display
	void Grid::display()
	{
		clearScreen();

		char pixel = 254;

		for (int i = 0; i < height_; i++)
		{	
			for (int j = 0; j < width_; j++)
			{
				if (cells_[width_*i + j].isAlive())
					cout << pixel << " ";
				else
					cout << "  ";	
			}

			cout << endl;
		}

	}

	void Grid::clearScreen()
	{
	    system("clear");
    }