#include <iostream>
#include <string>
#include <windows.h>

class figure {
private:
    int sides;
    std::string name;

protected:
    figure(int sides, std::string name) {
        this->sides = sides;
        this->name = name;
    }

public:
    figure() : figure(0, "Фигура") {};

    int get_sides_count() {
        return sides;
    }

    std::string get_name() {
        return name;
    }


};

class triangle : public figure {
public:
    triangle() : figure(3, "Треугольник") {};

};

class quadrangle : public figure {
public:
    quadrangle() : figure(4, "Квадрат") {};
};

// void print_f ()


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    figure fig;
    triangle trig;
    quadrangle quad;
    std::cout << "Количество сторон: " << std::endl;
    std::cout << fig.get_name() << " " << fig.get_sides_count() << std::endl;
    std::cout << trig.get_name() << " " << trig.get_sides_count() << std::endl;
    std::cout << quad.get_name() << " " << quad.get_sides_count() << std::endl;

}