#include<iostream>

using namespace std;

class Base{
public:
    Base(){
        cout << "Base ctor called" << endl;
    }

    //It is a good practice to make virtual dtor so that you can handle proper destruction of derived classes.
    virtual ~Base(){
        cout << "Base dtor called " << endl;
    }
};

class Derived : public Base{
public:
    Derived(){
        cout << "Derived ctor called" << endl;
    }
    ~Derived(){
        cout << "Derived dtor called" << endl;
    } 
};

int main(){
    Base *b = new Derived();
    delete b;
    return 0;
}