#include<iostream>

using namespace std;
//Basically compiletime polymorphism(also called static poly.) contains has two parts -> (1) Function overloading (2). Operator Overloading
//function overloading
int add(int a,int b){
    return a+b;
}

double add(double a,double b) 
{
    return a+b;
}

int add(int a, int b,int c){
    return a+b+c;
}

class Vector{
    int x,y;
public:

    
    // Vector(int x,int y){
    //     this->x = x;
    //     this->y = y;
    // }
    //init list
    Vector(int x,int y) : x(x),y(y) {}

    //Operator Overloading
    void operator+(const Vector&src){
        //this would point to v1;
        //src would be a ref to v2;

        this->x += src.x;
        this->y += src.y;

    }

    void operator-(const Vector&src){
        //this would point to v1;
        //src would be a ref to v2;

        this->x -= src.x;
        this->y -= src.y;

    }

    void operator++(){
        

        this->x++;
        this->y++;

    }
    void display(){
        cout << "x:" << x << endl << "y:" << y << endl;
    }
};

int main(){

    // cout << add(3,4) << endl;
    // cout << add(3.45,4.97) << endl;
    // cout << add(3,4,3) << endl;

    // Vector v;
    // v.display(2,3);

    Vector v1(2,3);
    Vector v2(5,7);

    //v1+v2;
    //v1-v2;
    ++v1;
 
    //addition answer should be stored in v1.
    v1.display() ;
    return 0;
}