#include "Cell.h"
#include <iostream>

Cell::Cell() : x(0), y(0), isWall(0) {

}
Cell::Cell(int _x, int _y, bool _isWall) : x(_x), y(_y), isWall(_isWall) {
}
Cell::~Cell()
{
}
int Cell::getX() const
{

		return this->x;

}
int Cell::getY() const
{

		return this->y;

}

bool Cell::getCheckIsWall() const
{
	return this->isWall;
}


void Cell::display()
{
	std::cout << "x = " << this->x << " y = " << this->y << std::endl;
}