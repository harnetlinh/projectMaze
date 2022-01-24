#pragma once
#include "Cell.h";
#include "Random.h"
#include <vector>;


class Maze
{
public:
	Maze();
	Maze(int _numberOfWall, int _width, int _length, int _maxLengthOfWall);
	int positionInMaze(int x, int y);
	bool isEntrance(int x, int y);
	bool isExit(int x, int y);
	void display();
	void display(Cell robot);
	virtual void generateWalls() = 0;

protected:
	void convertToMaze();
	int height;
	int width;


	Cell* entrance;
	Cell* exit;
	vector<vector<bool>> tempMaze;
	vector<vector<Cell>> randomMaze;
};