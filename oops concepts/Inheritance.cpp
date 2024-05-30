#include<iostream>

using namespace std;

class Bird{

public:
    int age;
    string color;
    int nol;
    int weight;

    void fly(){
        cout << "Bird is flying" << endl;
    }

    void eat(){
        cout << "Bird is eating" << endl;
    }
   

};

class Sparrow: public Bird{

public:

    Sparrow(int age,string color,int nol,int weight){
        this->age = age;
        this->color = color;
        this->nol = nol;
        this->weight = weight;

        cout << "parameterized ctor called" << endl;       
    }

    void grassing(){
        cout << "Sparrow is grassing ." << endl;
    }

};

class Pigeon: public Bird{

public:

   Pigeon(int age,string color,int nol,int weight){
        this->age = age;
        this->color = color;
        this->nol = nol;
        this->weight = weight;

        cout << "parameterized ctor called" << endl;       
    }

    void guttering(){
        cout << "Pigeon is guttering." << endl;
    }

};

int main() {
    //Bird(Parent class) -> Sparrow,Pigeon(Child class)

    Sparrow s(1,"Brown",2,5);
    cout << s.color << endl;
    s.eat();
    s.fly();
   
   Pigeon p(2,"Grey",2,2);
   cout << p.color << endl; 

    return 0;
}