#include <iostream>
#include "numEnterClass.h"


int numEnterClass::numEnter(int numX, int count)
{
    std::cout << "������� ����� " << count << ": ";
    std::cin >> numX;

    return numX;
}