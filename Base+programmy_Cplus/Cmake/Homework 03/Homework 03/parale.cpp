#include "parale.h"

parale::parale(int side_a, int side_b, int ang_a, int ang_b) : Quadrangle(side_a, side_b, side_a, side_b, ang_a, ang_b, ang_a, ang_b) {
	Quadrangle::name = "Параллелограм";
}