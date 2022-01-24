#pragma once
#include "Robot.h"

class CrazyRobot : public Robot
{
public:
	CrazyRobot(Maze* _randomMaze);
	
	void go();

	
private:
	
	
	//int getDirection() {
	//	this->listCoveredPosition[this->listCoveredPosition.size() - 1];

	//}
};

