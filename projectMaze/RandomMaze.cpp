#include "RandomMaze.h"

RandomMaze::RandomMaze(){

}
RandomMaze::RandomMaze(int _numberOfWall, int _width, int _height, int _maxLengthOfWall) {
	this->height = _height;
	this->numberOfWall = _numberOfWall;
	this->width = _width;
	this->maxLengthOfWall = _maxLengthOfWall;
	this->exit = new Cell(_width - 1, _height - 1, false);
	this->entrance = new Cell(0, 0, false);
	this->generateTempMaze();
	this->generateWalls();
};

void RandomMaze::generateWalls() {
	this->convertToMaze();
}


void RandomMaze::generateTempMaze() {
	int _width = (this->width - 1);
	int _height = (this->height - 1);
	Random* random = new Random();

	for (int h = 0; h < this->height; h++)
	{
		this->tempMaze.push_back(std::vector<bool>());
		for (int w = 0; w < this->width; w++)
		{
			this->tempMaze[h].push_back(false);
		}
	}
	for (int i = 0; i < this->numberOfWall; i++)
	{
		bool is_correct = true;
		do
		{
			int x = random->NextInt(0, _width);
			int y = random->NextInt(0, _height);

			int side = random->NextInt(0,3);
			int wall_length = 0;
			do 
			{
				wall_length = random->NextInt(0, this->maxLengthOfWall);
			} while (wall_length == 0);
			switch (side)
			{
			case 0: // up
				if ((y + wall_length) >= this->height)
				{
					is_correct = false;
					break;
					
				}
				else {
					for (int up = y; up < (y + wall_length); up++)
					{
						this->tempMaze[up][x] = true;
					}
					is_correct = true;
					break;
				}
				break;
			case 1: // right
				if ((x + wall_length) >= this->width)
				{
					is_correct = false;
					break;
				}
				else {
					for (int right = x; right < (x + wall_length); right++)
					{
						this->tempMaze[y][right] = true;
					}
					is_correct = true;
					break;
				}
				break;
			case 2: // down
				if ((y - wall_length) <= 0)
				{
					is_correct = false;
					break;
				}
				else {
					for (int down = y; down > (y - wall_length + 1); down--)
					{
						this->tempMaze[down][x] = true;
					}
					is_correct = true;
					break;
				}
				break;
			case 3: // left
				if ((x - wall_length) <= 0)
				{
					is_correct = false;
					break;
				}
				else {
					for (int left = x; left > (x - wall_length + 1); left--)
					{
						this->tempMaze[y][left] = true;
					}
					is_correct = true;
				}
				break;
			default:
				is_correct = false;
				break;
			}

		} while (!is_correct);
	}

}

