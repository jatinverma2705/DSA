#include<iostream>
#include<stack>
#include<queue>
#include<deque>

using namespace std;

//reverse Queue using stack
void reversequeue(queue<int>&q){
    stack<int>st;

    //one by one queue se element lo and stack mein dalo
    while(!q.empty()){
        int element = q.front();
        q.pop();

        st.push(element);
    }

    //one by one stack se element nikalkar vapis queue mein daalo
    while(!st.empty()){
        int element = st.top();
        st.pop();

        q.push(element);
    }     
}

//reverse Queue using Recursion
void reverseQ(queue<int>&q){
    if(q.empty()){
        return;
    }

    int temp = q.front();
    q.pop();

    reverseQ(q);

    q.push(temp);
}

//reverse first K numbers
void reverseKdigits(queue<int>& q,int k){
    if(k > q.size() || k==0){
        return;
    }
    stack<int> st;

    //Insert K elements into stack from queue
    for(int i=0;i<k;i++){
        int element = q.front();
        q.pop();

        st.push(element);
    }

    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }

    for(int i=0;i<q.size() - k;i++){
        int element = q.front();
        q.pop();
        q.push(element);
    }
}

//Our question assumption is always we get even sized q.
void interleaveQueue(queue<int>& first){
    int n = first.size();

    queue<int>second;

    for(int i=0;i<n/2;i++){
        int front = first.front();
        first.pop();
        second.push(front);
    }

    //Interleaving the two queues first and second 
    while(!second.empty()){
        int temp = second.front();
        second.pop();

        first.push(temp);
        temp = first.front();
        first.pop();
        first.push(temp);
    }

}

void findfirstNegative(int *arr,int n,int k){

    deque<int>dq;

    //process first k elements -> first window 
    for(int index=0;index<k;index++){
        int element = arr[index];
        if(element < 0){
            dq.push_back(index);
        }
    }

    //process remaining windows-> Removal and Addition
    for(int index = k;index < n;index++){

        //aage bhadne se pehle puraani window ka ans print karo.
        if(dq.empty()){
            cout << "0" << endl;
        }
        else{
            cout << arr[dq.front()] << " ";
        }


        //Removal-> jo bhi index out of range hoga usko queue se remove kardo.
        if(index - dq.front() >= k){
            dq.pop_front();
        }

        //Addition
        if(arr[index] < 0){
            dq.push_back(index);
        }
    }

    //last window ka answer print karo
    if(dq.empty()){
        cout << "0" << endl;
    }

    else{
        cout << arr[dq.front()] << " ";
    }

}

int main(){

    // queue<int>q;

    // q.push(10);
    // q.push(20);
    // q.push(30);
    // q.push(40);
    // q.push(50);
    // q.push(60);

    // // reverseQ(q);
    // // reverseKdigits(q,3);
    // interleaveQueue(q);

    // cout << "Printing Queue: " << endl;
    // while(!q.empty()){
    //     int element = q.front();
    //     q.pop();
    //     cout << element << " ";
    // }


    //Q-> Find first Negative element in every window of size k.
    int arr[] = {2,-5,4,-1,-2,0,5};
    int size = 7;
    int k=3;

    findfirstNegative(arr,size,k);

}