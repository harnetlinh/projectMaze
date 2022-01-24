#include "SmartRobot.h"

SmartRobot::SmartRobot(Maze* _maze) {
	this->random = new Random();
	this->maze = _maze;
	this->listCoveredPosition.push_back(Cell(0, 0, false));
}
void SmartRobot::go() {
	Cell position = this->getCurrentPosition();
	int x = position.getX();
	int y = position.getY();
	//cout << " ---------------------------------------- " << endl;
	//cout << " Current position x =" << x << " | y =" << y << endl;
	int chosenDirection = this->chooseDirection(x, y);
	//cout << " chosenDirection = " << chosenDirection << endl;
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
	//cout << " decision x = " << x << " | y =" << y << endl;
	if (this->numberCrossAPosition.find(x * 100 + y) == this->numberCrossAPosition.end() )
	{
		this->numberCrossAPosition[x * 100 + y] = 1;
	}
	else {
		this->numberCrossAPosition[x * 100 + y]++;
	}
	this->listCoveredPosition.push_back(Cell(x , y, false));
	//cout << " ---------------------------------------- " << endl;
}

int SmartRobot::chooseDirection(int x, int y) {
	
	double directionPoints[] = { 0, 0, 0, 0 };
	if (this->maze->positionInMaze((x + 1), y) == 0 || this->maze->positionInMaze((x + 1), y) == 1)
	{
		directionPoints[0] = -10;
		//cout << " 0 = -1" << endl;
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
		//cout << " 1 = -1" << endl;
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
		//cout << " 2 = -1" << endl;
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
		//cout << " 3 = -1" << endl;
	}
	else if (this->maze->positionInMaze(x, (y - 1)) == 4)
	{
		directionPoints[3] = 20;
	}
	else {
		directionPoints[3] = this->pointOfDirection(x, y - 1);

	}
	//for (int i = 0; i < 4; i++)
	//{
	//	cout << "directionPoints["<< i <<"] = " << directionPoints[i] << " | ";
	//}
	//cout << endl;
	int chosenDirection = this->getMaxPointDirection(directionPoints);
	return chosenDirection;
}

int SmartRobot::getMaxPointDirection(double arr[]) {
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

double SmartRobot::pointOfDirection(int x, int y) {
	//int total = 0;
	//Cell position = this->getCurrentPosition();
	//int curr_x = position.getX();
	//int curr_y = position.getY();
	double p1 = 0, p2 = 0, p3 = 0, p4 = 0;
	//if ((x + 1) != curr_x && (y) != curr_y)
	//{
		p1 = this->convertPoint(x + 1, y);
	//}
	//if ((x - 1) != curr_x && (y) != curr_y)
	//{
		p2 = this->convertPoint(x - 1, y);
	//}
	//if ((x) != curr_x && (y + 1) != curr_y)
	//{
		p3 = this->convertPoint(x, y + 1);
	//}
	//if ((x - 1) != curr_x && (y - 1) != curr_y)
	//{
		p4 = this->convertPoint(x, y - 1);
	//}
		double repeat_p = 1.5;
	if (!(this->numberCrossAPosition.find(x * 100 + y) == this->numberCrossAPosition.end()))
	{
		repeat_p = repeat_p - (this->numberCrossAPosition[x * 100 + y] * 0.25);
	}

	return p1 + p2 + p3 + p4 + repeat_p;
}

int SmartRobot::convertPoint(int x, int y) {
	int p = this->maze->positionInMaze(x, y);
	switch (p)
	{
	case 0:
		return 0;
	case 1:
		return 0;
	case 4:
		return 10;
	case 3:
		return 1;
	case 2:
		return 1;
	default:
		break;
	}
}