#include <iostream>
#include <string>
#include <windows.h>
#include "figure.h"
#include "triangle.h"
#include "right_triangle.h"
#include "blalanced_triangle.h"
#include "equil_triangle.h"
#include "Quadrangle.h"
#include "rectangle.h"
#include "square.h"
#include "parale.h"
#include "romb.h"
#include "printFigure.h"



int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	triangle triangle(10, 20, 30, 40, 50, 60);
	printFigure(&triangle);

	right_triangle right_triangle(10, 20, 30, 40, 50);
	printFigure(&right_triangle);

	blalanced_triangle blalanced_triangle(11, 220, 330, 440);
	printFigure(&blalanced_triangle);

	equil_triangle equil_triangle(111);
	printFigure(&equil_triangle);

	Quadrangle Quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
	printFigure(&Quadrangle);

	rectangle rectangle(14, 24);
	printFigure(&rectangle);

	square square(333);
	printFigure(&square);

	parale parale(555, 666, 777, 888);
	printFigure(&parale);

	romb romb(14, 24, 34);
	printFigure(&romb);

}