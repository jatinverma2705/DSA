#include<iostream>

using namespace std;

class abc{
public:
    int x;
    int *y;

    
    // Default Dumb copy ctor : It does shallow copy
    //Isme agar ham b=a karte to pointers of both the objects points to the same location in the heap memory.(security breach)
    // abc(const abc&src){
    //     x = src.x;
    //     y = src.y;
    // }

    //Our smart deep copy
    abc(const abc&src){
        x = src.x;
        y = new int(*src.y);        
    }

    //Init list
    abc(int _x,int _y) : x(_x) , y(new int(_y)){};

    void print(){
     printf("X:%d\nPTR Y:%p\nContent of Y(*y):%d\n\n",x,y,*y) ;
    }

    ~abc(){
        delete y;
    }    
};

int main(){
    // abc a(1,2);
    // a.print();

    // cout << endl;

    //copy ctor kaam aaega
    // abc b = a;//call hoga copy constructor 
    // b.print();
    // *b.y = 20;
    // b.print();

    // a.print();

    abc *a = new abc(1,2);
    abc b = *a;
    delete a;
    b.print();
    return 0; 
}