#pragma once
#include <map>
#include "Robot.h"
#include "ScoreTree.h"

class VerySmartRobot : public Robot
{
public:
	VerySmartRobot(Maze* _maze);
	void go();

private:
	double pointOfDirection(int x, int y);
	int chooseDirection(int x, int y);
	ScoreTree* scoreTree;
	int getMaxPointDirection(double arr[]);
};

