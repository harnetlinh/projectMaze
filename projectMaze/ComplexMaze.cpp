#include "ComplexMaze.h"

ComplexMaze::ComplexMaze() {

}
ComplexMaze::ComplexMaze(int _width, int _height) {

    this->width = _width;
    this->height = _height;
    
    this->entrance = new Cell(0, 0, false);

	for (int h = 0; h < this->height; h++)
	{
		this->tempMaze.push_back(std::vector<bool>());
		for (int w = 0; w < this->width; w++)
		{
			this->tempMaze[h].push_back(true);
		}
	}

	this->visitedPositions.push_back({0 , 0});
	this->stackPositions.push_back({0 , 0});
	this->generateStack();
	this->generateWalls();
}

void ComplexMaze::generateWalls() {
	for (int i = 0; i < this->visitedPositions.size(); i++)
	{
		this->tempMaze[this->visitedPositions[i][px]][this->visitedPositions[i][py]] = false;
	}
	for (int i = this->height - 1; i > 0 ; i--)
	{
		if (!this->tempMaze[this->width - 1][i])
		{
			this->exit = new Cell(i,this->width - 1, false);
			break;
		}
	}
	if (this->exit == nullptr || this->exit == NULL)
	{
		this->exit = new Cell(this->height - 1, this->width - 1, false);
	}
    this->convertToMaze();
}

void ComplexMaze::generateStack() {
	int dir;
	int count = 0;
	do
	{
		count++;
		//cout << "------------------start-----------" << endl;
		dir = this->getDirection();
		//cout << " DIR = " << dir << endl;
		switch (dir)
		{
		case -1:
			this->backOneStep();
			break;
		case 0:
			this->goForward(-1, 0);
			break;
		case 1:
			this->goForward(1, 0);
			break;
		case 2:
			this->goForward(0, -1);
			break;
		case 3:
			this->goForward(0, 1);
			break;
		default:
			break;
		}
		//cout << "------------------end-----------" << endl;
	} while (!this->isCompleted() && count < this->width * this->height);
}

void ComplexMaze::goForward(int dir_x, int dir_y) {
	vector<int> new_position = { this->stackPositions[this->stackPositions.size() - 1][px] + dir_x, this->stackPositions[this->stackPositions.size() - 1][py] + dir_y };
	this->visitedPositions.push_back(new_position);
	this->stackPositions.push_back(new_position);
}

bool ComplexMaze::isVisited(vector<int> p) {
	for (int i = 0; i < this->visitedPositions.size(); i++)
	{
		if (p[px] == this->visitedPositions[i][px] && p[py] == this->visitedPositions[i][py])
		{
			return true;
		}
	}
	return false;
}

void ComplexMaze::backOneStep() {
	if (this->stackPositions.size() > 2)
	{
		this->stackPositions.pop_back();
	}
	
}

bool ComplexMaze::isCompleted() {
	double scale = this->visitedPositions.size() / (this->width * this->height);
	if (scale > 0.45 && scale < 0.55)
	{
		return true;
	}
	else {
		return false;
	}
}

bool ComplexMaze::checkExisted(int e, vector<int> v) {
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == e)
		{
			return true;
		}
	}
	return false;
}

int ComplexMaze::getDirection() {
	vector<int> cur_position = this->stackPositions[this->stackPositions.size() - 1];
	//cout << " cur_position  x = " << cur_position[px] << " y = " << cur_position[py] << endl;
	vector<int> posible_dir;
	if (cur_position[py] % 2 == 0)
	{
		if (cur_position[px] > 0)
		{
			vector<int> new_position = { cur_position[px] - 1, cur_position[py]};
			if (!this->isVisited(new_position))
			{
				posible_dir.push_back(0);
			}
		}
		if (cur_position[px] < (this->height - 1))
		{
			vector<int> new_position = { cur_position[px] + 1, cur_position[py]};
			if (!this->isVisited(new_position))
			{
				posible_dir.push_back(1);
			}
		}
	}
	if (cur_position[px] % 2 == 0)
	{
		if (cur_position[py] > 0)
		{
			vector<int> new_position = { cur_position[px], cur_position[py] - 1 };
			if (!this->isVisited(new_position))
			{
				posible_dir.push_back(2);
			}
		}
		if (cur_position[py] < (this->width - 1))
		{
			vector<int> new_position = { cur_position[px], cur_position[py] + 1 };
			if (!this->isVisited(new_position))
			{
				posible_dir.push_back(3);
			}
		}
	}
	//for (int i = 0; i < posible_dir.size(); i++)
	//{
	//	cout << "posible_dir = " << posible_dir[i] << endl;
	//}
	if (posible_dir.size() <= 0)
	{
		return -1;
	}
	else {
		int choosen = this->random->NextInt(0, (posible_dir.size() - 1));
		
		return posible_dir[choosen];
	}
}



