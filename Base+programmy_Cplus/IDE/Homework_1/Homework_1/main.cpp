#include <iostream>
#include <string>
#include <fstream>


int main() {
	// Считали файл и создали массивы
	std::ifstream file("in.txt");
	std::string sym;

	if (!file.is_open()) {
		std::cout << "Ошибка открытия файла!";
		return 1;
	}

	file >> sym;
	int length = 0;
	length = std::stoi(sym);
	int* array = new int[length];

	int elem = 0;
	int x = 0;
	for (int i = 0; i < length; ++i) {
		file >> sym;
		elem = std::stoi(sym);
		array[i] = elem;
	}

		x = array[0];

		for (int i = 1; i < length; ++i) {
			array[i - 1] = array[i];
		}
		array[length - 1] = x;
	

	file >> sym;
	int length2 = 0;
	length2 = std::stoi(sym);
	int* array2 = new int[length2];

	int elem2 = 0;
	int x2 = 0;
	for (int i = 0; i < length2; ++i) {
		file >> sym;
		elem2 = std::stoi(sym);
		array2[i] = elem2;
	}
	// вывели второй
	for (int i = 0; i < length2; ++i) {

		std::cout << array2[i] << " ";

	}

		x2 = array2[0];

		for (int i = 1; i < length; ++i) {
			array2[i - 1] = array2[i];
		}
		array2[length2 - 1] = x2;
	

	// вывели первый 
	for (int i = 0; i < length; ++i) {

			std::cout << array[i] << " ";

	}
	// вывели второй
	for (int i = 0; i < length2; ++i) {

		std::cout << array2[i] << " ";

	}



	file.close();

	// Создаем файл и записываем в него  
	std::ofstream exfile("out.txt");
	exfile << length2 << std::endl;
	for (int i = 0; i < length2; ++i) {
		exfile << array2[i] << " ";
	}

	exfile << std::endl;
	exfile << length << std::endl;
	for (int i = 0; i < length; ++i) {
		exfile << array[i] << " ";
	}

	

	delete[] array;
	delete[] array2;


	exfile.close();
	return 1;
}

