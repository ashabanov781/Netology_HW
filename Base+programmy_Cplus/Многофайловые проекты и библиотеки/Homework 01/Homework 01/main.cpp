#include <iostream>
#include <string>
#include <windows.h>
#include "func.h"


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int x, y;
    int choice;
    bool check = false;
    std::string operation;

    std::cout << "Введите первое число: ";
    std::cin >> x;
    std::cout << std::endl;
    std::cout << "Введите второе число: ";
    std::cin >> y;
    std::cout << std::endl;

    do {
        std::cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
        std::cin >> choice;
        std::cout << std::endl;

        if (choice == 4 && choice == 0)
        {
            std::cout << "Ошибка! " << std::endl;
        }
        else if (choice <= 5 && choice >= 1)
        {
            check = true;
        }
        else
        {
            std::cout << "Такого варианта не существует. " << std::endl;
        }
    } while (!check);

    switch (choice)
    {
    case(1):
    {
        operation = "плюс";
        break;
    }
    case(2):
    {
        operation = "минус";
        break;
    }
    case(3):
    {
        operation = "умножить";
        break;
    }
    case(4):
    {
        operation = "разделить";
        break;
    }
    case(5):
    {
        operation = "в степени";
        break;
    }
    };

    std::cout << x << " " << operation << " " << y << " = ";

    if (choice == 1)
    {
        std::cout << addition(x, y);
    }
    else if (choice == 2)
    {
        std::cout << subtraction(x, y);
    }
    else if (choice == 3)
    {
        std::cout << multiplication(x, y);
    }
    else if (choice == 4)
    {
        std::cout << division(x, y);
    }
    else
    {
        std::cout << exponentiation(x, y);
    };
}