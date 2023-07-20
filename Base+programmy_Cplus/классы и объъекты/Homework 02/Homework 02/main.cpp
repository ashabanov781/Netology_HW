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


    int plus(int count) {
        this->count = count;
        return ++count;
    };

    int minus(int count) {
        this->count = count;
        return --count;
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
    int count = 0;

    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::cin >> choose;

    if (choose == "да") {
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> count;
        }
    if ((choose == "нет")) {
        count = 1;
    }
    while (x == 1) {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> action;
        Counter act(count);
        if (action == "+") {
            count = act.plus(count);
        }
        if (action == "-") {
           count = act.minus(count);
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
