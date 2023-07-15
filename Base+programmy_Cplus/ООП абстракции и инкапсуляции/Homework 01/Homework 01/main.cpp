#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

class adress {
private:
    std::string town;
    std::string street;
    int building;
    int appart;
    std::string full_adress;

public:
    adress(std::string town, std::string street, int building, int appart) {
        this->town = town;
        this->street = street;
        this->building = building;
        this->appart = appart;
    }

    std::string create_fulladress() {
        full_adress = town + " , " + street + " , " + std::to_string(building) + " , " + std::to_string(appart);
        return full_adress;
    }
};

//Функция создания текстового динамического массива
std::string* creat_arr(int count) {
    std::string* arr = new std::string[count]{};
    return arr;
}

//Функция удаления динамического массива
void delete_arr(std::string* arr, int count) {
    delete[] arr;
    arr = nullptr;
}

//Функция печати массива в файл
void print_arr(std::string* arr, int count) {
    std::ofstream fileOut("out.txt");

    if (fileOut.is_open()) {
        std::cout << "Файл out.txt открыт." << std::endl;
    }
    else {
        std::cout << "Ошибка открытия файла" << std::endl;
         }

    fileOut << "Всего количество адресов: " << count << std::endl << std::endl;

    fileOut << "Адреса:" << std::endl;

    for (int i = count - 1; i >= 0; i--) {
        fileOut << count - i << ". " << arr[i] << std::endl;
    }
    fileOut.close();
};







int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::ifstream file("in.txt"); // окрываем файл для чтения
    std::string infile;

    if (!file) {
        std::cout << "Ошибка открытия файла in.txt." << std::endl;
    }
    else {
        std::cout << "Файл in.txt успешно открыт." << std::endl;
    }

    std::string town;
    std::string street;
    int building;
    int appart;

    int count = 0;
    file >> infile;
    count = std::stoi(infile);

    std::string* bd = creat_arr(count);

    for (int i = 0; i < count; ++i) {
        file >> town >> street >> building >> appart;
        adress adress(town, street, building, appart);
        bd[i] = adress.create_fulladress();
    }

    file.close();
    print_arr(bd, count);
    delete_arr(bd, count);


}