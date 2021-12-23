#include "Second.hpp"
using std::cout;
using std::endl;

Second::Second(){
    //default constr for second class
    c = 200;
}
    Second::~Second()
    {
        //destr for second class
    }
    Second::Second(const Second &var) : First(var), c(var.c){};
    Second Second::operator=(const Second &var){ //item 12
        //second class copy assignment
        First::operator=(var);
        this->c = var.c;
        return *this;
    }
    void Second::printNumber(){
        cout<<c<<endl;
    }