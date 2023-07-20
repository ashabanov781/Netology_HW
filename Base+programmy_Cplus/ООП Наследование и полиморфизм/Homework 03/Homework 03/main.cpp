#include <iostream>
#include <string>
#include <windows.h>

class Figure
{
protected:
	std::string name;
	bool check = false;//Признак правильности фигуры
	int s_sides = 0;//Кол-во сторон фигуры

	virtual bool Check() //метод проверки фигуры.Кол-во сторон == 0 
	{
		if (s_sides == 0) { return true; }
		else { return false; }
	};

public:
	std::string get_name() { return name; }

	virtual void printf() //Метод печати и проверка правильности фигуры
	{
		std::cout << std::endl;
		std::cout << name << ":" << std::endl;
		if (Check()) { 
			std::cout << "Правильная" << std::endl; 
			}
		else { 
			std::cout << "Неправильная" << std::endl; 
			}

		std::cout << "Количество сторон: " << s_sides << std::endl;
	}
};


class Triangle : public Figure {

protected:
	double side_a = 0;
	double side_b = 0;
	double side_c = 0;
	double ang_a = 0;
	double ang_b = 0;
	double ang_c = 0;

	bool Check() override //переопределение метода проверки на сумму углов треуг == 180
	{
		if ((ang_a + ang_b + ang_c) == 180) { 
			return true; 
			}
		else { 
			return false; 
		}
	};


public:
	Triangle(double side_a, double side_b, double side_c, double ang_a, double ang_b, double ang_c):side_a(side_a), side_b(side_b), side_c(side_c), ang_a(ang_a), ang_b(ang_b), ang_c(ang_c)
	{
		name = "Треугольник";
		s_sides = 3; 
		check = Check();
	}
	double get_a() { return side_a; }
	double get_b() { return side_b; }
	double get_c() { return side_c; }

	double get_A() { return ang_a; }
	double get_B() { return ang_b; }
	double get_C() { return ang_c; }


	void printf() override 
	{
			Figure::printf();

			std::cout << "Стороны: " << "a=" << get_a() << ", b=" << get_b() << ", c=" << get_c() << std::endl;
			std::cout << "Углы: " << "A=" << get_A() << ", B=" << get_B() << ", C=" << get_C() << std::endl;
	}

};

class right_triangle : public Triangle { //прямоугольный треугольник
protected:
	bool Check() override
	{
		if (Triangle::Check() && (ang_c == 90)) 
		{ 
			return true; 
		}
		else 
		{ 
			return false; 
		}
	};
public:
	right_triangle(double side_a, double side_b, double side_c, double ang_a, double ang_b, double ang_c) : Triangle(side_a, side_b, side_c, ang_a, ang_b, ang_c)
	{
		Triangle::name = "Прямоугольный треугольник";
	}
};


class blalanced_triangle : public Triangle { //Равнобедренный треугольник
protected:
	bool Check() override
	{
		if (Triangle::Check() && (side_a == side_c && ang_a == ang_c)) 
		{ 
			return true; 
		}
		else 
		{ 
			return false; 
		}
	};
public:
	blalanced_triangle(int side_a, int side_b, int side_c, int ang_a, int ang_b, int ang_c) : Triangle(side_a, side_b, side_c, ang_a, ang_b, ang_c) {
		Triangle::name = "Равнобедренный треугольник";
	};
};

class equil_triangle : public Triangle { //Равносторонний треугольник
private:
	bool CheckEquilTriangle()
	{
		if (side_a == side_b && side_b == side_c && (ang_a == 60) && ang_b == 60 && ang_c == 60) 
		{ 
			return true; 
		}
		else 
		{ 
			return false; 
		}
	};
public:
	equil_triangle(int side_a, int side_b, int side_c, int ang_a, int ang_b, int ang_c) : Triangle(side_a, side_b, side_c, ang_a, ang_b, ang_c) {
		Triangle::name = "Равносторонний треугольник";
	};

protected:
	bool Check() override
	{
		if (Triangle::Check() && (CheckEquilTriangle())) 
		{ 
			return true; 
		}
		else 
		{ 
			return false; 
		}
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


	virtual bool Check() //Виртуальный метод проверки на сумму углов четырехугольника == 360
	{
		if ((ang_a + ang_b + ang_c + ang_d) == 360) 
		{ 
			return true; 
		}
		else 
		{ 
			return false; 
		}
	};

	bool CheckSides1() //Метод проверки, что стороны а,с и в,d попарно равны
	{
		if (side_a == side_c && side_b == side_d) 
		{ 
			return true; 
		}
		else 
		{ 
			return false; 
		}
	};

	bool CheckSides2() //Метод проверки, что все стороны равны
	{
		if (side_a == side_b && side_b == side_c && side_c == side_d) 
		{ 
			return true; 
		}
		else 
		{ 
			return false; 
		}
	};

	bool CheckAngles1() //Метод проверки, что все углы равны 90 гр
	{
		if (ang_a == 90 && ang_b == 90 && ang_c == 90 && ang_d == 90) 
		{ 
			return true; 
		}
		else 
		{ 
			return false; 
		}
	};

	bool CheckAngles2() //Метод проверки, что углы А,С и В,D попарно равны
	{
		if (ang_a == ang_c && ang_b == ang_d)
		{
			return true;
		}
		else
		{
			return false;
		}
	};

public:
	Quadrangle(int side_a, int side_b, int side_c, int side_d, int ang_a, int ang_b, int ang_c, int ang_d):side_a(side_a), side_b(side_b), side_c(side_c), side_d(side_d), ang_a(ang_a), ang_b(ang_b), ang_c(ang_c), ang_d(ang_d)
	{
		name = "Четырехугольник";
		s_sides = 4;
	}
	double get_a() { return side_a; }
	double get_b() { return side_b; }
	double get_c() { return side_c; }
	double get_d() { return side_d; }

	double get_A() { return ang_a; }
	double get_B() { return ang_b; }
	double get_C() { return ang_c; }
	double get_D() { return ang_d; }

	void printf() override //Переопределение метода печати с вызовом базового метода печати
	{
		Figure::printf();

		std::cout << "Стороны: " << "a=" << get_a() << ", b=" << get_b() << ", c=" << get_c() << ", d=" << get_d() << std::endl;
		std::cout << "Углы: " << "A=" << get_A() << ", B=" << get_B() << ", C=" << get_C() << ", D=" << get_D() << std::endl;
	}
};


class rectangle : public Quadrangle //Прямоугольник
{
protected:
	bool Check() override
	{
		if (Quadrangle::Check() && Quadrangle::CheckSides1() && Quadrangle::CheckAngles1())
		{
			return true;
		}
		else
		{
			return false;
		}
	};

public:
	rectangle(int side_a, int side_b, int side_c, int side_d, int ang_a, int ang_b, int ang_c, int ang_d) : Quadrangle(side_a, side_b, side_c, side_d, ang_a, ang_b, ang_c, ang_d) 
	{
		Quadrangle::name = "Прямоугольник";
	}
};

class square : public Quadrangle //Квадрат
{
protected:
	bool Check() override {
		if (Quadrangle::Check() && Quadrangle::CheckSides2() && Quadrangle::CheckAngles1()) { return true; }
		else { return false; }
	};

public:
	square(int side_a, int side_b, int side_c, int side_d, int ang_a, int ang_b, int ang_c, int ang_d) : Quadrangle(side_a, side_b, side_c, side_d, ang_a, ang_b, ang_c, ang_d) 
	{
		Quadrangle::name = "Квадрат";
	}
};

class parale : public Quadrangle //Параллелограмм
{
protected:
	bool Check() override {
		if (Quadrangle::Check() && Quadrangle::CheckSides1() && Quadrangle::CheckAngles2()) { return true; }
		else { return false; }
	};

public:
	parale(int side_a, int side_b, int side_c, int side_d, int ang_a, int ang_b, int ang_c, int ang_d) : Quadrangle(side_a, side_b, side_c, side_d, ang_a, ang_b, ang_c, ang_d)
	{
		Quadrangle::name = "Параллелограмм";
	}
};

class romb : public Quadrangle //Ромб
{
protected:
	bool Check() override {
		if (Quadrangle::Check() && Quadrangle::CheckSides2() && Quadrangle::CheckAngles2()) { return true; }
		else { return false; }
	};

public:
	romb(int side_a, int side_b, int side_c, int side_d, int ang_a, int ang_b, int ang_c, int ang_d) : Quadrangle(side_a, side_b, side_c, side_d, ang_a, ang_b, ang_c, ang_d)
 {
		Quadrangle::name = "Ромб";
	}
};





int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Figure Figure1;
	Figure1.printf();

	Triangle Triangle1(10, 20, 30, 50, 60, 70);
	Figure* f1 = &Triangle1;
	f1->printf();

	right_triangle rightTriangle1(10, 20, 30, 50, 60, 90);
	Figure* f2 = &rightTriangle1;
	f2->printf();

	right_triangle rightTriangle2(10, 20, 30, 50, 40, 90);
	Figure* f3 = &rightTriangle2;
	f3->printf();

	blalanced_triangle isosTriangle1(10, 20, 10, 50, 60, 50);
	Figure* f4 = &isosTriangle1;
	f4->printf();

	blalanced_triangle isosTriangle2(10, 20, 10, 60, 60, 60);
	Figure* f5 = &isosTriangle2;
	f5->printf();

	equil_triangle equilTriangle1(30, 30, 30, 60, 60, 60);
	Figure* f6 = &equilTriangle1;
	f6->printf();

	Quadrangle Quadrangle1(10, 20, 30, 40, 50, 60, 70, 80);
	Figure* f7 = &Quadrangle1;
	f7->printf();

	rectangle rectangle1(10, 20, 10, 20, 90, 90, 90, 90);
	Figure* f8 = &rectangle1;
	f8->printf();

	square square1(20, 20, 20, 20, 90, 90, 90, 90);
	Figure* f9 = &square1;
	f9->printf();

	parale parallelogram1(20, 30, 20, 30, 30, 40, 30, 40);
	Figure* f10 = &parallelogram1;
	f10->printf();

	romb rhomb1(30, 30, 30, 30, 30, 40, 30, 40);
	Figure* f11 = &rhomb1;
	f11->printf();
}