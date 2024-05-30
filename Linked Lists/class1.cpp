#include<iostream>

using namespace std;

class Node{
public:
    int data;
    Node *next;

    //Default ctor
    Node(){
        this->next = NULL;
    }

    //parameterized ctor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void printLL(Node *head){

    Node *temp = head;

    cout << "Printing linked list :" << endl;

    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
}

int Getlen(Node *head){
    int count = 0;
    Node *temp = head;
    while(temp!= NULL){
        count ++;
        temp = temp->next;
    }

    return count;
}

void insertAtHead(Node * &head,Node *&tail,int data){

    if(head == NULL){
        //empty linked list
        Node *newnode = new Node(data);
        head = newnode;
        tail = newnode;
    }
    else{
        //non- empty linked list 
        //create a new node
        Node *newnode = new Node(data);
    
         //attach new node to head node
         newnode -> next = head;

        //update head 
         head = newnode;
    } 
}

void insertAtTail(Node *&head,Node * &tail,int data){
    if(head == NULL){
        //empty linked list
        Node * newnode = new Node(data);
        tail = newnode;
        head = newnode;
    }
    else{
        //non empty linked list

       //step1 -> create  a new node
     Node *newnode = new Node(data);
    //step2 -> tail node ko attach karo new node se
    tail->next = newnode;
    //step3 -> tail ko update kardo
    tail = newnode;
    }
 
}

void insertAtPosition(Node *&head,Node *&tail,int position,int data){
    int length = Getlen(head);
    if(position <= 1){
        insertAtHead(head,tail,data);
    }
    else if(position > length){
        insertAtTail(head,tail,data);
    }
    else{
        //insert at the middle of the linked list

        //Step1 : create a new node
        Node *newnode = new Node(data);

        //Step 2: Traverse prev // curr to position
        Node *prev = NULL;
        Node *curr = head;
        while(position != 1){
            prev = curr;
            curr = curr->next;
            position--;
        }
        //Step 3 : Attach prev to new node
        prev->next = newnode;
        newnode->next = curr;
    }
  
}

int main(){

    //Creation of Node
    //Node a; -> static allocation

    //Node *head = new Node();
    
    // Node *first = new Node(10);
    // Node *second = new Node(20);
    // Node *third = new Node(30);
    // Node *fourth = new Node(40);
    // Node *fifth = new Node(50);

    // first->next = second;
    // second->next = third;
    // third->next = fourth;
    // fourth->next = fifth;
    //Linked list create ho chuki hai

    // Node *head = first;
    // Node *tail = fifth;
    // printLL(head);

    //int ans =  Getlen(head);
    //cout << "Length of the linked list : " << ans << endl;
    // printLL(head);

    // // insertAtHead(head,tail,500);
    // insertAtTail(head,tail,500);

    // cout << endl;

    // printLL(head);

    Node *head = NULL;
    Node *tail = NULL; 

    insertAtHead(head,tail,10);
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,30);
    insertAtTail(head,tail,500);
    printLL(head);
    cout << endl;
    
    insertAtPosition(head,tail,0,144);
    insertAtPosition(head,tail,-2,111);
    insertAtPosition(head,tail,56,78);
    printLL(head);

    return 0;
}