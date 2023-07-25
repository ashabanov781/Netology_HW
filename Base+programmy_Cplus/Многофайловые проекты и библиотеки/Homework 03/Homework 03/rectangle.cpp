#include "rectangle.h"

rectangle::rectangle(int side_a, int side_b) : Quadrangle(side_a, side_b, side_a, side_b, 90, 90, 90, 90) {
	Quadrangle::name = "Прямоугольник";
}