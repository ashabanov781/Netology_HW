#include <iostream>
#include <string>
#include <Windows.h>

struct balance
{
	int account;
	std::string fio;
	long double money;
};

void change_balance(balance* new_symm, long double new_money)
{
	new_symm->money = new_money;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double x = 0;
	int count;
	balance full;
	std::string name;

	std::cout << "¬ведите номер счЄта: ";
	std::cin >> count;
	full.account = count;
	// std::cout << std::endl;

	std::cout << "¬ведите им€ владельца: ";
	std::cin >> name;
	full.fio = name;
	// std::cout << std::endl;

	std::cout << "¬ведите баланс: ";
	std::cin >> x;
	full.money = x;
	std::cout << std::endl;

	// std::cout << "¬аш счЄт: " << full.account << ", " << full.fio << ". " << full.money << std::endl;

	long double new_money = 0;
	std::cout << "¬ведите новый баланс: ";
	std::cin >> new_money;
	std::cout << std::endl;

	change_balance(&full, new_money);

	std::cout << "¬аш счЄт: " << full.account << ", " << full.fio << ", " << full.money;

}