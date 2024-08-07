#include<iostream>
#include<queue>

using namespace std;

//Implementing our queue class
class Queue{
public:
    int *arr;
    int size;
    int front;
    int rear;

    Queue(int size){
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }

    void push(int data){

        if(front == -1 && rear == -1){
            //queue is empty.
            front++;rear++;
            arr[rear] = data;
        }
        else if(rear == size-1){
            //queue is full.
            cout << "Queue Overflow" << endl;
        }
        else{
            //normal case
            rear++;
            arr[rear] = data;
        }
        
    }

    void pop(){
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

        else{
            //pop in normal case
            arr[front] = -1;
            front++;
        }
    }

    bool isEmpty(){
        if(front == -1 && rear == -1){
            return true;
        }
        else{
            return false;
        }
    }

    int getSize(){
        if(front == -1 && rear == -1){
            //empty queue
            return 0;
        }
        else{
            return rear-front+1;

        }
    }

    int getFront(){
        if(front == -1){
            cout << "Cannot get front , queue is empty" << endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }

    int getRear(){
        if(rear == -1){
            cout << "Cannot get rear element , queue is empty" << endl;
        }
        else{
            return arr[rear];
        }
    }

    void print(){

        cout << "Printing Queue : ";
        for(int i=0;i<size;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){

    //Important note: Queue me elements insert rear se hote hai and delete front se hote ha.

    //creation of queue
    // queue<int>q;

    // //Insertion in queue
    // q.push(10);
    // q.push(20);

    // //Size check in queue
    // cout << "size of queue : " << q.size() << endl;

    // //front element
    // cout << "Front element in queue: "<< q.front() << endl;

    // //rear element in a queue
    // cout << "Rear element in queue: " << q.back() << endl;

    // //isEmpty check
    // if(q.empty() == true){
    //     cout << "Queue is empty" << endl;
    // }
    // else{
    //     cout << "Queue is not empty" << endl;
    // }

    // //remove element from queue
    // q.pop();
    // cout << "After popping, ";
    // cout << "size of queue : " << q.size() << endl;

    //-> -> -> -> -> -> -> -> -> -> -> 

    //Q-> Implementation of our queue class.
    // Queue q(5);

    
    // q.push(10);
    // q.print();

    // cout <<endl;

    // q.push(20);
    // q.print();

    // cout <<endl;

    // q.push(30);
    // q.print();

    // cout <<endl;
    // q.push(40);
    // q.print();

    // cout <<endl;
    // q.push(50);
    // q.print();

    // q.pop();
    // q.print();

    // q.pop();
    // q.print();

    // q.pop();
    // q.print();

    // q.pop();
    // q.print();

    // q.pop();
    // q.print();

    // q.pop();

    // cout <<  "Size :" << q.getSize() << endl;
    // cout <<  "Front element of q : " << q.getFront() << endl;
    // cout << "Rear element: " << q.getRear() << endl;
    // q.pop();
    // cout <<  "Front element of q : " << q.getFront() << endl;
    

}