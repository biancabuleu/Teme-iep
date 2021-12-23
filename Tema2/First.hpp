#ifndef FIRST_HPP
#define FIRST_HPP
#include <iostream>

class First 
{
    protected:
    int a;
    int b;

    public:
    First();
    ~First();
    First(int a, int b):a{a},b{b}{}
    First(const First& var);
    First operator=(const First &var);
    void showNumbers();

};

#endif