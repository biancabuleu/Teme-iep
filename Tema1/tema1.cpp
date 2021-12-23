#include <iostream>
using namespace std;
class Uncopyable{
    protected:
    Uncopyable(){
        cout<<"Object created";
    }
    ~Uncopyable(){
        cout<<"Object Destroyed";
    }
    private:
    Uncopyable(const Uncopyable& var);
    Uncopyable& operator=(const Uncopyable& var); // prevent copying
};
class Me: private Uncopyable{

};

class Hello{
    public:
        // Hello(){} -- default constructor
        // Hello(const Hello& var){...} -- copy constructor
        // ~Hello(){...} -- destructor
        // Hello& operator=(const Hello& var){...} -- copy assignment operator 
};


class SumOfTwo{
    int a;
    int b;

public:
    SumOfTwo(int a, int b)
        :a{a}, b{b} {

    }

    void print() {
            cout<< "Sum of the two numbers is " <<a+b;
    }
};

int main() {

// ---------------ITEM4---------------
    SumOfTwo sum1(3,5);

//----------------ITEM5---------------
 
    Hello h1; // default constructor;          
    Hello h2(h1); // copy constructor
    h2=h1; //copy assignment operator
    // destructor
    // destructor

//----------------ITEM6---------------
    Me m1;
    //Me m2(m1); -- error
    //m2=m1;     -- error

}