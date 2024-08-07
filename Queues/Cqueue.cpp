#include<iostream>

using namespace std;

//Implementing Circular Queue
class Cqueue{
   public:
        int * arr;
        int size;
        int front;
        int rear;


        Cqueue(int size){
            arr = new int[size];
            this->size = size;
            front = -1;
            rear = -1;
        }

        void push(int data){
            
            if(front == -1 && rear == -1){
                //empty queue -> push single element
                front++;
                rear++;
                arr[rear] = data;
            }
            else if((front == 0 && rear == size-1) || (front - rear == 1)){
                //overflow , you can also do-> rear = front-1;
                cout << "Queue Overflow" << endl;
            }
            else if(rear == size-1 && front != 0){
                //circular nature
                rear = 0;
                arr[rear] = data;
            }
            else{
                //normal flow 
                rear++;
                arr[rear] = data;
            }

        }

        void pop(){
            if(front == -1 && rear == -1){
                //empty queue /Underflow
                cout << "Cannot delete queue is empty" << endl;
                return; 
            }          
            else if(front == rear){
                //single element
                arr[front] = -1;
                front = -1;
                rear = -1;
            }    
            else if(front == size-1){
                //circular nature
                arr[front] = -1;
                front = 0;
            }
            else{
                //normal flow 
                arr[front] = -1;
                front++;
            }
               
        }

        int getFront(){
            if(front == -1){
               return -1;
            }
            else{
                return arr[front];
            }
        }

        int getRear(){
            if(rear == -1) {
                return -1;
            }
            else{
                return arr[rear];
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

    Cqueue cq(5);
    cq.print();

    cq.push(10);
    cq.print();

    cq.push(20);
    cq.print();

    cq.push(30);
    cq.print();

    cq.push(40);
    cq.print();

    cq.push(50);
    cq.print();

    cout << "front element : " << cq.getFront() << endl;
    cout << "Rear element : " << cq.getRear() << endl;

    cq.pop();
    cq.print();

    cq.pop();
    cq.print();

    cq.pop();
    cq.print();

    cq.push(100);
    cq.print();

    cq.push(110);
    cq.print();

    cq.push(120);
    cq.print();

    cq.push(130);
    cq.print();
    

}