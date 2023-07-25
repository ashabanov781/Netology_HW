#include "right_triangle.h"
#include "triangle.h"

right_triangle::right_triangle(int side_a, int side_b, int side_c, int ang_a, int ang_b) : triangle(side_a, side_b, side_c, ang_a, ang_b, 90)
{
	triangle::name = "Прямоугольный треугольник";
};