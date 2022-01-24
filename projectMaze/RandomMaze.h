#pragma once
#include "Maze.h"

class RandomMaze :
    public Maze
{
public:
	RandomMaze();
	RandomMaze(int _numberOfWall, int _width, int _length, int _maxLengthOfWall);

	void generateWalls();
	
private:
	void generateTempMaze();
	int currentWallNumber = 0;
	int numberOfWall;
	int maxLengthOfWall;
};

