#include <iostream>
#include <Windows.h>
#include <string>

enum class mounth
{
    None = 0,
    January,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int x;
    do {
        std::cout << "������� ����� ������: ";
        std::cin >> x;
        // std::cout << x << std::endl;


        switch (x)
        {
        case 0:
            std::cout << "�� ��������!" << std::endl;
            break;
        case 1:
            std::cout << "������" << std::endl;
            break;
        case 2:
            std::cout << "�������" << std::endl;
            break;
        case 3:
            std::cout << "����" << std::endl;
            break;
        case 4:
            std::cout << "������" << std::endl;
            break;
        case 5:
            std::cout << "���" << std::endl;
            break;
        case 6:
            std::cout << "����" << std::endl;
            break;
        case 7:
            std::cout << "����" << std::endl;
            break;
        case 8:
            std::cout << "������" << std::endl;
            break;
        case 9:
            std::cout << "��������" << std::endl;
            break;
        case 10:
            std::cout << "�������" << std::endl;
            break;
        case 11:
            std::cout << "������" << std::endl;
            break;
        case 12:
            std::cout << "�������" << std::endl;
            break;

        }
        if (x < 0 || x > 13)
            std::cout << "������������ �����!" << std::endl;

    } while (x > 0 || x < 13);

}