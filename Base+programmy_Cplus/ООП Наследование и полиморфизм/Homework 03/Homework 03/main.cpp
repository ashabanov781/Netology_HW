#include <iostream>
#include <string>
#include <windows.h>

class figure {
protected:
    int side_count;
    int ang_count;
    bool check_meth = false;
    int sides = 0;
    int side_a = 0;
    int side_b = 0;
    int side_c = 0;
    int side_d = 0;
    int ang_a = 0;
    int ang_b = 0;
    int ang_c = 0;
    int ang_d = 0;

    figure(int sides, std::string name) {
        this->sides = sides;
        this->name = name;
    }

    virtual bool check() {
        if (sides == 0) {
            return true;
        }
        else {
            return false;
        }
    };

public:
    std::string name;

    figure() : figure(0, "Фигура") {};
    // int size_not_4 () {return size_4; }

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

    virtual void print_figure() {
        std::cout << std::endl;
        std::cout << name << ":" << std::endl;
        if (check()) {
            std::cout << "Правильная" << std::endl;
        }
        else {
            std::cout << "Неправильная" << std::endl;
        }
        std::cout << "Количество сторон: " << sides << std::endl;
    }


};

class triangle : public figure {
protected:
    bool check() override {
        if ((ang_a + ang_b + ang_c) == 180) {
            return true;
        }
        else {
            return false;
        }
    };


public:
    triangle(int side_a, int side_b, int side_c, int ang_a, int ang_b, int ang_c) {
        name = "Треугольник";
        this->side_a = side_a;
        this->side_b = side_b;
        this->side_c = side_c;
        this->ang_a = ang_a;
        this->ang_b = ang_b;
        this->ang_c = ang_c;
        this->check_meth = check();
    }

    void print_figure() override {
        figure::print_figure();

        std::cout << "Стороны:";
        std::cout << " a = " << get_side_a() << ", b = " << get_side_b() << ", с = " << get_side_c();
        std::cout << std::endl;

        std::cout << "Углы:";
        std::cout << " А = " << get_ang_a() << ", В = " << get_ang_b() << ", С = " << get_ang_c();
        std::cout << std::endl;
    }

};



class right_triangle : public triangle {
protected:
    bool check() override {
        if (triangle::check() && (ang_c == 90)) {
            return true;
        }
        else {
            return false;
        }
    };

public:
    right_triangle(int side_a, int side_b, int side_c, int ang_a, int ang_b, int ang_c) : triangle(side_a, side_b, side_c, ang_a, ang_b, ang_c) {
        triangle::name = "Прямоугольный треугольник";
    };

};


class blalanced_triangle : public triangle {
protected:
    bool check() override {
        if (triangle::check() && (side_a == side_c && ang_a == ang_c)) {
            return true;
        }
        else {
            return false;
        }
    };

public:
    blalanced_triangle(int side_a, int side_b, int side_c, int ang_a, int ang_b, int ang_c) : triangle(side_a, side_b, side_c, ang_a, ang_b, ang_c) {
        triangle::name = "Равнобедренный треугольник";
    };
};


class equil_triangle : public triangle {
private:
    bool check_equil() {
        if ((side_a == side_b && side_b == side_c) && ((ang_a == 60) && (ang_b = 60) && (ang_c = 60))) {
            return true;
        }
        else {
            return false;
        }
    };

protected:
    bool check() override {
        if (triangle::check() && (check_equil())) {
            return true;
        }
        else {
            return false;
        }
    };


public:
    equil_triangle(int side_a, int side_b, int side_c, int ang_a, int ang_b, int ang_c) : triangle(side_a, side_b, side_c, ang_a, ang_b, ang_c) {
        triangle::name = "Равносторонний треугольник";
    };
};



class quadrangle : public figure {

protected:
    virtual bool check_4() {
        if ((ang_a + ang_b + ang_c + ang_d) == 360) {
            return true;
        }
        else {
            return false;
        }
    };

    bool check_4_AC_BD() {
        if (side_a == side_c && side_b == side_d) {
            return true;
        }
        else {
            return false;
        }
    };

    bool check_4_ABCD() {
        if (side_a == side_b && side_b == side_c && side_c == side_d) {
            return true;
        }
        else {
            return false;
        }
    };

    bool check_ang_90() {
        if (ang_a == 90 && ang_b == 90 && ang_c == 90 && ang_d == 90) {
            return true;
        }
        else {
            return false;
        }
    };

    bool check_ang_AC_BD() {
        if (ang_a == ang_c && ang_b == ang_d) {
            return true;
        }
        else {
            return false;
        }
    };


public:
    quadrangle(int side_a, int side_b, int side_c, int side_d, int ang_a, int ang_b, int ang_c, int ang_d) {
        name = "Четырехугольник";
        this->side_a = side_a;
        this->side_b = side_b;
        this->side_c = side_c;
        this->side_d = side_d;

        this->ang_a = ang_a;
        this->ang_b = ang_b;
        this->ang_c = ang_c;
        this->ang_d = ang_d;
    }

    void print_figure() override
    {
        figure::print_figure();

        std::cout << "Стороны:";
        std::cout << " a = " << get_side_a() << ", b = " << get_side_b() << ", с = " << get_side_c();
        std::cout << ", d = " << get_side_d() << std::endl;

        std::cout << "Углы:";
        std::cout << " А = " << get_ang_a() << ", В = " << get_ang_b() << ", С = " << get_ang_c();
        std::cout << ", D = " << get_ang_d() << std::endl;
    };
};





class rectangle : public quadrangle {
protected:
    bool check() override {
        if (quadrangle::check() && quadrangle::check_4_AC_BD() && quadrangle::check_ang_90()) {
            return true;
        }
        else {
            return false;
        }
    };

public:
    rectangle(int side_a, int side_b, int side_c, int side_d, int ang_a, int ang_b, int ang_c, int ang_d) : quadrangle(side_a, side_b, side_c, side_d, ang_a, ang_b, ang_c, ang_d) {
        quadrangle::name = "Прямоугольник";
    }
};


class square : public quadrangle {
protected:
    bool check() override {
        if (quadrangle::check() && quadrangle::check_4_ABCD() && quadrangle::check_ang_90()) {
            return true;
        }
        else {
            return false;
        }
    };

public:
    square(int side_a, int side_b, int side_c, int side_d, int ang_a, int ang_b, int ang_c, int ang_d) : quadrangle(side_a, side_b, side_c, side_d, ang_a, ang_b, ang_c, ang_d) {
        quadrangle::name = "Квадрат";
    }
};


class parale : public quadrangle {
protected:
    bool check() override {
        if (quadrangle::check() && quadrangle::check_4_AC_BD() && quadrangle::check_ang_AC_BD()) {
            return true;
        }
        else {
            return false;
        }
    };


public:
    parale(int side_a, int side_b, int side_c, int side_d, int ang_a, int ang_b, int ang_c, int ang_d) : quadrangle(side_a, side_b, side_c, side_d, ang_a, ang_b, ang_c, ang_d) {
        quadrangle::name = "Параллелограмм";
    }
};

class romb : public quadrangle {
protected:
    bool check() override {
        if (quadrangle::check() && quadrangle::check_4_ABCD() && quadrangle::check_ang_AC_BD()) {
            return true;
        }
        else {
            return false;
        }
    };

public:
    romb(int side_a, int side_b, int side_c, int side_d, int ang_a, int ang_b, int ang_c, int ang_d) : quadrangle(side_a, side_b, side_c, side_d, ang_a, ang_b, ang_c, ang_d) {
        quadrangle::name = "Ромб";
    }
};


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    figure fig;
    fig.print_figure();

    triangle tri_1(10, 20, 30, 50, 60, 70);
    tri_1.print_figure();

    right_triangle tri_2(10, 20, 30, 50, 60, 90);
    tri_2.print_figure();

    blalanced_triangle tri_3(10, 20, 10, 50, 60, 50);
    tri_3.print_figure();

    equil_triangle tri_4(30, 30, 30, 60, 60, 60);
    tri_4.print_figure();

    quadrangle quad_1(10, 20, 30, 40, 50, 60, 70, 80);
    quad_1.print_figure();

    rectangle quad_2(10, 20, 10, 20, 90, 90, 90, 90);
    quad_2.print_figure();

    square quad_3(20, 20, 20, 20, 90, 90, 90, 90);
    quad_3.print_figure();

    parale quad_4(20, 30, 20, 30, 30, 40, 30, 40);
    quad_4.print_figure();

    romb quad_5(30, 30, 30, 30, 30, 40, 30, 40);
    quad_5.print_figure();

}