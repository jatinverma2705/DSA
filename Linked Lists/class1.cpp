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
         newnode->next = head;

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

void deleteNode(Node * &head,Node * &tail, int position){
    //Assumptions : Valid deletions from [1 to length]
    int len = Getlen(head);
    if(head == NULL){
        //empty linked list
        cout << "Cannot delete because LL is empty" << endl;
    }
    
    if(position == 1){
        //delete from head
        //Step1 : make a temp pointing to head.
        Node *temp = head;
        //Step2 : move head to next node
        head = head->next; // or head = temp->next
        //Step 3 : Isolate the node
        temp->next = NULL;
        //Step 4 : delete temp
        delete temp;
    }

    else if(position == len){
        //delete from tail
        //Step 1:find prev : Set prev to second last node
        Node *prev = head;
        while(prev->next != tail){ 
            prev = prev->next;
        }
        //Step2 : Set prev -> next to NULL.
        prev->next = NULL;
        //Step 3: DELETE tail
        delete tail;
        //Attach tail to prev
        tail = prev;
    }

    else{
        //delete from middle
        //Step1: Traverse LL for prev/curr
        Node *prev = NULL;
        Node *curr  = head;
        while(position != 1){
            prev = curr;
            curr = curr->next;
            position--;
        }

        //Attach previous ka next to curr->next
        prev->next = curr->next;
        //Isolate curr node
        curr->next = NULL;
        //delete curr for avoiding memory leak
        delete curr;
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

    insertAtHead(head,tail,50);
    insertAtHead(head,tail,40);
    insertAtHead(head,tail,30);
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,10);
    printLL(head);
    cout << endl;
    
    // insertAtPosition(head,tail,0,144);
    // insertAtPosition(head,tail,-2,111);
    // insertAtPosition(head,tail,56,78);
    // printLL(head);

    // deleteNode(head,tail,1);
    // deleteNode(head,tail,5);
    // deleteNode(head,tail,3);
    deleteNode(head,tail,3);
    printLL(head);

    return 0;
}