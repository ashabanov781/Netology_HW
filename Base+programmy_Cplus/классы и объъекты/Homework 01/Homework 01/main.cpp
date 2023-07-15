#include <iostream>
#include <windows.h>

class Calculator {
public:
    double num1;
    double num2;

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

    void add() {
        std::cout << "num1 + num2 = " << (num1 + num2) << std::endl;
    };

    void multiply() {
        std::cout << "num1 * num2 = " << (num1 * num2) << std::endl;
    };

    void subtract_1_2() {
        std::cout << "num1 - num2 = " << (num1 - num2) << std::endl;
    };

    void subtract_2_1() {
        std::cout << "num2 - num1 = " << (num2 - num1) << std::endl;
    };

    void divide_1_2() {
        std::cout << "num1 / num2 = " << (num1 / num2) << std::endl;
    };

    void divide_2_1() {
        std::cout << "num2 / num1 = " << (num2 / num1) << std::endl;
    };

};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double num1, num2;


    while (1) {
        std::cout << "Введите num1: ";
        std::cin >> num1;
        // std::cout << std::endl;

        std::cout << "Введите num2: ";
        std::cin >> num2;
        // std::cout << std::endl;

        Calculator calc;
        calc.num1 = num1;
        calc.num2 = num2;

        // calc.set_num1(num1);
        // calc.set_num2(num2);
        if ((calc.set_num1(num1) != 0) && (calc.set_num2(num2) != 0)) {
            calc.add();
            calc.multiply();
            calc.subtract_1_2();
            calc.subtract_2_1();
            calc.divide_1_2();
            calc.divide_2_1();
            std::cout << std::endl;
        }
        else {
            std::cout << "Неверный ввод!" << std::endl;
        };

    };
}