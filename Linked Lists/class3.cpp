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

Node* reverseLL(Node *&head){
    Node *prev = NULL;
    Node *curr = head;


    while(curr != NULL){
        Node *nextnode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextnode;
    }

    return prev;
}

Node * reverseLLusingRecursion(Node * &head,Node *prev,Node *curr){
    
    if(curr == NULL){
        return prev;
    }
    Node *nextnode = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nextnode;

 return reverseLLusingRecursion(head,prev,curr);
//   return recursionans;
    
}

Node * middleOFLL(Node * slow,Node * fast){
    while(fast != NULL){

        fast = fast->next;

        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}

bool checkPalindrome(Node * &head,Node *slow ,Node *fast){
    //step1 : Break into two halves
    while(fast->next != NULL){
        fast = fast->next;

        if(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }

    Node* headNode2 = slow->next;
    slow->next = NULL;

    //Step2 : Reverse the second breaked half
    Node *prev = NULL;
    Node *curr = headNode2;

    while(curr != NULL){
        Node *nextnode = curr->next; 
        curr->next = prev;
        prev = curr;
        curr = nextnode;
    }

    //Now prev of second reversed part is acting like the head of the second part.

    while(head != NULL && prev != NULL ){
        if(head->data !=  prev->data){
            return false;
        }
        else{
            head = head->next;
            prev = prev->next;
        }
    }
    return true;
}

bool checkloop(Node *head){
    //Using the Tortoise Algorithm
    Node *slow = head;
    Node *fast = head;

    while(fast != NULL){
        fast = fast->next;

        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        //condition for checking loop
        if(slow == fast){
            return true;// loop presents
        }
    }

    return false;
}

Node *startingnodeofloop(Node *head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL){
        fast = fast ->next;

        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        if(slow == fast){
            break;
        }
    }

    //Now the algorithm for finding out the starting node for loop-> 
    //Step1 : slow ko head par point kara do 
    //Step2 : slow and fast dono ko ak ak karke aage badhao .
    // jis node par slow and fast equal honge vhi node starting node hogi 
    slow = head;

    while(fast != slow){
        fast = fast->next;
        slow = slow->next;
    }

    //slow and fast dono starting node par point krenge.kisi ko bhi return kardo whether slow ya fast.
    return slow;
}

void removeLoop(Node *head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL){
        fast = fast ->next;

        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        if(slow == fast){
            break;
        }
    }

    //starting node of linked list
    slow = head;

    while(fast != slow){
        fast = fast->next;
        slow = slow->next;
    }
    
    //Now slow pointing to starting node of loop
    //removing the loop :
    Node* startingnode = slow;
    Node *temp = startingnode;

    while(temp->next != startingnode){
        temp = temp->next;
    }

    //remove the connection of temp/last node.
    temp->next = NULL;
}

void addOne(Node *head){
    //Step1 : Reverse LL
    head = reverseLL(head);
    //Step2 : Add one 

    int carry = 1;
    Node *temp = head;
    while(temp->next != NULL){

        int totalSum = temp->data + carry;
        int digit = totalSum % 10;
        carry = totalSum / 10;
        temp->data = digit;

        temp = temp->next;

        if(carry == 0){
            break;
        }
    } 

    //process last node
    if(carry != 0){
        int totalSum = temp->data + carry;
        int digit = totalSum % 10;
        carry =  totalSum /10;

        temp->data = digit;

        if(carry != 0){
            Node* newnode = new Node(carry);
            temp->next = newnode;
        }
    }

    //Step3 : Reverse LL again

    head = reverseLL(head);
}

int printKthNodedatafromend(Node* head,int positionfromtail){
    Node* slow = head;
    Node* fast = head;
    
    //ham fast ko( positionfromtail + 1) steps aage badha rahe h
    for(int i=0;i<=positionfromtail;i++){
        fast = fast->next;
    }

    //Now move fast and slow both one one steps so that slow reaches to the required position

    while(fast != NULL){
        fast = fast->next;
        slow = slow->next;
    }

    //Now slow is at our desired position, return value
    return slow->data;
}

int main(){

    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head,tail,5);
    insertAtHead(head,tail,4);
    insertAtHead(head,tail,3);
    insertAtHead(head,tail,2);
    insertAtHead(head,tail,1);

    //we want last 2nd node data.(positionfromtail is 0 indexed)
    // int positionfromtail = 2;
    // int ans = printKthNodedatafromend(head,2);
    // cout << "Data of "<<positionfromtail<<"nd node from end: "<< ans <<endl;
    // printLL(head);


    // insertAtHead(head,tail,60);
    // insertAtHead(head,tail,50);
    // insertAtHead(head,tail,40);
    // insertAtHead(head,tail,30);
    // insertAtHead(head,tail,20);
    // insertAtHead(head,tail,10);

    // insertAtHead(head,tail,8);
    // insertAtHead(head,tail,3);
    // insertAtHead(head,tail,1);
    // printLL(head);

    // addOne(head);

    //  cout << endl;
    // printLL(head);
    
   

    // Node *prev = NULL;
    // Node *curr = head;

    // printLL(head);

    // tail->next = head->next->next;
    // removeLoop(head);
    // printLL(head);
    // bool ans = checkloop(head);
    // cout << ans << endl;
    
    // Node *startingnode = startingnodeofloop(head);
    // cout << "Starting node of loop is : "<<  startingnode->data << endl;

    // Node *reversedhead = reverseLLusingRecursion(head,prev,curr);
    // cout << endl;

    // reverseLL(head);
    // printLL(reversedhead);

    // printLL(head);

    Node *slow = head;
    Node *fast = head;

    // Node *ans = middleOFLL(slow,fast);

    // cout << ans->data << endl;

    bool ans = checkPalindrome(head,slow,fast);
    cout <<  ans << endl;

}