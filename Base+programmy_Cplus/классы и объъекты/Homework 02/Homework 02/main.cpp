#include <iostream>
#include <string>
#include <windows.h>

class Counter {
private:
    int count;

public:
    Counter(int count) {
        this->count = count;
    }

    Counter() {
        this->count = 1;
    }


    void plus(int count) {
        ++count;
    };

    void minus(int count) {
        --count;
    };

    void print(int count) {
        std::cout << count << std::endl;
    };

};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int x = 1;
    std::string choose;
    std::string action;
    int count;

    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::cin >> choose;

    if (choose == "да") {
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> count;
        Counter counter(count);
    }
    if ((choose == "нет")) {
        Counter counter;
    }
    while (x == 1) {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> action;
        Counter act(count);
        if (action == "+") {
            act.plus(count);
        }
        if (action == "-") {
            act.minus(count);
        }
        if (action == "=") {
            act.print(count);
        }
        if (action == "x") {
            x = 0;
            std::cout << "До свидания!";
        }
    }
}
