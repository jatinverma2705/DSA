#include<iostream>
#include<queue>

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

int main(){

    Node * rootNode = createTree();
    cout << "Root Node data : " <<  rootNode->data << endl;

    cout << "Pre Order Traversal : " ;
    preOrderTraversal(rootNode);

    cout << endl;

    cout << "Inorder Traversal : ";
    inOrderTraversal(rootNode);
    
    cout << endl;
    cout << endl;

    cout << "Postorder Traversal : ";
    postOrderTraversal(rootNode);

    cout << endl;

    cout << "Printing levelOrderTraversal : " << endl;
    levelOrderTraversal(rootNode);

    return 0;
}