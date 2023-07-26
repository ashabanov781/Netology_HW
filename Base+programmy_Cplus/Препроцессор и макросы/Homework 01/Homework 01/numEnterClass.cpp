#include <iostream>
#include "numEnterClass.h"


int numEnterClass::numEnter(int numX, int count)
{
    std::cout << "¬ведите число " << count << ": ";
    std::cin >> numX;

    return numX;
}