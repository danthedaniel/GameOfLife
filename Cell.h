#ifndef _CELL_H_
#define _CELL_H_

//#include "ccc_shap.h"

using namespace std;

/**
   A cell in John Conway's game of Life
*/

class Cell
{
	public:
		//Constructors
		Cell(void);
		Cell(int x, int y);
		Cell(int x, int y, bool alive);

		//Destructor
		~Cell(void);

		//Inspectors
		int getX() const;
		int getY() const;
		int getNeighbors() const;
		bool isAlive() const;

		//Mutators
		void setNeighbors(int neighbors);
		void setAlive(bool alive);

		//Facilitators
		//Point toPoint() const;

	private:
		int x_;
		int y_;
		int neighbors_;

		bool alive_;
};

#endif