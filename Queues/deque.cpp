#include<iostream>
#include<deque>

using namespace std;

//Implementing Doubly Ended Linked List with circular behaviour  -> means you can push and pop elements from both sides

class Dqueue{
public: 
    int *arr;
    int size;
    int front;
    int rear;

    Dqueue(int size) {
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }

    void push_back(int val){
       if(front == -1 && rear == -1){
            //empty queue -> push single element
            front++;
            rear++;
            arr[rear] = val;
        }
        else if((front == 0 && rear == size-1) || (front - rear == 1)){
            //overflow , you can also do-> rear = front-1;
            cout << "Queue Overflow" << endl;
        }
        else if(rear == size-1 && front != 0){
            //circular nature
            rear = 0;
            arr[rear] = val;
        }
        else{
            //normal flow 
            rear++;
            arr[rear] = val;
        }
    }

    void  push_front(int val){
        
        if((front == 0 && rear == size-1) || (front - rear == 1)){
            //overflow , you can also do-> rear = front-1;
            cout << "Queue Overflow" << endl;
        }
        else if(front == -1 && rear == -1){
            //single element 
            front++;
            rear++;
            arr[front] = val;
        }  
        else if(front == 0 && rear != size-1){
            //circular nature
            front = size-1;
            arr[front] = val;
        }
        else{
            //normal flow 
            front--;
            arr[front] = val;
       }    
    }

    void pop_back(){

        //underflow 
        //single element
        //circular case
        //normal flow 
        if(front == -1 && rear == -1){
            cout << "Underflow" << endl;
        }
        else if(front == rear){
            arr[rear] = -1;
            front = -1;
            rear = -1;
        }
        else if(rear == 0 && front != size-1){
            arr[rear] = -1;
            rear = size-1;
        }
        else{
            arr[rear] = -1;
            rear--;
        }
    }
    
    void pop_front(){
        if(front == -1 && rear == -1){ 
            //empty queue
            cout << "Queue Underflow -> Empty" << endl;
        }

        else if(front == rear){
            //single element ko pop karna h
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else if(front == size-1){
            arr[front] = -1;
            front = 0;
        }

        else{
            //pop in normal case
            arr[front] = -1;
            front++;
        }
    }

    void print(){
        cout << "Printing : ";
        for(int i=0;i<size;i++){
            cout << arr[i] << " ";
        }
        cout << endl;   
    }
    
};

int main(){

    // deque<int>dq;

    // dq.push_back(10);
    // dq.push_front(20);
    // dq.push_front(40);

    // dq.push_front(50);
     
    // cout << dq.front() << endl;
    // cout << dq.back() << endl;

    // cout << "Size: " << dq.size() << endl;

    Dqueue cdq(5);

    cdq.push_front(10);
    cdq.push_back(20);
    cdq.push_back(30);
    cdq.push_back(40);
    cdq.push_front(100);
    // cdq.push_back(1000);

    cdq.print();
    
}