#include<iostream>
using namespace std;

int main() {
    //pointer creation
    // int a = 5;
    // int *ptr = &a;

    //pointer accessing 
    // cout << a <<endl;
    // cout << "adress of a:"<<&a <<endl;

    // cout << ptr <<endl;
    // cout << "value stored at adress pointer:" <<*ptr <<endl;
    // cout << "adress of pointer:"<<&ptr <<endl;
    //* -> derefernce operator.


    int a = 5;
    int *ptr1 = &a;
    cout << sizeof(ptr1) << endl;
    
    char b = 'k';
    char *ptr2 = &b;
    cout << sizeof(ptr2) << endl;

    long c = 10;
    long *ptr3 = &c;
    cout << sizeof(ptr3) << endl;

    // int a = 5;
    // int *p = &a;
    // cout << p << endl;
    // p = p+1;
    // cout<<p ;
    // int arr[5]  = {1,2,3,4,5};
    // arr = arr+ 1;
    // char ch[100] = "lovebabbar is good teacher";
    // cout << ch;
    // char ch[50] = "jatin verma";
    // cout << ch;
    // char ch[50] = "statement";
    // char *cptr = &ch[0];

    // cout << ch <<endl;
    // cout << &ch <<endl;//prints the based adress hexadecimal value
    // cout << *(ch+3) <<endl;
    // cout << cptr <<endl;
    // cout << &cptr <<endl;
    // cout << *(cptr+3) << endl;
    // cout << cptr + 2 <<endl;
    // cout << *cptr <<endl;
    // cout << cptr +8 <<endl;
    // int *ptr = nullptr; // way to create a null pointer
    // int a = 100;
    // int *ptr = &a;
    // cout << *a ; This is not possible kyuki *(value at adress ) sirf pointers par hi lagu hota h! a -> int hai!
    
    
    return 0 ;
}