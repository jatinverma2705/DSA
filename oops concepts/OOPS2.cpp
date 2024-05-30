#include<iostream>

using namespace std; 

class abc{ 
    int x; //if we write mutable before  x then we are able to modify x anywhere if the particular member function is const.
    int *y;
    const int z;

public: 

    // abc(){
    //     x = 0;
    //     y = new int(0);
       
    // } and

    //ctor -> old style allProblem

    // abc(int _x , int _y, int _z = 0){ //z -> default argument
    //     x = _x;
    //     y = new int(_y);
    //     z = _z;
    // }

    //Works same as ctor
    //Initialization list ->  We can also initialise a const var. in this list.
    //Syntax : 
    abc(int _x,int _y,int _z=0):x(_x),y(new int(_y)),z(_z) {
        
        cout << "In init.. list" << endl;
        *y = *y * 10;
    }

    int getX() const 
    { 
        
        cout << x << endl; 
    }

    void setX(int _val){
        x = _val;
    }


    int getY() const 
    {
        cout << *y << endl;
    }

    void setY(int _val){
        *y = _val;
    } 

    int getZ() const 
    {
        return z;
    }

    //default destructor : 
    // ~class_name(){

   // }
};

void printABC(const abc&a){
    cout << a.getX() << " " << a.getY() << " " << a.getZ() ;
}

int main(){
    abc a(1,2,3);
    printABC(a);
    
//    cout << a.getX() << endl;
//    cout << a.getY()<<endl;

    return 0;
}

int main2(){

   // const int x = 5;// x is constant
    //Initialization can be done
    //but we can't reassign a value
    //we can't do like-> x = 10;
    // cout << x << endl;


    //2.const with pointer
    // const int *a = new int(2);// CONST data , NON-CONST pointer
    // int const *a = new int(2); //works same as line 13. 
    // cout << *a << endl;
    // *a = 10; //can't change the content of pointer.
    // int b = 5;
    // a = &b; //Pointer itself can be reassigned.
    // cout << *a << endl;

    //3.CONST POINTER BUT NON-CONST DATA
    /* int *const a = new int(2);
    cout << *a << endl;
    *a = 10;//we can change the data of the pointer.
    int b = 5;
    a = &b;//Pointer itself can't be reassigned.
    cout << *a << endl;
    */

   //4. CONST POINTER , CONST DATA
  /*const int *const a = new int(2);
   cout << *a << endl;
   *a = 3; -> we cannot change the content of pointer
   int b = 4;
   a = &b; -> Pointer itself can't be reassigned.
   cout << *a << endl;*/ 

 return 0;
}
