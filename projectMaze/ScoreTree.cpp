#include "ScoreTree.h"

ScoreTree::ScoreTree(Maze* _maze) {
	this->maze = _maze;
}

double ScoreTree::getEvaluateDirection(Cell _cur_pos, int x, int y) {
	int cur_x = _cur_pos.getX();
	int cur_y = _cur_pos.getY();
	cout << "getEvaluateDirection" << endl;
	cout << " x = " << x << endl;
	cout << " y = " << y << endl;
	vector<vector<int>> lv2_positions = this->getLv2Positions(cur_x, cur_y, x, y);
	cout << "lv2_positions size = " << lv2_positions.size() << endl;
	vector<vector<int>> evaluation_positions = this->getevaluationPoints(lv2_positions, cur_x, cur_y, x, y);
	double total_point = 0;
	cout << "evaluation_positions size = " << evaluation_positions.size() << endl;
	for (int i = 0; i < evaluation_positions.size(); i++)
	{
		cout << "evaluation_positions[i][0] = " << evaluation_positions[i][0] << endl;
		cout << "evaluation_positions[i][1] = " << evaluation_positions[i][1] << endl;
		total_point += this->positionToPoint(evaluation_positions[i][0], evaluation_positions[i][1]) + this->getCrossPoint(evaluation_positions[i][0], evaluation_positions[i][1]);
	}
	cout << "getEvaluateDirection TotalPoint= " <<total_point << endl;
	return total_point;
}

double ScoreTree::getCrossPoint(int x, int y) {
	double repeat_p = 1.5;
	if (!(this->numberCrossAPosition.find(x * 100 + y) == this->numberCrossAPosition.end()))
	{
		repeat_p = repeat_p - (this->numberCrossAPosition[x * 100 + y] * 0.5);
	}
	return repeat_p;
}

void ScoreTree::setPositionCross(int x, int y) {
	if (this->numberCrossAPosition.find(x * 100 + y) == this->numberCrossAPosition.end())
	{
		this->numberCrossAPosition[x * 100 + y] = 1;
	}
	else {
		this->numberCrossAPosition[x * 100 + y]++;
	}
}

bool ScoreTree::checkExisted(vector<int> e, vector<vector<int>> v) {
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i][0] == e[0] && v[i][1] == e[1])
		{
			return true;
		}
	}
	return false;
}

vector<vector<int>> ScoreTree::getevaluationPoints(vector<vector<int>> lv2_positions, int cur_x, int cur_y, int dir_x, int dir_y) {
	vector<vector<int>> evaluation_positions = {};
	for (int i = 0; i < lv2_positions.size(); i++)
	{
		int x = lv2_positions[i][0];
		int y = lv2_positions[i][1];
		cout << " lv2_positions[i][0] = " << lv2_positions[i][0] << endl;
		cout << " lv2_positions[i][1] = " << lv2_positions[i][1] << endl;
		if ((cur_x != (x + 1) && cur_y != y) && (dir_x != (x + 1) && dir_y != y))
		{
			cout << "PASSED x+ 1 - " << this->maze->positionInMaze(x + 1, y) << endl;
			if (this->maze->positionInMaze(x + 1, y) != 0 && this->maze->positionInMaze(x + 1, y) != 1)
			{
				if (!this->checkExisted({x + 1, y}, evaluation_positions))
				{
					evaluation_positions.push_back({ x + 1, y });
				}
			}
		}

		if ((cur_x != (x - 1) && cur_y != y) && (dir_x != (x - 1) && dir_y != y))
		{
			cout << "PASSED x- 1" << endl;
			if (this->maze->positionInMaze(x - 1, y) != 0 && this->maze->positionInMaze(x - 1, y) != 1)
			{
				if (!this->checkExisted({ x - 1, y }, evaluation_positions))
				{
					evaluation_positions.push_back({ x - 1, y });
				}
			}
		}

		if ((cur_x != x && cur_y != (y + 1)) && (dir_x != x && dir_y != (y + 1)))
		{
			cout << "PASSED y + 1" << endl;
			if (this->maze->positionInMaze(x, y + 1) != 0 && this->maze->positionInMaze(x, y + 1) != 1)
			{
				if (!this->checkExisted({ x, y + 1 }, evaluation_positions))
				{
					evaluation_positions.push_back({ x, y + 1});
				}
			}
		}

		if ((cur_x != x && cur_y != (y - 1)) && (dir_x != x && dir_y != (y - 1)))
		{
			cout << "PASSED y- 1" << endl;
			if (this->maze->positionInMaze(x, y - 1) != 0 && this->maze->positionInMaze(x, y - 1) != 1)
			{
				if (!this->checkExisted({ x, y - 1 }, evaluation_positions))
				{
					evaluation_positions.push_back({ x, y - 1 });
				}
			}
		}

	}
	return evaluation_positions;
}

vector<vector<int>> ScoreTree::getLv2Positions(int cur_x, int cur_y, int x, int y) {
	vector<vector<int>> lv2_positions = {};
	cout << "getLv2Positions(int cur_x, int cur_y, int x, int y)  x =" << x << " | y =" << y << " | cur_x = "<< cur_x << " cur_y = "<< cur_y << endl;
	if (!(cur_x == (x + 1) && cur_y == y))
	{
		cout << "cur_x != (x + 1) && cur_y != y | " << x + 1 <<" "<< y<< "-----" << this->maze->positionInMaze(x + 1, y) << endl;
		if (this->maze->positionInMaze(x + 1, y) != 0 && this->maze->positionInMaze(x + 1, y) != 1)
		{
			cout << " OK LUON!!!!!!!!!!!!!!!!";
			lv2_positions.push_back({ x + 1, y });
		}
	}

	if (!(cur_x != (x - 1) && cur_y != y))
	{
		cout << "cur_x != (x - 1) && cur_y != y" << endl;
		if (this->maze->positionInMaze(x - 1, y) != 0 && this->maze->positionInMaze(x - 1, y) != 1)
		{
			lv2_positions.push_back({ x - 1, y });
		}
	}

	if (!(cur_x != x  && cur_y != (y + 1)))
	{
		cout << "cur_x != x  && cur_y != (y + 1)" << endl;
		if (this->maze->positionInMaze(x, (y + 1)) != 0 && this->maze->positionInMaze(x, (y + 1)) != 1)
		{
			lv2_positions.push_back({ x , (y + 1) });
		}
	}

	if (!(cur_x != x && cur_y != (y - 1)))
	{
		cout << "cur_x != x && cur_y != (y - 1)" << endl;
		if (this->maze->positionInMaze(x, (y - 1)) != 0 && this->maze->positionInMaze(x, (y - 1)) != 1)
		{
			lv2_positions.push_back({ x , (y - 1) });
		}
	}
	return lv2_positions;
}

int ScoreTree::positionToPoint(int x, int y) {
	int p = this->maze->positionInMaze(x, y);
	switch (p)
	{
	case 0:
		return 0;
	case 1:
		return 0;
	case 4:
		return 20;
	case 3:
		return 1;
	case 2:
		return 1;
	default:
		break;
	}
}
