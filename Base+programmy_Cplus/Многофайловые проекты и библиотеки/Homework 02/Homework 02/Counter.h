#pragma once


class Counter
{
private:
    int res = 0;

public:
    Counter(int int_value);
    int get_counter();
    int counter_plus();
    int counter_minus();
};
