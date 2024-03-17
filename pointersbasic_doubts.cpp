#include<iostream>
using namespace std;

void solve(int * &p){
    // cout<< "Size of array inside function:"<<sizeof(arr);
    //actual me arrays passed by reference as a pointer containing the base adress of the array
    p=p+1;
}
int main(){
    //why we can't do arr = arr+1. -> This is because the name of the array is the 
    //constant pointer pointing to the first position of the array.
    //and we cant modify the constant pointer.

    // int arr[5] = {1,2,3,4,5};
    // int* ptr = arr;//pointing to the first element of the array -> 1;
    // cout << *ptr <<endl;
   
    // // cout<<*ptr++<<endl;
   
    // cout << *ptr <<endl;

    // for(int i=0;i<5;i++){
    //     cout << arr[i] << " ";
    // }

    //Wild pointers in cpp
    //(a) Uninitialized pointers 
    // int *ptr ;
    // cout << *ptr;

    //(b) Deleting pointers
    // int *ptr = new int;
    // delete ptr;
    // cout << *ptr;

    //(c) Pointers  to a non existent variables
    // int *ptr = &x;
    // cout << *ptr;


    //void pointers
    // void *ptr; // creation
    // int x = 10;
    // ptr = &x;
    // int *intptr = static_cast<int*>(ptr);//cast ptr pointer into the new intptr pointer
    // cout << *intptr;

    // int *ptr = new int;
    // *ptr = 10; // Assigning a value to the dynamically allocated integer

    // char *cptr = new char;
    // *cptr = 'a'; // Assigning a value to the dynamically allocated integer
    // cout << *cptr;

    //dangling pointers
    // int *ptr = new int;
    // *ptr = 10;
    // delete ptr;//deletes the memory location stored in ptr
    // cout << *ptr;


    //array of pointers
    // int *arr[3] ; // array of pointers to int
    // int nums[3] = {1,2,3};
    // int *ptr = nums;//adress of first element of the nums array.

    //assigning pointers to the elements in the array of elements
    // arr[0] =  &nums[0];
    // arr[1] =  &nums[1];
    // arr[2] =  &nums[2];
    // //accessing elements using array notation
    // cout << *arr[0];//prints 1 
    // cout << *arr[1];//prints 2
    // cout << *arr[2];//prints 3

    // cout << endl;
    // //accessing element using pointer notation
    // cout<<*ptr <<endl;
    // cout << *(ptr+1) << endl;
    // cout << *(ptr+2) << endl;

    //another way of doing this is
    // int nums[10] = {1,2,3,4,5,6,7,8,9,10};
    // int (*ptr)[10] = &nums;//pointer to an array of 10 integers
    // //accessing values of the array using pointer notation
    // cout<<(*ptr)[0] << endl;
    // cout<<(*ptr)[1] << endl;
    // cout<<(*ptr)[2] << endl;
    // cout<<(*ptr)[3] << endl;
    // cout<<(*ptr)[9] << endl;
    //In this way we can access the values by applying a pointer to an array!

    // int arr[5] = {1,2,3,4,5};
    // int (*ptr)[5] = &arr;

    // int arr[] = {10,20,30,40};
    // int size = 4;
    // cout <<"size of arr inside main:" <<sizeof(arr)<< endl;
    // solve(arr,size);

    // int a=5;
    // int *p = &a;

    // cout << p << endl;
    // cout << &p << endl;
    // cout << *p << endl;
    // solve(p);

    // cout << p << endl;
    // cout << &p << endl;
    // cout << *p << endl;

    //quiz practice
    // cout << 6359 % 320 <<endl;
    // string*x,y;
    // cout<<x<<"   " <<y;

    // int a=5,b=10,c=15;
    // int *arr[] = {&a,&b,&c};
    // cout << arr[1]<<endl;
    // cout << *arr[1];

    
// char st[] = "ABCD";
// for(int i = 0; st[i] != '\0'; i++) {
// cout << st[i] << *(st)+i << *(i+st) << i[st];
// }

    // int p = 5;
    // int const *w=&p;
    // // p++;
    // *w++;
    // cout<<*w;

    // int const  p = 5;
    // cout<<++p;

    // cout<<(12*13)%5 <<endl;
    // char *ptr = "codehelp";
    // cout << *ptr;

    int x = 10;
    int *ptr = &x;
    cout << *ptr + 2**ptr-3**ptr;

    return 0;
}