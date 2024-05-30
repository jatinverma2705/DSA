#include<iostream>

using namespace std;

class Box{
    int width;
    //private ctor
    Box(int _w):width(_w){};

public:


    int GetWidth(){
        return width;
    }

    void SetWidth(int _val){
        width = _val;
    }
};

int main(){
    //Q-> Can constructor be made private?
    //Ans-> yes, it can be made private.
    // Box a(2);
    
    
    return 0; 
}