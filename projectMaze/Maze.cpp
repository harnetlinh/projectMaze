#include "Maze.h"

Maze::Maze() {

}
Maze::Maze(int _numberOfWall, int _width, int _length, int _maxLengthOfWall) {

}

void Maze::convertToMaze() {
	for (int i = 0; i < this->height; i++)
	{
		this->randomMaze.push_back(std::vector<Cell>());
		for (int j = 0; j < this->width; j++)
		{
			if (this->tempMaze[i][j])
			{
				if (this->isEntrance(i, j) || this->isExit(i, j))
				{
					this->randomMaze[i].push_back(Cell(i, j, false));
				}
				else {
					this->randomMaze[i].push_back(Cell(i, j, true));
				}

			}
			else {
				this->randomMaze[i].push_back(Cell(i, j, false));
			}

		}
	}
}

int Maze::positionInMaze(int x, int y) {

	if (x < 0 || x >= this->height || y < 0 || y >= this->height)
	{
		return 0;
	}
	if (this->randomMaze[x][y].getCheckIsWall() && !this->isExit(x, y) && !this->isEntrance(x, y))
	{
		return 1;
	}
	if (this->isExit(x, y))
	{
		return 4;
	}
	if (this->isEntrance(x, y))
	{
		return 3;
	}
	return 2;
}

bool Maze::isEntrance(int x, int y) {
	return (x == this->entrance->getX() && y == this->entrance->getY());
}

bool Maze::isExit(int x, int y) {
	return (x == this->exit->getX() && y == this->exit->getY());
}

void Maze::display() {
	cout << randomMaze.size() << endl;
	for (int i = 0; i < this->randomMaze.size(); i++)
	{
		for (int j = 0; j < this->randomMaze[i].size(); j++)
		{
			if (this->isEntrance(i, j)) {
				cout << " A ";
			}
			else if (this->isExit(i, j)) {
				cout << " B ";
			}
			else if (this->randomMaze[i][j].getCheckIsWall())
			{
				cout << " # ";
			}
			else {
				cout << " . ";
			}
		}
		cout << endl;
	}
}
void Maze::display(Cell robot) {
	for (int i = 0; i < this->randomMaze.size(); i++)
	{
		for (int j = 0; j < this->randomMaze[i].size(); j++)
		{
			if (robot.getX() == i && robot.getY() == j) {
				cout << " R ";
			}
			else if (this->isEntrance(i, j)) {
				cout << " A ";
			}
			else if (this->isExit(i, j)) {
				cout << " B ";
			}
			else if (this->randomMaze[i][j].getCheckIsWall())
			{
				cout << " # ";
			}
			else {
				cout << " . ";
			}
		}
		cout << endl;
	}
}