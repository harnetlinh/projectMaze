#include "Random.h"

Random::Random()
{
    this->min = 0;
    this->max = 0;
    srand(time(NULL));
}
int Random::NextInt(int min, int max)
{
    // Get a random number - formula
    int num = min + rand() % (max - min + 1);
    return num;
}
