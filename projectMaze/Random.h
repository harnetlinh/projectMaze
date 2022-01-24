#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Random
{
public:
    Random();
    int NextInt(int min, int max);
private:
    int min;
    int max;
};

