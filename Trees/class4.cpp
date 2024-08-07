#include<iostream>
#include<queue>
#include<vector>

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

//This solution is taking O(n^2) complexity.
// int height(Node* root){
//     if(root == NULL)
//         return 0;

//     int lh = height(root->left);
//     int rh = height(root->right);
    
//     return max(lh,rh) + 1;
// }

// int diameter(Node* root){

//     if(root== NULL)  return 0;

//     int option1 = diameter(root->left);
//     int option2 = diameter(root->right);
//     int option3 = height(root->left) + height(root->right);

//     return max(option1, max(option2 , option3));

// }

// -> -> -> -> -> -> -> -> -> -> -> -> -> -> -> -> -> -> 

//Take a global variable
int D = 0;

//Through this approach we are traversing every node single time .
//therefore Time complexity -> O(n).
int height(Node* root){
    if(root == NULL)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);
    int currD = lh + rh;

    D = max(currD,D);
    
    return max(lh,rh) + 1;
}

int diameter(Node* root){

    height(root);
    return D;
}

//-> -> -> -> -> -> -> -> -> -> -> -> -> 
//fast way to calculate height balanced tree 
bool isBalanced = true;

/*int height(Node* root){
    if(root == NULL)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    if(isBalanced && abs(lh - rh) > 1){
        isBalanced = false;
    }
    
    return max(lh,rh) + 1;
}

bool isbalanced(Node* root){
    height(root);
    return isBalanced;
}
*/

//-> -> -> -> -> -> -> -> -> -> 
//Diagnol Traversal
void diagnolTraversal(Node* root, vector<int>&ans){
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        while(temp!= NULL){
            ans.push_back(temp->data);
            if(temp->left){
                q.push(temp->left);
            }
            temp = temp->right;
        }
    }

}

int main(){

    Node *root = createTree();
    // int heightofTree = height(root);
    // cout << "Height of Tree : " << heightofTree << endl;
    // int diameterofTree = diameter(root);
    // cout << "diameter of Tree: "<< diameterofTree << endl;
    //5 10 15 -1 -1 -1 25 35 -1 -1 40 -1 -1 
    vector<int>ans;

    diagnolTraversal(root,ans);

    for(auto i:ans){
        cout << i << " ";
    }
    return 0;
}