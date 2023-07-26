#include <iostream>
#include <Windows.h>
#include "numEnterClass.h"
#include "numSumClass.h"

#define MODE 2
#if !defined MODE
#error "��������� � ������������� ���������� MODE"
#endif 

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

#ifdef MODE

#if MODE == 1
    std::cout << std::endl << "�������� � ������ ����������" << std::endl;

#elif MODE == 2
    std::cout << std::endl << "�������� � ������ ������" << std::endl;
    int num1 = 0;
    int num2 = 0;
    int count = 1;
    bool numMode = true;


    num1 = numEnterClass::numEnter(num1, count);
    ++count;
    num2 = numEnterClass::numEnter(num2, count);
    std::cout << std::endl << "��������� ��������: " << numSumClass::numSum(num1, num2) << std::endl;
#else MODE
    std::cout << std::endl << "������������ �����.���������� �������" << std::endl;
#endif 
#endif

#ifndef MODE
    std::cout << std::endl << "�� ������� #error � �� �������� #define MODE." << std::endl;
#endif
}