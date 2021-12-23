#include "First.hpp"
using std::cout;
using std::endl;

    First::First ()
    {
        cout<<"Default constr for First class";
    }
    First::~First()
    {
        //default constr for first class
    }
// First First::operator=(const First &var) // item 10
//    {
//        this->a = var.a;
//        this->b = var.b;

//        return *this;
//    }

     First::First(const First &var){
        this->a = var.a;
        this->b = var.b;
    }

   First First::operator=(const First &var) // item 11
   {
       First temporary(var);
       this->a = temporary.a;
       this->b = temporary.b;

       return *this;
   }   // p1 deja generat
   //p0 = p1; delete p1

   void First::showNumbers(){
       cout<<a<<" "<<b<<endl;
   }