#include<iostream>

using namespace std;

//C++ provides inline functions to reduce the function call overhead
//An inline function is a function that is expanded in line when it is called
//When the inline function is called whole code of the inline function gets inserted or substituted at the point of the inline function call.

inline void printnumber(int num){
    cout << num << endl;
}

int main(){
    printnumber(10);
    printnumber(10);
    printnumber(10);
    printnumber(10);
    printnumber(10);
    printnumber(10);
    printnumber(10);

    return 0;
}