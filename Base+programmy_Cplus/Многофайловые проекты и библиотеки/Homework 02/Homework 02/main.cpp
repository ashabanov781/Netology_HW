#include <iostream>
#include <string>
#include <windows.h>
#include "counter.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice;
    bool check = false;
    std::string operation;


    do
    {
        std::cout << std::endl << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
        std::cin >> operation;
        std::cout << std::endl;

        if (operation == "да" || operation == "Да")
        {
            std::cout << "Введите начальное значение счётчика: ";
            std::cin >> choice;
            check = true;
        }
        else if (operation == "нет" || operation == "Нет")
        {
            check = true;
        }
        else
        {
            std::cout << "Вы ввели неверную команду.";
        }
    } while (!check);

    Counter Counter(choice);
    std::string value;
    bool check_2 = false;

    do
    {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> value;

        if (value == "x")
        {
            std::cout << "Выход! ";
            check_2 = true;
        }
        else if (value == "+")
        {
            Counter.counter_plus();
        }
        else if (value == "-")
        {
            Counter.counter_minus();
        }
        else if (value == "=")
        {
            std::cout << "Значение счетчика: " << Counter.get_counter() << "." << std::endl;
        }
        else
        {
            std::cout << "Неправильная команда! " << std::endl;
        }
    } while (!check_2);
}