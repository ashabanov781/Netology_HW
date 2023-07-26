#include <iostream>
#include <string>
#include <exception>
#include <Windows.h>

int function(std::string word, int forbiddenLength)
{
    if (forbiddenLength == word.length())
    {
        throw std::length_error("�� ����� ����� ��������� �����! �� ��������");
    };

    return static_cast<int>(word.length());
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int length = 0;
    int forbiddenLength = 0;
    std::string word;
    bool check_length = false;

    do
    {
        std::cout << "������� ��������� �����: ";
        std::cin >> forbiddenLength;

        if (forbiddenLength > 0)
        {
            check_length = true;
        }

        if (forbiddenLength <= 0)
        {
            std::cout << "�������� �����... ������� �����" << std::endl;
        }

    } while (!check_length);

    try
    {
        do
        {
            std::cout << "������� �����: ";
            std::cin >> word;

            length = function(word, forbiddenLength);

            std::cout << "����� ����� \"" << word << "\" ����� " << length << std::endl;

        } while (forbiddenLength != length);
    }
    catch (const std::exception& ex)
    {
        std::cout << std::endl << ex.what() << std::endl;
    }
}