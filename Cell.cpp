#include "Cell.h"
//#include "ccc_shap.h"

using namespace std;

//------------------------------------------
//---------Constructors---------------------
//------------------------------------------

	Cell::Cell(void) { }

	Cell::Cell(int x, int y)
	{
		x_ = x;
		y_ = y;

		alive_ = false;
	}

	Cell::Cell(int x, int y, bool alive)
	{
		x_ = x;
		y_ = y;

		alive_ = alive;
	}

//------------------------------------------
//---------Destructor-----------------------
//------------------------------------------

	Cell::~Cell(void) { }

//------------------------------------------
//---------Inspectors-----------------------
//------------------------------------------

	int Cell::getX() const
	{
		return x_;
	}

	int Cell::getY() const
	{
		return y_;
	}

	bool Cell::isAlive() const
	{
		return alive_;
	}

	int Cell::getNeighbors() const
	{
		return neighbors_;
	}

//------------------------------------------
//---------Mutators-------------------------
//------------------------------------------
	void Cell::setNeighbors(int neighbors)
	{
		neighbors_ = neighbors;
	}

	void Cell::setAlive(bool alive)
	{
		alive_ = alive;
	}

//------------------------------------------
//---------Facilitators---------------------
//------------------------------------------

	/*Point Cell::toPoint() const
	{
		double x = getX() + 0.5;
		double y = getY() + 0.5;

		Point p(x, y);
		return p;
	}*/