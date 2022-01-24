#pragma once
#include <vector>
#include <iostream>
#include "Cell.h"
#include "Maze.h"
#include "Random.h"
#include "Robot.h"

using namespace std;
class Robot
{
public:
	Robot();
	Robot(Maze* _randomMaze);
	~Robot();
	void display();
	Cell getCurrentPosition();

	virtual void go() = 0;
protected:
	Random* random;
	Maze* maze;
	vector<Cell> listCoveredPosition;
};

