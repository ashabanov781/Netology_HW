#include <iostream>
#include <string>
#include <windows.h>

class Figure
{
protected:
	std::string name;

public:
	std::string get_name() { return name; }
	virtual void metod() {
		std::cout << name;
	}
};


class Triangle : public Figure {

protected:
	int side_a = 0;
	int side_b = 0;
	int side_c = 0;
	int ang_a = 0;
	int ang_b = 0;
	int ang_c = 0;


public:
	Triangle(int side_a, int side_b, int side_c, int ang_a, int ang_b, int ang_c) {
		name = "Треугольник";
	}
		double get_a() { return side_a; }
		double get_b() { return side_b; }
		double get_c() { return side_c; }

		double get_A() { return ang_a; }
		double get_B() { return ang_b; }
		double get_C() { return ang_c; }
	

		void metod() override {
			std::cout << name << ":" << std::endl;
			std::cout << "Стороны: ";
			std::cout << "a=" << get_a() << ", b=" << get_b() << ", c=" << get_c() << std::endl;
			std::cout << "Углы: ";
			std::cout << "A=" << get_A() << ", B=" << get_B() << ", C=" << get_C() << std::endl;
			std::cout << std::endl;
		}
	
};

class right_triangle : public Triangle  { //прямоугольный треугольник
public:
	right_triangle(int side_a, int side_b, int side_c, int ang_a, int ang_b) : Triangle(side_a, side_b, side_c, ang_a, ang_b, 90) {
		Triangle::name = "Прямоугольный треугольник";
	};

};


class blalanced_triangle : public Triangle { //Равнобедренный треугольник
public:
	blalanced_triangle(int side_a, int side_b, int ang_a, int ang_b) : Triangle(side_a, side_b, side_a, ang_a, ang_b, ang_a) {
		Triangle::name = "Равнобедренный треугольник";
	};
};

class equil_triangle : public Triangle { //Равносторонний треугольник
public:
	equil_triangle(int side_a) : Triangle(side_a, side_a, side_a, 60, 60, 60) {
		Triangle::name = "Равносторонний треугольник";
	};
};



class Quadrangle : public Figure {

protected:
	int side_a = 0;
	int side_b = 0;
	int side_c = 0;
	int side_d = 0;
	int ang_a = 0;
	int ang_b = 0;
	int ang_c = 0;
	int ang_d = 0;

public:
	Quadrangle(int side_a, int side_b, int side_c, int side_d, int ang_a, int ang_b, int ang_c, int ang_d) {
		name = "Четырехугольник";
	}
	double get_a() { return side_a; }
	double get_b() { return side_b; }
	double get_c() { return side_c; }
	double get_d() { return side_d; }

	double get_A() { return ang_a; }
	double get_B() { return ang_b; }
	double get_C() { return ang_c; }
	double get_D() { return ang_d; }
	
	void metod() override {
		std::cout << name << ":" << std::endl;
		std::cout << "Стороны: ";
		std::cout << "a=" << get_a() << ", b=" << get_b() << ", c=" << get_c() << ", d=" << get_d() << std::endl;
		std::cout << "Углы: ";
		std::cout << "A=" << get_A() << ", B=" << get_B() << ", C=" << get_C() << ", D=" << get_D() << std::endl;
		std::cout << std::endl;
	}
};


class rectangle : public Quadrangle //Прямоугольник
{
public:
	rectangle(int side_a, int side_b) : Quadrangle(side_a, side_b, side_a, side_b, 90, 90, 90, 90) {
		Quadrangle::name = "Прямоугольник";
	}
};

class square : public Quadrangle //Квадрат
{
public:
	square(int side_a) : Quadrangle(side_a, side_a, side_a, side_a, 90, 90, 90, 90) {
		Quadrangle::name = "Квадрат";
	}
};

class parale : public Quadrangle //Параллелограмм
{
public:
	parale(int side_a, int side_b, int ang_a, int ang_b) : Quadrangle(side_a, side_b, side_a, side_b, ang_a, ang_b, ang_a, ang_b) {
		Quadrangle::name = "Параллелограмм";
	}
};

class romb : public Quadrangle //Ромб
{
public:
	romb(int side_a, int ang_a, int ang_b) : Quadrangle(side_a, side_a, side_a, side_a, ang_a, ang_b, ang_a, ang_b) {
		Quadrangle::name = "Ромб";
	}
};





int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Triangle triangle(10, 20, 30, 50, 60, 70);
	Figure* f_triangle = &triangle;
	f_triangle->metod();

	right_triangle right_triangle(10, 20, 30, 50, 60);
	Figure* f_r_triangle = &right_triangle;
	f_r_triangle->metod();

	blalanced_triangle blalanced_triangle(10, 20, 50, 60);
	Figure* f_i_triangle = &blalanced_triangle;
	f_i_triangle->metod();

	equil_triangle equil_triangle(30);
	Figure* f_e_triangle = &equil_triangle;
	f_e_triangle->metod();

	Quadrangle Quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
	Figure* f_quadrangle = &Quadrangle;
	f_quadrangle->metod();

	rectangle rectangle(10, 20);
	Figure* f_rectangle = &rectangle;
	f_rectangle->metod();

	square square(20);
	Figure* f_square = &square;
	f_square->metod();

	parale parale(20, 30, 30, 40);
	Figure* f_parallelogram = &parale;
	f_parallelogram->metod();

	romb romb(30, 30, 40);
	Figure* f_rhomb = &romb;
	f_rhomb->metod();

}