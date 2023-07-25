#include "square.h"

square::square(int side_a) : Quadrangle(side_a, side_a, side_a, side_a, 90, 90, 90, 90) {
	Quadrangle::name = " вадрат";
}