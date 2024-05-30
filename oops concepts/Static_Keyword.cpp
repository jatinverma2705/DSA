#include<iostream>

using namespace std;

class abc{

//use of Static -> When a data member of a class is declared as static, it means there is only one instance of that variable shared among all instances of the class. It’s essentially a class-level variable, not tied to any specific object instance.
public:
    // static int x,y;
    int x,y; 

    static void print() {
        // cout << x << " " << y << endl;
            printf("I am inside the %s\n", __FUNCTION__); //MACRO -> __FUNCTION__ used for printing the current function name! 
    }
};

// int abc::x; //// Must define static member outside of class
// int abc::y;

int main() {
    abc obj1;
    abc obj2;

    // obj1.x = 1; 
    // obj1.y = 2;
    // obj1.print(); 

    // obj2.x = 10;
    // obj2.y  = 20;
    // obj1.print();
    // obj2.print();
    
    abc::print();
    obj1.print();
    obj2.print();
    abc::print();
    abc::print();


    return 0;

}