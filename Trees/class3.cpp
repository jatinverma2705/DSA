#include<iostream>
#include<queue>
#include<vector>
#include<map>

using namespace std;

class Node{

public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    
};

//it returns the root node of the created tree
Node* createTree(){

    cout << "Enter the value : ";
    int data;
    cin >> data;

    //agar data -1 hai matlab node ko null point kara do matlab koi node mat lagao
    if(data == -1){
        return NULL;
    }

    //Step1 : make a new node / root node
    Node * root = new Node(data);

    //Step2: Make left subtree
    cout << root->data << " left node val process" << endl;
    root->left = createTree();

    //Step3: Make right subtree
    cout << root->data << " right node val process " << endl;
    root->right = createTree();

    return root;

}

//preOrder Traversal -> N L R
void preOrderTraversal(Node *root) {
    //base case
    if(root == NULL){
        return ;
    }

    //N -> current node ko process karo
    cout << root->data <<  " ";

    //L-> left part ko process karo
    preOrderTraversal(root->left);

    //R -> right part ko process karo
    preOrderTraversal(root->right);

}

//In order traversal -> L N R
void inOrderTraversal(Node *root) {
    //base case
    if(root == NULL){
        return ;
    }

    //L
    inOrderTraversal(root->left);

    //N -> current node
    cout << root->data << " ";

    //R
    inOrderTraversal(root->right);

}

void postOrderTraversal(Node *root){
    if(root == NULL){
        return;
    }

    //L
    postOrderTraversal(root->left);
 
    //R
    postOrderTraversal(root->right);

    //N
    cout << root->data << " ";
}


void levelOrderTraversal(Node * root){

    queue<Node*>q;
    q.push(root);

    //Here null acts as a marker kabhi bhi null milega to next line print kar dunga
    q.push(NULL);

    //asli traversal start krte hai
    while(!q.empty()){
        Node *front = q.front();
        q.pop();

        if(front == NULL){
            cout << endl;
            
            if(!q.empty()){
            q.push(NULL);
            }
        }

        else{
            //valid node
            cout << front->data << " ";

            //inserting child inside q
            if(front->left) {
                q.push(front->left);
            }

            if(front->right){
                q.push(front->right);
            }

        }
    }

}


void leftViewPrint(Node* root ,vector<int>&leftView, int level){
    
    if(root == NULL){
        return;
    }

    if(level == leftView.size()){
        //ans mein store kara lo 
        leftView.push_back(root->data);
    }

    //pehle left ki call
    leftViewPrint(root->left,leftView,level+1);

    //fir right subtree ki call
    leftViewPrint(root->right,leftView,level+1);

}

void rightViewPrint(Node* root ,vector<int>&rightView, int level){
    
    if(root == NULL){
        return;
    }

    if(level == rightView.size()){
        //ans mein store kara lo 
        rightView.push_back(root->data);
    }

    //pehle root->right ki call 
    rightViewPrint(root->right,rightView,level+1);

    //fir root->left ki call
    rightViewPrint(root->left,rightView,level+1);

}

void topViewPrint(Node * root){
    map<int,int> hdtoNodeMap;//->used to map hd with node data
    queue<pair<Node* , int> > q;
    q.push(make_pair(root,0));

    while(!q.empty()){

        pair<Node* , int>temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        //check karo ki map mein hd ke corresponding koi data store h ya nhi .
        //hdtoNodeMap.end()->matlab hd ke corresponding data nhi mil paya
        if(hdtoNodeMap.find(hd) == hdtoNodeMap.end()){
            hdtoNodeMap[hd] = frontNode->data;
        }

        //child ko dekhna h
        if(frontNode->left){
            q.push(make_pair(frontNode->left , hd - 1));
        }

        if(frontNode->right){
            q.push(make_pair(frontNode->right , hd + 1));
        }
    }

    cout << "Printing top View :" << endl;
    for(auto i:hdtoNodeMap){
        cout << i.second << " ";
    }
}

void bottomViewPrint(Node * root){
    map<int,int> hdtoNodeMap;//->used to map hd with node data
    queue<pair<Node* , int> > q;
    q.push(make_pair(root,0));

    while(!q.empty()){

        pair<Node* , int>temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        //overwrite mapping so that deeper nodes can be stored
        hdtoNodeMap[hd] = frontNode->data;

        //child ko dekhna h
        if(frontNode->left){
            q.push(make_pair(frontNode->left , hd - 1));
        }

        if(frontNode->right){
            q.push(make_pair(frontNode->right , hd + 1));
        }
    }

    cout << "Printing top View :" << endl;
    for(auto i:hdtoNodeMap){
        cout << i.second << " ";
    }
}

void printLeftBoundary(Node* root){
    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        //leaf node se vapas aana hai 
        return;
    }

    cout << root->data <<  " ";

    if(root->left != NULL){
        printLeftBoundary(root->left);
    }
    else{
        printLeftBoundary(root->right);
    }
}

void printLeafBoundary(Node* root){
    if(root == NULL)
        return;

    if(root->left == NULL && root->right == NULL){
        //leafnodes 
        cout << root -> data << " ";
    }

    printLeafBoundary(root->left);
    printLeafBoundary(root->right);
}

void printRightBoundary(Node* root){
    if(root == NULL)
        return;

    if(root->left == NULL && root->right == NULL){
        return;
    }
    
    if(root->right != NULL){
        printRightBoundary(root->right);
    }
    else{
        printRightBoundary(root->left);
    }

    cout << root -> data << " ";
}

void boundaryTraversal(Node* root){
    if(root == NULL)
        return;

    printLeftBoundary(root);
    printLeafBoundary(root);

    if(root -> right){
        printRightBoundary(root->right);
    }
    
    else{
        printRightBoundary(root->left);
    }
}

int main(){
    
    Node* root = createTree();
    // levelOrderTraversal(root);

    // vector<int>leftView;
    // leftViewPrint(root,leftView,0);
    // cout << "Printing left view : " ;
    // for(int i:leftView){
    //     cout << i  << " ";
    // }

    // vector<int>rightView;
    // rightViewPrint(root,rightView,0);
    // cout << "Printing right view : " ;
    // for(int i:rightView){
    //     cout << i  << " ";
    // }
    
    //5 10 15 -1 -1 20 -1 -1 25 -1 30 -1 100 -1 200 -1 -1 

    // topViewPrint(root);
    boundaryTraversal(root);
    return 0;
}