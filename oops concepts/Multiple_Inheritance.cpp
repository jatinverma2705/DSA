#include<iostream>

using namespace std;

class Teacher{
public:
    void teach(){
        cout << "Teaching" << endl;
    }
};

class Researcher{
public: 
    void reasearch(){
        cout << "Researching" << endl;
    }
};

//Multiple Inheritance
//Professor class is inheriting from Teacher & Researcher class 
class Professor:public Teacher,public Researcher{
public:
    void bore(){
        cout << "BOring" << endl;
    }
};


int main(){

    Professor p;
    p.teach();
    return 0;
}