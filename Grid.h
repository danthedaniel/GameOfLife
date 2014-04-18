#ifndef _GRID_H_
#define _GRID_H_

#include <vector> //For storing all of the cell objects
#include <iostream> //For writing the grid to the console
#include <time.h> //Helps to provide a "random" seed upon each run on randomize()
#include <stdlib.h> //Contains srand and rand

//To read from a user provided file
#include <fstream>
#include <string>

//Project specific class
#include "Cell.h"

using namespace std;

/**
	A grid to contain cells for John Conway's game of Life
*/

class Grid
{
	public:
		//Constructors
		Grid(void);
		Grid(int size);
		Grid(int w, int h);
		Grid(string filename);

		//Destructor
		~Grid(void);

		//Inspectors
		int getWidth() const;
		int getHeight() const;
		vector<Cell> getCells() const;

		//Facilitators
		void randomize(int prob);
		void newGeneration();
		void display();
		void clearScreen();
		void loadFromFile(string filename);

	private:
		void init();
		void init(string filename);
		int neighborCount(int i);

		vector<Cell> cells_;
		int width_;
		int height_;
};

#endif