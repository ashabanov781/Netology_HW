#include <iostream>
#include <string>
#include <windows.h>


struct bd
{
    std::string city;
    std::string street;
    int home;
    int apartment;
    int zip;
};


void print_str(bd* view_bd, int x)
{

    for (int i = 0; i < x; ++i)
    {
        std::cout << "�����: " << view_bd[i].city << std::endl
            << "�����: " << view_bd[i].street << std::endl
            << "����� ����: " << view_bd[i].home << std::endl
            << "����� ��������: " << view_bd[i].apartment << std::endl
            << "������: " << view_bd[i].zip << std::endl;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
  
    int x = 1;
    bd* bd_array = new bd[10];

    bd_array[0].city = "Piter";
    bd_array[0].street = "������";
    bd_array[0].home = 41;
    bd_array[0].apartment = 19;
    bd_array[0].zip = 119334;

    print_str (bd_array, x);

    // for (int i= 0; i < x; ++i)
    // {
    //   std::cout << "�����: " << bd_array[i].city << std::endl
    //         << "�����: " << bd_array[i].street << std::endl
    //         << "����� ����: " << bd_array[i].home << std::endl
    //         << "����� ��������: " << bd_array[i].apartment << std::endl
    //         << "������: " << bd_array[i].zip << std::endl;
    // }
    std::cout << std::endl;
    delete[] bd_array;
}