#include "VerySmartRobot.h"

VerySmartRobot::VerySmartRobot(Maze* _maze) {
	this->maze = _maze;
	this->scoreTree = new ScoreTree(_maze);
	this->listCoveredPosition.push_back(Cell(0, 0, false));
}

void VerySmartRobot::go() {
	Cell position = this->getCurrentPosition();
	int x = position.getX();
	int y = position.getY();
	cout << " ------------------------ START --------------------------" << endl;
	cout << "getCurrentPosition x = " << x << " | y =" << y << endl;
	int chosenDirection = this->chooseDirection(x, y);
	switch (chosenDirection)
	{
	case 0:
		x = (x + 1);
		break;
	case 1:
		y = (y + 1);
		break;
	case 2:
		x = (x - 1);
		break;
	case 3:
		y = (y - 1);
		break;
	default:
		break;
	}
	cout << " ------------ RESULT x = " << x << " | y = " << y << " RESULT -------------" << endl;
	this->scoreTree->setPositionCross(x, y);
	this->listCoveredPosition.push_back(Cell(x, y, false));
	cout << " ------------------------ END --------------------------" << endl;
}

double VerySmartRobot::pointOfDirection(int x, int y) {
	cout << "-----------BEFORE--------------";
	cout << "-------- x = " << x << " |----- y =" << y << "----------" << endl;
	return this->scoreTree->getEvaluateDirection(this->listCoveredPosition[this->listCoveredPosition.size() - 1], x, y);
}

int VerySmartRobot::chooseDirection(int x, int y) {

	double directionPoints[] = { 0, 0, 0, 0 };
	if (this->maze->positionInMaze((x + 1), y) == 0 || this->maze->positionInMaze((x + 1), y) == 1)
	{
		directionPoints[0] = -10;
	}
	else if (this->maze->positionInMaze((x + 1), y) == 4)
	{
		directionPoints[0] = 20;
	}
	else {
		
		directionPoints[0] = this->pointOfDirection(x + 1, y);

	}

	if (this->maze->positionInMaze(x, (y + 1)) == 0 || this->maze->positionInMaze(x, (y + 1)) == 1)
	{
		directionPoints[1] = -10;
	}
	else if (this->maze->positionInMaze(x, (y + 1)) == 4)
	{
		directionPoints[1] = 20;
	}
	else {
		directionPoints[1] = this->pointOfDirection(x, y + 1);

	}

	if (this->maze->positionInMaze((x - 1), y) == 0 || this->maze->positionInMaze((x - 1), y) == 1)
	{
		directionPoints[2] = -10;
	}
	else if (this->maze->positionInMaze((x - 1), y) == 4)
	{
		directionPoints[2] = 20;
	}
	else {
		directionPoints[2] = this->pointOfDirection(x - 1, y);

	}

	if (this->maze->positionInMaze(x, (y - 1)) == 0 || this->maze->positionInMaze(x, (y - 1)) == 1)
	{
		directionPoints[3] = -10;
	}
	else if (this->maze->positionInMaze(x, (y - 1)) == 4)
	{
		directionPoints[3] = 20;
	}
	else {
		directionPoints[3] = this->pointOfDirection(x, y - 1);

	}
	//for (int i = 0; i < sizeof(directionPoints); i++)
	//{
	//	cout << directionPoints[i] << " ";
	//}
	cout << endl;
	int chosenDirection = this->getMaxPointDirection(directionPoints);
	return chosenDirection;
}

int VerySmartRobot::getMaxPointDirection(double arr[]) {
	int indexToReturn = 0;
	int indexValue = 0;
	int newValue = 0;
	for (int i = 0; i < sizeof(arr); i++) {
		newValue = arr[i];
		if (newValue >= indexValue) {
			indexToReturn = i;
			indexValue = newValue;
		}
	}
	return indexToReturn;
}
