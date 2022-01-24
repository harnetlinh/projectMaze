#pragma once
#include "Robot.h"

class JumpingRobot : public Robot
{
public:
	JumpingRobot(Maze* _randomMaze);
	void go();
};

