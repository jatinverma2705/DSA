#include<iostream>

using namespace std;

int x = 20; //Declaration of the global variable.

void fun() {
    int x = 34;
    cout << x << endl; 
    cout << ::x << endl; 
}


int main(){

    //x = 10; x = 10 
    
    ::x = 90; //changing the value of the global x

    int x = 4;
    cout << x << endl;//gives O/P 4 local x
    cout << ::x << endl;//accessing global x
    

    cout << x << endl;
     {
        int x = 200;
        cout << x << endl;
     }
     {
        int x = 0;
        {
            int x = 6;
            cout << x << endl;
        }
        cout << x << endl;
        
     }

    fun();

    return 0;
}