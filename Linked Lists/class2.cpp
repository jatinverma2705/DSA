#include<iostream>

using namespace std;

class Node{
public: 
    int data;
    Node *prev;
    Node *next;

    Node(){
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void printLL(Node *&head){
    Node *temp = head;
    while(temp != 0){
        cout  << temp->data << " -> ";
        temp = temp->next;
    }
}

int findlen(Node*&head){
    int len = 0;
    Node *temp = head;
    while(temp != 0){
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(Node *&head,Node *&tail, int data){
    if(head == NULL){
        //LL is empty
        Node *newnode = new Node(data);
        head = newnode;
        tail = newnode;
    }
    else{
        //LL is not empty
        Node *newnode = new Node(data);
        newnode->next = head;
        head->prev = newnode;
        head = newnode;

    }
}

void insertAtTail(Node *&head,Node *&tail,int data){

    if(head == NULL){
        //LL is empty
        Node *newnode = new Node(data);
        head  = newnode;
        tail  = newnode;
    }
    else{
        //LL is not empty
        Node *newnode = new Node(data);
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;

    }
}

void insertAtPosition(Node *&head,Node *&tail,int position,int data){
    if(head == NULL){
        Node *newnode = new Node(data);
        head = newnode;
        tail = newnode;
    }

    int len = findlen(head);

    if(position == 1){
        insertAtHead(head,tail,data);
    }

    else if(position == len + 1){
        insertAtTail(head,tail,data);
    }

    else{
    Node *newnode = new Node(data);

    //Step-> Traverse prev/curr node;
    Node *prevNode = NULL;
    Node *currNode = head;
    while(position != 1){
        position--;
        prevNode = currNode;
        currNode = currNode->next;
    }

    prevNode->next = newnode;
    newnode->prev = prevNode;
    newnode->next = currNode;
    currNode->prev = newnode;
    }

}

void deleteNode(Node * &head,Node *&tail,int position){
    //Valid deletions : range -> [1 to len]
    int len = findlen(head);

    if(head == NULL){
        cout << "Cannot delete from an empty LL" << endl;
    }

    if(position == 1){
        //delete from head
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
    }

    if(position == len){
        //delete from tail
        Node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        temp->prev = NULL;
        delete temp;
    }

    else{
        //delete from middle
        Node *prevNode = NULL;
        Node *currNode  = head;
        while(position != 1){
            prevNode = currNode;
            currNode = currNode->next;
            position--;
        }
        //Attach prevNode -> next = currNode->next
        Node *nextnode = currNode->next;
        prevNode->next = nextnode;
        nextnode->prev = prevNode;
        currNode -> next = NULL;
        currNode->prev = NULL;
        delete currNode;

    }
}

int main(){

Node *head = NULL;
Node *tail = NULL;

insertAtTail(head,tail,50);
insertAtHead(head,tail,40);
insertAtHead(head,tail,30);
insertAtHead(head,tail,20);
insertAtHead(head,tail,10);

deleteNode(head,tail,2);

// insertAtPosition(head,tail,5,25);

printLL(head);

}