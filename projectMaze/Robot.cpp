#include "Robot.h"

Robot::Robot() {

}

Robot::Robot(Maze* _randomMaze) {

}
Robot::~Robot() {

}
Cell Robot::getCurrentPosition() {
	return this->listCoveredPosition[this->listCoveredPosition.size() - 1];
}
void Robot::display() {
	this->maze->display(this->getCurrentPosition());
}