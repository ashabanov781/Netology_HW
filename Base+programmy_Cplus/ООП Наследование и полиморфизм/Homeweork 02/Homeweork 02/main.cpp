#include <iostream>
#include <string>
#include <windows.h>

class figure {
private:


protected:
	bool size_4 = false;
	int sides;
	int side_a;
	int side_b;
	int side_c;
	int side_d;
	int ang_a;
	int ang_b;
	int ang_c;
	int ang_d;
	figure(int sides, std::string name) {
		this->sides = sides;
		this->name = name;
	}

public:
	std::string name;

	figure() : figure(0, "������") {};
	int size_not_4() { return size_4; }

	int get_sides_count() {
		return sides;
	}

	std::string get_name() {
		return name;
	}

	int get_side_a() { return side_a; }
	int get_side_b() { return side_b; }
	int get_side_c() { return side_c; }
	int get_side_d() { return side_d; }

	int get_ang_a() { return ang_a; }
	int get_ang_b() { return ang_b; }
	int get_ang_c() { return ang_c; }
	int get_ang_d() { return ang_d; }


};

class triangle : public figure {

public:
	triangle(int side_a, int side_b, int side_c, int ang_a, int ang_b, int ang_c) {
		name = "�����������";
		this->side_a = side_a;
		this->side_b = side_b;
		this->side_c = side_c;
		this->ang_a = ang_a;
		this->ang_b = ang_b;
		this->ang_c = ang_c;
	}

};

class right_triangle : public triangle {
public:
	right_triangle(int side_a, int side_b, int side_c, int ang_a, int ang_b, int ang_c) : triangle(side_a, side_b, side_c, ang_a, ang_b, ang_c) {
		triangle::name = "������������� �����������";
	};

};


class blalanced_triangle : public triangle {
public:
	blalanced_triangle(int side_a, int side_b, int side_c, int ang_a, int ang_b, int ang_c) : triangle(side_a, side_b, side_c, ang_a, ang_b, ang_c) {
		triangle::name = "�������������� �����������";
	};
};

class equil_triangle : public triangle
{
public:
	equil_triangle(int side_a, int side_b, int side_c, int ang_a, int ang_b, int ang_c) : triangle(side_a, side_b, side_c, ang_a, ang_b, ang_c) {
		triangle::name = "�������������� �����������";
	};
};



class quadrangle : public figure {

public:
	quadrangle(int side_a, int side_b, int side_c, int side_d, int ang_a, int ang_b, int ang_c, int ang_d) {
		size_4 = true;
		name = "���������������";
		this->side_a = side_a;
		this->side_b = side_b;
		this->side_c = side_c;
		this->side_d = side_d;

		this->ang_a = ang_a;
		this->ang_b = ang_b;
		this->ang_c = ang_c;
		this->ang_d = ang_d;
	}
};


class rectangle : public quadrangle
{
public:
	rectangle(int side_a, int side_b, int side_c, int side_d, int ang_a, int ang_b, int ang_c, int ang_d) : quadrangle(side_a, side_b, side_c, side_d, ang_a, ang_b, ang_c, ang_d) {
		quadrangle::name = "�������������";
	}
};

class square : public quadrangle
{
public:
	square(int side_a, int side_b, int side_c, int side_d, int ang_a, int ang_b, int ang_c, int ang_d) : quadrangle(side_a, side_b, side_c, side_d, ang_a, ang_b, ang_c, ang_d) {
		quadrangle::name = "�������";
	}
};

class parale : public quadrangle
{
public:
	parale(int side_a, int side_b, int side_c, int side_d, int ang_a, int ang_b, int ang_c, int ang_d) : quadrangle(side_a, side_b, side_c, side_d, ang_a, ang_b, ang_c, ang_d) {
		quadrangle::name = "��������������";
	}
};

class romb : public quadrangle
{
public:
	romb(int side_a, int side_b, int side_c, int side_d, int ang_a, int ang_b, int ang_c, int ang_d) : quadrangle(side_a, side_b, side_c, side_d, ang_a, ang_b, ang_c, ang_d) {
		quadrangle::name = "����";
	}
};

//������ � �������
void printFigure(figure& figure) {
	std::cout << std::endl;
	std::cout << figure.get_name() << ":" << std::endl;

	std::cout << "�������:";
	std::cout << " a = " << figure.get_side_a() << ", b = " << figure.get_side_b() << ", � = " << figure.get_side_c();

	if (figure.size_not_4())
	{
		std::cout << ", d = " << figure.get_side_d() << std::endl;
	}
	else { std::cout << std::endl; }

	std::cout << "����:";
	std::cout << " � = " << figure.get_ang_a() << ", � = " << figure.get_ang_b() << ", � = " << figure.get_ang_c();
	if (figure.size_not_4()) {
		std::cout << ", D = " << figure.get_ang_d() << std::endl;
	}
	else { std::cout << std::endl; }
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	triangle tri_1(10, 20, 30, 50, 60, 70);
	printFigure(tri_1);

	right_triangle tri_2(10, 20, 30, 50, 60, 90);
	printFigure(tri_2);

	blalanced_triangle tri_3(10, 20, 10, 50, 60, 50);
	printFigure(tri_3);

	equil_triangle tri_4(30, 30, 30, 60, 60, 60);
	printFigure(tri_4);

	quadrangle quad_1(10, 20, 30, 40, 50, 60, 70, 80);
	printFigure(quad_1);

	rectangle quad_2(10, 20, 10, 20, 90, 90, 90, 90);
	printFigure(quad_2);

	square quad_3(20, 20, 20, 20, 90, 90, 90, 90);
	printFigure(quad_3);

	parale quad_4(20, 30, 20, 30, 30, 40, 30, 40);
	printFigure(quad_4);

	romb quad_5(30, 30, 30, 30, 30, 40, 30, 40);
	printFigure(quad_5);

}