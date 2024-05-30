#include<iostream>

using namespace std;

class Person{  
public:
    void walk(){
        cout << "Walking..." << endl;
    }
};

class Teacher: virtual public Person{
public:
    void teach(){
        cout << "Teaching" << endl;
    }
};

class Researcher: virtual public Person{
public: 
    void reasearch(){
        cout << "Researching" << endl;
    }
};

//Multiple Inheritance
class Professor:public Teacher,public Researcher{
public:
    void bore(){
        cout << "BOring" << endl;
    }
};


int main(){

    Professor p;
    
    //DIAMOND problem

    //Solution 1. Scope resolution
    //Explicitly assign the scope of the class
    // p.Teacher::walk();
    // p.Researcher::walk();

    //Solution 2. use of virtual->means virtually inherit karenge person vali class se.
    p.walk();
    return 0;
}