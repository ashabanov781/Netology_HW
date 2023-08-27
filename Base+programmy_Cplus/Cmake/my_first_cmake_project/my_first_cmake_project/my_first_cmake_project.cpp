#include <iostream>
#include <Windows.h>
#include <string>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string name;
    std::cout << "Введите имя: ";
    std::cin >> name;
    std::cout << "\nЗдравствуйте, " << name << "!\n";

    system("pause");
    
}
