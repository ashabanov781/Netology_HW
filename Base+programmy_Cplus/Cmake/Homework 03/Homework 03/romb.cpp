#include "romb.h"

romb::romb(int side_a, int ang_a, int ang_b) : Quadrangle(side_a, side_a, side_a, side_a, ang_a, ang_b, ang_a, ang_b) {
	Quadrangle::name = "Ромб";
}