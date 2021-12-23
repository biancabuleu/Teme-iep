#ifndef SECOND_HPP
#define SECOND_HPP
#include <iostream>
#include "First.hpp"

class Second : First 
{
    private:
    int c;

    public:
    Second();
    ~Second();
    Second(int c):First(a,b),c{c}{}
    Second(const Second &a) ;
    Second operator=(const Second &var);
    void printNumber();
};

#endif