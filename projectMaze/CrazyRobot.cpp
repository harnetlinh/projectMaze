#include "CrazyRobot.h"

CrazyRobot::CrazyRobot(Maze* _maze) {
	this->random = new Random();
	this->maze = _maze;
	this->listCoveredPosition.push_back(Cell(0, 0, false));
}
void CrazyRobot::go() {
	bool is_correct = true;
	Cell position = this->getCurrentPosition();
	int x = position.getX();
	int y = position.getY();
	
	do
	{
		int side = this->random->NextInt(0, 3);
		switch (side)
		{
		case 0:
			if (this->maze->positionInMaze((x+1),y) == 0 || this->maze->positionInMaze((x + 1), y) == 1)
			{
				is_correct = false;
				break;
			}
			else {
				this->listCoveredPosition.push_back(Cell((x + 1), y, false));
				is_correct = true;
				break;
			}
			break;
		case 1:
			if (this->maze->positionInMaze(x, (y + 1)) == 0 || this->maze->positionInMaze(x, (y + 1)) == 1)
			{
				is_correct = false;
				break;
			}
			else {
				this->listCoveredPosition.push_back(Cell(x , (y + 1), false));
				is_correct = true;
				break;
			}
			break;
		case 2:
			if (this->maze->positionInMaze((x - 1), y) == 0 || this->maze->positionInMaze((x - 1), y) == 1)
			{
				is_correct = false;
				break;
			}
			else {
				this->listCoveredPosition.push_back(Cell((x - 1), y, false));
				is_correct = true;
				break;
			}
			break;
		case 3:
			if (this->maze->positionInMaze(x , (y - 1)) == 0 || this->maze->positionInMaze(x, (y - 1)) == 1)
			{
				is_correct = false;
				break;
			}
			else {
				this->listCoveredPosition.push_back(Cell(x, (y - 1), false));
				is_correct = true;
			}
			break;
		default:
			break;
		}
	} while (!is_correct);
}



