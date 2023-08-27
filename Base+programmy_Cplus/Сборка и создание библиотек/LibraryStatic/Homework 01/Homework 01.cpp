#include "StaticLib.h"
#include <iostream>
#include <Windows.h>
#include <string>





int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);

    std::string name, z1;
    std::cout << "Введите имя: ";

    std::cin >> name;

    lib::Greeter z10;
    z1 = z10.ret_name(name);

    std::cout << z1;



}