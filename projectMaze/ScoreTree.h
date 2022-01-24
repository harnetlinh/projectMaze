#pragma once
#include "Maze.h"
#include "Cell.h"
#include <map>
class ScoreTree
{
public:
	ScoreTree();
	ScoreTree(Maze* _maze);
	~ScoreTree();
	double getEvaluateDirection(Cell _cur_pos, int x, int y);
	void setPositionCross(int x, int y);
private:
	bool checkExisted(vector<int> e, vector<vector<int>> v);
	double getCrossPoint(int x, int y);
	vector<vector<int>> getLv2Positions(int cur_x, int cur_y, int x, int y);
	vector<vector<int>> getevaluationPoints(vector<vector<int>> lv2_positions, int cur_x, int cur_y, int dir_x, int dir_y);
	int positionToPoint(int x, int y);
	map<int, int> numberCrossAPosition;
	Maze* maze;
	vector<vector<int>> evaluation_positions = {};
};

