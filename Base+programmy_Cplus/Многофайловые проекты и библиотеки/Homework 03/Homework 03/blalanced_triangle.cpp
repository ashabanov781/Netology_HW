#include "blalanced_triangle.h"

blalanced_triangle::blalanced_triangle(int side_a, int side_b, int ang_a, int ang_b) : triangle(side_a, side_b, side_a, ang_a, ang_b, ang_a)
{
	triangle::name = "Равнобедренный треугольник";
};
