#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

class Adress {
private:
    std::string town;
    std::string street;
    int building = 0;
    int appart = 0;
    std::string full_adress;

public:
    Adress(std::string town, std::string street, int building, int appart) {
        this->town = town;
        this->street = street;
        this->building = building;
        this->appart = appart;
    };

    std::string create_fulladress() {
        full_adress = town + " , " + street + " , " + std::to_string(building) + " , " + std::to_string(appart);
        return full_adress;
    };
};

//������� �������� ���������� ������������� �������
std::string* creat_arr(int count) {
    std::string* arr = new std::string[count]{};
    return arr;
}


//������� ����������
void sort(std::string* arr, int count) {

    bool swapped = false;
    do {
        swapped = false;
        std::string tmp;

        for (int i = count - 1; i > 0; --i) {
            if (arr[i - 1] > arr[i]) {
                tmp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = tmp;
                swapped = true;
            }
        }
    } 
    while (swapped);
};


//������� ������ ������� � ����
void print_arr(std::string* arr, int count) {
    std::ofstream fileOut("out.txt");

    if (fileOut.is_open()) {
        std::cout << "���� out.txt ������." << std::endl;
    }
    else {
        std::cout << "������ �������� �����" << std::endl;
    }

    fileOut << "����� ���������� �������: " << count << std::endl << std::endl;

    fileOut << "������:" << std::endl;

    for (int i = 0; i < count; ++i) {
        fileOut << arr[i] << std::endl;
    }
    fileOut.close();
};

//������� �������� ������������� �������
void delete_arr(std::string* arr, int count) {
    delete[] arr;
    arr = nullptr;
}





int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::ifstream file("in.txt"); // �������� ���� ��� ������
    std::string infile;

    if (!file) {
        std::cout << "������ �������� ����� in.txt." << std::endl;
    }
    else {
        std::cout << "���� in.txt ������� ������." << std::endl;
    }

    std::string town;
    std::string street;
    int building;
    int appart;

    int count = 0;
    file >> count;
    //count = std::stoi(infile);

    std::string* bd = creat_arr(count);

    for (int i = 0; i < count; ++i) {
        file >> town >> street >> building >> appart;
        Adress adress(town, street, building, appart);
        bd[i] = adress.create_fulladress();
    }

    file.close();
    sort(bd, count);
    print_arr(bd, count);
    delete_arr(bd, count);


}