#include "counter.h"


Counter::Counter(int int_value)
{
    res = int_value;
};

int Counter::get_counter()
{
    return res;
};

int Counter::counter_plus() 
{
    return ++res;
};

int Counter::counter_minus()
{
    return --res;
};