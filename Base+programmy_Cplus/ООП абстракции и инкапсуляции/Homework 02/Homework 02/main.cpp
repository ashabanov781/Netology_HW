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
    void set_adress(std::string town, std::string street, int building, int appart) {
        this->town = town;
        this->street = street;
        this->building = building;
        this->appart = appart;
    }


    std::string get_town() {
        return town;
    }

    std::string get_street() {
        return street;
    }

    int get_building() {
        return building;
    }

    int get_appart() {
        return appart;
    }

  
    static int converting(std::string x) {
        int x2 = 0;
        x2 = std::stoi(x);
        return x2;
    }


    static void set_convert(Adress& A, Adress& B) {
        std::string c1, c2;
        int c3, c4;
        c1 = B.town;
        c2 = B.street;
        c3 = B.building;
        c4 = B.appart;

        B.town = A.town;
        B.street = A.street;
        B.building = A.building;
        B.appart = A.appart;


        A.town = c1;
        A.street = c2;
        A.building = c3;
        A.appart = c4;

    }

};




int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::ifstream file("in.txt"); 
    if (!file) {
        std::cout << "Fail open file in.txt." << std::endl;
    }
    else {
        std::cout << "File in.txt is opened" << std::endl;
    }

    std::string town;
    std::string street;
    std::string building;
    std::string appart;
    int x = 0;
    int y = 0;

    int count = 0;
    file >> count;


    Adress* bd = new Adress[count];


    for (int i = 0; i < count; ++i) {
        file >> town >> street >> building >> appart;
        x = bd[i].converting(building);
        y = bd[i].converting(appart);
        bd[i].set_adress(town, street, x, y);
    }

    for (int j = 0; j < (count - 1); ++j) {
        for (int i = 0; i < (count - 1); i++) {
            std::string t1 = bd[i].get_town();
            std::string t2 = bd[i + 1].get_town();
            if (t1 > t2) {
                bd[i].set_convert(bd[i], bd[i + 1]);
            }
        }
    }


    std::ofstream offfile("out.txt"); 
    if (offfile.is_open()) {
        std::cout << "Файл out.txt открыт." << std::endl;
    }
    else {
        std::cout << "Ошибка открытия файла" << std::endl;
    }

    offfile << count << "\n";
    for (int i = 0; i < count; i++) {
        offfile << bd[i].get_town() << ", " << bd[i].get_street() << ", " << bd[i].get_building() << ", "
            << bd[i].get_appart() << "\n";
    }

    delete[]bd;
    file.close();
    offfile.close();

    return 0;


}