#include "equil_triangle.h"
#include "triangle.h"

equil_triangle::equil_triangle(int side_a) : triangle(side_a, side_a, side_a, 60, 60, 60)
{
	triangle::name = "Равносторонний треугольник";
};