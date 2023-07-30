#include <iostream>
#include <windows.h>

class Calculator {
private:
    double num1 = 1;
    double num2 = 1;

public:
    bool set_num1(double num1) {
        this->num1 = num1;
        if (num1 != 0) {
            return true;
        }
        else {
            return false;
        }
    };

    bool set_num2(double num2) {
        this->num2 = num2;
        if (num2 != 0) {
            return true;
        }
        else {
            return false;
        }
    };

    double add() {
        return num1 + num2;
    };

    double multiply() {
        return num1 * num2;
    };

    double subtract_1_2() {
        return num1 - num2;
    };

    double subtract_2_1() {
        return num2 - num1;
    };

    double divide_1_2() {
        return num1/num2;
    };

    double divide_2_1() {
        return num2/num1;
    };

};

void Print(double result)
{
    std::cout << result << std::endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double num1, num2;
    Calculator calc;

    while (1) {
        do {
            std::cout << "Введите num1: ";
            std::cin >> num1;
            if (!calc.set_num1(num1)) {
                std::cout << "Неверный ввод!" << std::endl;
            }
        } while (!calc.set_num1(num1));
        
        do {
            std::cout << "Введите num2: ";
            std::cin >> num2;
            if (!calc.set_num2(num2)) {
                std::cout << "Неверный ввод!" << std::endl;
            }
        } while (!calc.set_num2(num2));
        

        calc.add();
        std::cout << " num1 + num2 = ";
        Print(calc.add());

        calc.multiply();
        std::cout << " num1 * num2 = ";
        Print(calc.multiply());

        calc.subtract_1_2();
        std::cout << " num1 - num2 = ";
        Print(calc.subtract_1_2());

        calc.subtract_2_1();
        std::cout << " num2 - num1 = ";
        Print(calc.subtract_2_1());

        calc.divide_1_2();
        std::cout << " num1 / num2 = ";
        Print(calc.divide_1_2());

        calc.divide_2_1();
        std::cout << " num2 / num1 = ";
        Print(calc.divide_2_1());


    };
}