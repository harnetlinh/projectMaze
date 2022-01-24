#pragma once
#include <iostream>
using namespace std;
class Cell
{
public:
    // Constructors
    Cell();
    Cell(int _x, int _y, bool _isWall);

    // Destructor
    ~Cell();

    // Getters
    int getX() const;
    int getY() const;
    bool getCheckIsWall() const;

    void display();

protected:

    // Attributes
    const int x;
    const int y;
    const bool isWall;
};
