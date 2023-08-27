#include <iostream>
#include <Windows.h>

class Fraction
{
private:
	int numerator_;
	int denominator_;
	double ant_x;
public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	double get_answer() {
		return ant_x;
	}


	Fraction operator+(Fraction other) {
		int num = 0, den = 0;

		if (denominator_ == other.denominator_) {
			num = (numerator_ + other.numerator_);
			den = denominator_;
		}
		else {
			num = (numerator_ * other.denominator_) + (denominator_ * other.numerator_);
			den = (denominator_ * other.denominator_);
		}
		return Fraction(num, den);
	}

	Fraction operator-(Fraction other) {
		int num = 0, den = 0;
		if (denominator_ == other.denominator_) {
			num = (numerator_ - other.numerator_);
			den = denominator_;
		}
		else {
			num = (numerator_ * other.denominator_) - (denominator_ * other.numerator_);
			den = (denominator_ * other.denominator_);
		}
		return Fraction(num, den);
	}


	Fraction operator*(Fraction other) {
		int num = 0, den = 0;
		num = (numerator_ * other.numerator_);
		den = (denominator_ * other.denominator_);

		return Fraction(num, den);
	}


	Fraction operator/(Fraction other) {
		int num = 0, den = 0;
		num = (numerator_ * other.denominator_);
		den = (denominator_ * other.numerator_);

		return Fraction(num, den);
	}

	Fraction& operator++() {
		numerator_++;
		denominator_++;
		return (*this);
	}

	Fraction operator++(int) {
		Fraction z = *this;
		++(*this);

		return z;
	}

	Fraction& operator--() {
		numerator_--;
		denominator_--;
		return (*this);
	}

	Fraction operator--(int) {
		Fraction z = *this;
		--(*this);

		return z;
	}

	Fraction& operator-() {
		numerator_ += 5;
		denominator_ += 7;
		return (*this);
	}


	void get_print() {
		for (;;) {
			if (((numerator_ % 2) == 0) && ((denominator_ % 2) == 0)) {
				numerator_ /= 2;
				denominator_ /= 2;
			}
			else if (((numerator_ % 3) == 0) && ((denominator_ % 3) == 0)) {
				numerator_ /= 3;
				denominator_ /= 3;
			}
			else if (((numerator_ % 3) == 0) && ((denominator_ % 3) == 0)) {
				numerator_ /= 3;
				denominator_ /= 3;
			}

			else if (((numerator_ % 5) == 0) && ((denominator_ % 5) == 0)) {
				numerator_ /= 5;
				denominator_ /= 5;
			}
			else if (((numerator_ % 7) == 0) && ((denominator_ % 7) == 0)) {
				numerator_ /= 7;
				denominator_ /= 7;
			}

			else {
				std::cout << numerator_ << "/" << denominator_ << "\n";
				break;
			}
		}
	}
};


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
   
	int x1 = 0, x2 = 0, x3 = 0, x4 = 0;

	std::cout << "Введите числитель дроби 1: ";
	std::cin >> x1;

	std::cout << "\nВведите знаминатель дроби 2: ";
	std::cin >> x2;

	std::cout << "\nВведите числитель дроби 3: ";
	std::cin >> x3;

	std::cout << "\nВведите знаминатель дроби 4: ";
	std::cin >> x4;



	Fraction f1(x1, x2);
	Fraction f2(x3, x4);

	Fraction sum_f1_f2 = (f1 + f2);//42 слайд
	std::cout << x1 << "/" << x2 << " + " << x3 << "/" << x4 << " = ";
	sum_f1_f2.get_print();

	Fraction minus_f1_f2 = (f1 - f2);
	std::cout << x1 << "/" << x2 << " - " << x3 << "/" << x4 << " = ";
	minus_f1_f2.get_print();

	Fraction proiz_f1_f2 = (f1 * f2);
	std::cout << x1 << "/" << x2 << " * " << x3 << "/" << x4 << " = ";
	proiz_f1_f2.get_print();

	Fraction dell_f1_f2 = (f1 / f2);
	std::cout << x1 << "/" << x2 << " / " << x3 << "/" << x4 << " = ";
	dell_f1_f2.get_print();






	std::cout << "\n\nбазовое f1 = ";
	f1.get_print();
	Fraction f00 = (f1++);
	std::cout << " f00 выполнится и увеличится на 1/1 = ";
	f00.get_print();

	std::cout << "\nбазовое f1 = ";
	f1.get_print();
	Fraction f01 = (++f1);
	std::cout << " f01 сначала увеличится на 1/1 и выполнится = ";
	f01.get_print();

	std::cout << "\nбазовое f1 = ";
	f1.get_print();
	Fraction f02 = (f1--);
	std::cout << " f02 выполнится и уменьшится на 1/1 = ";
	f02.get_print();

	std::cout << "\nбазовое f1 = ";
	f1.get_print();
	Fraction f03 = (--f1);
	std::cout << " f03 сначала уменьшится на 1/1 и выполнится = ";
	f03.get_print();

	std::cout << "\nбазовое f1 = ";
	f1.get_print();
	Fraction f04 = (-f1);
	std::cout << " f04 увелисится на 5/7 = ";
	f04.get_print();

	std::cout << "\nбазовое f1 = ";
	f1.get_print();


	return 0;
}
