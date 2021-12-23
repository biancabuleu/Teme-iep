#include <iostream>
#include <memory>
#include <string>
using std::cout;
using std::endl;
class Motor
{
    int putere;
    bool isLocked=false;
    public:
    Motor(int putere)
    {
        this->putere=putere;
    }
   void setBlocat(bool setter)
   {
       this->isLocked = setter;
   }
   void merge()
   {
       if(this->isLocked == false)
       cout<<"nu e blocat!"<<endl;
       else
       cout<<"este blocat"<<endl;
   }
   Motor(const Motor &m)
    {
        this->putere = m.putere;
        this->isLocked = m.isLocked;
    }

};

void lockMotor(Motor &m)
{
    cout<<"locked resource"<<endl;
    m.setBlocat(true);
}
void unlockMotor(Motor &m)
{
    cout<<"unlocked resource"<<endl;
    m.setBlocat(false);
} 

class Masina
{
    int numar;
    std::string marca;
    Motor &motor;
    public:
    Masina(int numar, std::string marca, Motor &m): motor(m)
    {
        this->numar=numar;
        this->marca=marca;
        lockMotor(motor);
    }
    void createCar()
    {
        cout<<"create new car"<<numar<<" "<<marca<<endl;
    }

    Masina(const Masina &m): motor(m.motor)
    {
        this->numar = m.numar;
        this->marca = m.marca;
    }
    ~Masina()
    {
        unlockMotor(motor);
        cout<<"Destructor"<<endl;
    }

};

  
int main()
{
    //asa nu
    // Masina *newCar = new Masina();//raw pointer

    // delete newCar;
    Motor m1(2000);
    Motor m2(5000);
    {std::unique_ptr<Masina> newCar1(new Masina(99, "volvo", m1));//varianta mai noua a lui auto
    newCar1->createCar();

    m1.merge();

    std::unique_ptr<Masina> newCar2;
    newCar2=move(newCar1);

    newCar2->createCar();
    //newCar1->createCar();
    }
    m1.merge();
    
    std::shared_ptr<Masina> newCar3(new Masina(100, "audi", m2));//varianta mai noua a lui auto
    newCar3->createCar();

    cout<<newCar3.use_count()<<endl;
    std::shared_ptr<Masina> newCar4(newCar3);
    cout<<newCar3.use_count()<<endl;
    newCar4->createCar();
    std::shared_ptr<Masina> newCar5;
    newCar5=move(newCar3);
    cout<<newCar3.use_count()<<endl;
    cout<<newCar5.use_count()<<endl;
}