#pragma once
#include <map>
#include "Robot.h"
class SmartRobot :
    public Robot
{
public:
    SmartRobot();
    SmartRobot(Maze* _maze);
    ~SmartRobot();
    void go();
private :
    int chooseDirection(int x, int y);
    
    double pointOfDirection(int x, int y);
    int convertPoint(int x, int y);
    int getMaxPointDirection(double arr[]);
    map<int, int> numberCrossAPosition;
};

