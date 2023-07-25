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

    std::cout << "������� ������ �����: ";
    std::cin >> x;
    std::cout << std::endl;
    std::cout << "������� ������ �����: ";
    std::cin >> y;
    std::cout << std::endl;

    do {
        std::cout << "�������� �������� (1 - ��������, 2 ���������, 3 - ���������, 4 - �������, 5 - ���������� � �������): ";
        std::cin >> choice;
        std::cout << std::endl;

        if (choice == 4 && choice == 0)
        {
            std::cout << "������! " << std::endl;
        }
        else if (choice <= 5 && choice >= 1)
        {
            check = true;
        }
        else
        {
            std::cout << "������ �������� �� ����������. " << std::endl;
        }
    } while (!check);

    switch (choice)
    {
    case(1):
    {
        operation = "����";
        break;
    }
    case(2):
    {
        operation = "�����";
        break;
    }
    case(3):
    {
        operation = "��������";
        break;
    }
    case(4):
    {
        operation = "���������";
        break;
    }
    case(5):
    {
        operation = "� �������";
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