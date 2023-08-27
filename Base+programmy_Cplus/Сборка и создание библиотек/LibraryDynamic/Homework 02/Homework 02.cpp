#include <iostream>
#include <Windows.h>
#include <string>
#include "DynamicLib.h"



int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);

    std::string name, z1;
    std::cout << "Введите имя: ";

    std::cin >> name;

    lib_dynamic::Leaver z10;
    z1 = z10.leave(name);

    std::cout << z1;

    system("pause");

}
