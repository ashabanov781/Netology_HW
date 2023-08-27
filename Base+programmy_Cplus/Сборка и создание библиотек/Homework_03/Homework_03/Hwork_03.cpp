#include <iostream>
#include <Windows.h>
#include <string>
#include "CMake_d_lib.h"


int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);

    std::string name, z1;
    std::cout << "¬ведите им€: ";

    std::cin >> name;

    lib_dynamic::Leaver z10;
    z1 = z10.leave(name);

    std::cout << z1;

    system("pause");
    system("pause");
}