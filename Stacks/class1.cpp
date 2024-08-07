#include<iostream>
#include<stack>

using namespace std;

//Implementation of our own stack class
class Stack{
 public:
    int *arr;     
    int size;
    int top;
    
    Stack(int size){ 
        arr = new int[size];
        this->size = size;
        this->top = -1;
    }

    void push(int data){
        if(top == size - 1){
            cout << "Overflow / Stack is full" << endl;
            return;
        }
        else{
        top++;
        arr[top] = data;
        }
    }

    void pop(){
        if(top == -1){
            cout << "stack is empty / Underflow condition " << endl;
            return;
        }
        else{
            top--;
        }
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }

    }

    int getTop(){
        if(top == -1){
            cout << "Stack is empty" << endl;
            return -1;
        }
        else{
            return arr[top]; 
        }
    }

    int getSize(){
        return top+1; 
    }

    void print(){
        cout << "Top : " << top << endl;
        cout << "Top element : "<< getTop() << endl;
        cout << "Stack : ";
        for(int i=0;i<getSize();i++){
            cout << arr[i] << " ";
        }
        cout << endl << endl;
    }
};

void solve(stack<int>&st , int &position, int &ans){
    
    if(position == 1){
      ans =  st.top();
      return ;
    }

    position--;
    int temp = st.top();
    st.pop();

    solve(st,position,ans);

    //backtracking 
    st.push(temp);
}

int getMiddleElement(stack<int>&st){
    
    int size = st.size();
    if(st.empty()){
        //means stack is empty.
        cout << "Stack is empty" << endl;
        return -1;
    }

    else{
        int pos = -1;

        if(size & 1){
            //odd size
            pos = size/2 + 1;

        }

        else{
            //Even size
            pos = size/2;
        }

        int ans = -1;
        solve(st,pos,ans);
        return ans;
    }
   
}


void insertAtBottom(stack<int>&st,int &keyelement,int &size){
    //base case
    if(size == 0){
        st.push(keyelement);
        return;
    }

    size--;
    int temp = st.top();
    st.pop();

    insertAtBottom(st,keyelement,size);

    //backtrack
    st.push(temp);
}

void printStack(stack<int>st){

    while(!st.empty()){
        int val = st.top();
        cout << val <<  " " ;
        st.pop();
    }

}

void insertAtbottom(stack<int>&st,int element){
    if(st.empty()){
        st.push(element);
        return;
    }

    int temp = st.top();
    st.pop();

    insertAtbottom(st,element);

    //backtraking 
    st.push(temp); 
}

void reverseStackusingRecursion(stack<int>&st){

    //base case
    if(st.empty()){
        return;
    }

    int temp = st.top();
    st.pop();

    reverseStackusingRecursion(st);

    //backtracking 
    insertAtbottom(st,temp);

}

void insertSorted(stack<int>&st, int element){
    //base case
    if(st.empty() || element > st.top()){
        st.push(element);
        return;
    }

    //one case solution 
    int temp = st.top();
    st.pop();

    insertSorted(st,element);

    //backtrack
    st.push(temp);
}

void sortStack(stack<int>&st){
    if(st.empty()){
        return;
    }

    int temp = st.top();
    st.pop();

    sortStack(st);

    //backtrack
    insertSorted(st,temp);
}

int main(){


// //creation of stack 
// stack<int>st;

// //Insertion in stack
// st.push(10);
// st.push(20);
// st.push(30);

// //Size check
// cout << "Size of stack : "<< st.size() << endl;

// //top element
// cout <<"Top element : "<< st.top() << endl;

// //remove 
// st.pop();
// cout <<"Top element after pop : "<< st.top() << endl;

// //check empty
// if(st.empty()){
//     cout << "Stack is empty " << endl;
// }
// else{
//     cout << "Stack is not empty" << endl;
// }

// cout << st.top() << endl;

//Static creation
// Stack st(8);

// st.push(10);
// st.print();

// st.push(20);
// st.print();

// st.push(30);
// st.print();

// // st.pop();
// // st.print();


// // st.pop();
// // st.print();

// // st.pop();
// // st.print();

// st.push(40);
// st.print();

// st.push(50);
// st.print();

// st.push(60);
// st.print();

// st.push(70);
// st.print();

// st.push(80);
// st.print();

// st.push(90);
// st.print();

// Q1. Find the Middle element of stack

//For odd size our middle element is => size/2 + 1;
//For even size our middle element is => size/2;
// stack<int>st;
// st.push(10);
// st.push(20);
// st.push(30);
// st.push(40);
// st.push(50);
// st.push(60);
// st.push(70);

// int ans = getMiddleElement(st);
// cout << "Middle Element : " <<  ans << endl;

//Q2 . Insert at Bottom of Stack 
// stack<int>st;
// st.push(10);
// st.push(20);
// st.push(30);

// int keyelement = 400;
// int size = st.size();

// cout << "Before inserting at end : ";
// printStack(st);
// // cout << "Size before inserting :" << st.size() << endl;
// insertAtBottom(st,keyelement,size);

// cout << endl;
// cout << "After inserting at end : ";
// printStack(st);

// // cout << "Size after inserting :" << st.size() << endl;

//Q3. Reverse a stack : 

//->There are many approaches to reverse a stack ;
// (1) Create another stack and push the elements into the new stack .
// (2) Using recursion.

// stack<int>st ;
// st.push(10);
// st.push(20);
// st.push(30);
// st.push(40);
// st.push(50);

// cout << "Before stack : " ;
// printStack(st);

// reverseStackusingRecursion(st);

// cout << endl;
// cout << "After Stack : ";
// printStack(st);

//Q4. Insert element in a sorted stack.

// stack<int>st;
// st.push(10);
// st.push(20);
// st.push(30);

// int element = 25;

// printStack(st);

// insertSorted(st,element);

// cout << endl;
// printStack(st);

//Q5. Sort a stack .

// stack<int>st;
// st.push(10);
// st.push(5);
// st.push(7);
// st.push(9);
// st.push(6);

// sortStack(st);
// printStack(st);
return 0;  
}