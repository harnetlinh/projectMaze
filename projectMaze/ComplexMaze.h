#pragma once
#include "Maze.h"

class ComplexMaze:public Maze
{
	
public:
	
	ComplexMaze();
	ComplexMaze(int _width, int _length);
	void generateWalls();
private:
	const int px = 0;
	const int py = 1;
	Random* random = new Random();
	void generateStack();
	void goForward(int dir_x, int dir_y);
	bool isVisited(vector<int> p);
	void backOneStep();
	int getDirection();
	bool checkExisted(int i, vector<int> v);
	bool isCompleted();
	int lastStep = -1;
	vector<vector<int>> visitedPositions;
	vector<vector<int>> stackPositions;
};




