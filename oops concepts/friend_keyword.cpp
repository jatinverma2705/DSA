#include<iostream>

using namespace std;

class A{
    int x;

public:
    //init list
    A(int _val): x(_val) {};

    int GetX() const{
        return x;
    }

    void SetX(int _x){
        x = _x;
    }

    friend class B; //yha maine class B ko friend bna dia .
    friend void print(const A &);//yha maine ak function ko friend bna dia class A ka.
};

void print(const A&a) {
    cout << a.x << endl;
}

class B{
public:
    void print(const A&a){
        // cout << a.GetX() << endl;
        cout << a.x << endl;
    }
};

int main(){

    A a(5);
    B b;

    b.print(a);
    
    return 0;
}