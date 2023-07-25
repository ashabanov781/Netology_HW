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
        std::cout << std::endl << "�� ������ ������� ��������� �������� ��������? ������� �� ��� ���: ";
        std::cin >> operation;
        std::cout << std::endl;

        if (operation == "��" || operation == "��")
        {
            std::cout << "������� ��������� �������� ��������: ";
            std::cin >> choice;
            check = true;
        }
        else if (operation == "���" || operation == "���")
        {
            check = true;
        }
        else
        {
            std::cout << "�� ����� �������� �������.";
        }
    } while (!check);

    Counter Counter(choice);
    std::string value;
    bool check_2 = false;

    do
    {
        std::cout << "������� ������� ('+', '-', '=' ��� 'x'): ";
        std::cin >> value;

        if (value == "x")
        {
            std::cout << "�����! ";
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
            std::cout << "�������� ��������: " << Counter.get_counter() << "." << std::endl;
        }
        else
        {
            std::cout << "������������ �������! " << std::endl;
        }
    } while (!check_2);
}