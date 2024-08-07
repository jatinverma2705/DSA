#include<iostream>
#include<stack>

using namespace std;

//Implement two stacks in an array.
class Stack{
  public:
    int *arr;
    int size;
    int top1;
    int top2;
    
    Stack(int size){
        arr = new int[size];
        this->size = size;
        top1 = -1;
        top2 = size;
    }

    void push1(int data){

        if(top2-top1 == 1){
            //stack is full 
            cout << "OVERFLOW" << endl;
        }

        else{
            top1++;
            arr[top1] = data;            
        } 
    }

    void pop1(){
        if(top1 == -1){
            //stack is empty
            cout << "UNDERFLOW" << endl;
        }
        else{
            arr[top1] = 0;
            top1--;
        }
    }

    void push2(int data){
        if(top2-top1 == 1){
            //stack is full no memory.
            cout << "OVERFLOW" << endl;
        }
        else{
            top2--;
            arr[top2] = data;
        }
    }

    void pop2(){
        if(top2 == size){
            cout << "UNDERFLOW" << endl;
        }
        else{
            arr[top2] = 0;
            top2++;
        }
    }

    void print(){
        cout << endl;
        for(int i=0;i<size;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

bool checkRedundant(string &str){
   stack<int>st;

   for(int i=0;i<str.length();i++){
        char ch = str[i];
        if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/'){
            st.push(ch);
        }

        else if(ch==')'){
            int operatorCount = 0;
            while(!st.empty() && st.top()!='('){

                char temp = st.top();

                if(temp=='+' || temp=='-' || temp=='*' || temp=='/'){

                    operatorCount++;

                }

                st.pop(); 
               
            }
            //yha tak aap tabhi pohchoge jab
            //aapke stack ke top par ak opening bracket hoga
            st.pop();

            if(operatorCount == 0){
                return true;
            }
        }

   }
   //agar main yha tak pohcha hoon 
   //iska matlab har ak bracket ke pair ke beech mein ak operator pakka mila hoga
   
    return false;
    
}


int main(){
    
    // //Q1. Implement two stacks in an array.
    // Stack st(6);

    // st.push1(10);
    // st.print();

    // st.push1(20);
    // st.print();

    // st.push2(400);
    // st.print();

    // st.push2(300);
    // st.print();

    // st.push2(200);
    // st.print();

    // st.push2(100);
    // st.print();

    // st.pop1();
    // st.pop1();
    // st.pop1();
    // st.print();


    //Q2. Remove redundant brackets.
    // Redundant brackets-> faltu ke brackets
    //Return true if there is redundant bracket present and false if not.

    string str = "((a+b)*(c+d))";

    bool ans = checkRedundant(str);

    if(ans == true){
        cout << "String contains redundant brackets" << endl;

    }
    else{
        cout << "String does not contains redundant brackets" << endl;
    }
    

    return 0;
}