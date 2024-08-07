#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>

using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int val):val(val),left(NULL),right(NULL) {}
};


    //it returns the root TreeNode of the created tree
    TreeNode* createTree(){

    cout << "Enter the value : ";
    int data;
    cin >> data;

    //agar data -1 hai matlab TreeNode ko null point kara do matlab koi TreeNode mat lagao
    if(data == -1){
        return NULL;
    }

    //Step1 : make a new TreeNode / root TreeNode
    TreeNode * root = new TreeNode(data);

    //Step2: Make left subtree
    cout << root->val << " left TreeNode val process" << endl;
    root->left = createTree();

    //Step3: Make right subtree
    cout << root->val << " right TreeNode val process " << endl;
    root->right = createTree();

    return root;

    }

    void levelOrderTraversal(TreeNode * root){

    queue<TreeNode*>q;
    q.push(root);

    //Here null acts as a marker kabhi bhi null milega to next line print kar dunga
    q.push(NULL);

    //asli traversal start krte hai
    while(!q.empty()){
        TreeNode *front = q.front();
        q.pop();

        if(front == NULL){
            cout << endl;
            
            if(!q.empty()){
            q.push(NULL);
            }
        }

        else{
            //valid TreeNode
            cout << front->val << " ";

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

//Main point in this code is pass PreOrderIndex variable  as pass by reference
TreeNode* constructTreeusingPreOrderandPostOrder(vector<int>& preOrder, vector<int>& inOrder,int &preOrderIndex , int inOrderStartIndex, int inOrderEndIndex, int size,unordered_map<int,int>&inORderMapping){
    //base case
    if(preOrderIndex >= size || inOrderStartIndex > inOrderEndIndex){
        return NULL;
    }

    //1 case main solve karta hu
    //preorder mein jis bhi index par khade ho uske liye TreeNode create kro.
    int element = preOrder[preOrderIndex];
    preOrderIndex ++;

    //making of root TreeNode
    TreeNode* root = new TreeNode(element);
    //element search karna padega inorder mein ->index
    int position  = inORderMapping.at(element);

    // baaki recursion sambhal lega
    root->left = constructTreeusingPreOrderandPostOrder(preOrder,inOrder,preOrderIndex,inOrderStartIndex,position-1,size,inORderMapping);
    root->right = constructTreeusingPreOrderandPostOrder(preOrder,inOrder,preOrderIndex,position+1,inOrderEndIndex,size,inORderMapping);

    return root;
}

int height(TreeNode* root){

    //base case
    if(root == NULL) return 0;

    //call for left subtree
    int leftHeight = height(root->left);
    //call for right subtree
    int rightHeight = height(root->right);

    int finalAns = max(leftHeight , rightHeight) + 1;

    return finalAns;
    
}

int diameter(TreeNode* root){
    
    if(root == NULL){
        return 0;
    }

    int option1 = diameter(root->left);
    int option2 = diameter(root->right);
    int option3 = height(root->left) + height(root->right);

    int diameter = max(option1 , max(option2 , option3));
    return diameter;
}

int main(){
     
    // TreeNode* root = createTree();

    //finding height
    // int heightt = height(root);
    // cout << "Height of above tree is : " << heightt << endl;

    // int diameterr = diameter(root);
    // cout << "Diameter : " << diameterr << endl; 


    vector<int> preOrder = {2,8,10,6,4,12};
    vector<int> inOrder = {10,8,6,2,4,12};
    int size = inOrder.size();
    int preOrderIndex = 0;
    int inOrderStartIndex = 0;
    int inOrderEndIndex = size -1 ;

    //element to index mapping 
    unordered_map<int,int> inORderMapping;
    for(int i=0;i<inOrder.size();i++){
        int index = i;
        int element = inOrder[i];
        inORderMapping[element] = index;
    }

    TreeNode* root = constructTreeusingPreOrderandPostOrder(preOrder,inOrder,preOrderIndex,inOrderStartIndex,inOrderEndIndex,size,inORderMapping);
    levelOrderTraversal(root);

    return 0;
}
