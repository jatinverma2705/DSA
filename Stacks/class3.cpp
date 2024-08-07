#include<iostream>
#include<stack>
#include<vector>

using namespace std;

vector<int> nextSmallerElement(int *arr , int size ,vector<int>&ans){
    stack<int>st;

    st.push(-1);

    for(int i=size-1;i>=0;i--){
        
        int curr = arr[i];
        while(st.top() >= curr){
            st.pop(); 
        }
        //ans mil gya hoga yha

        ans[i] = st.top();
    
        st.push(curr);
    }
    return ans;
}   

vector<int> prevSmallerElement(int *arr , int size ,vector<int>&ans){
    stack<int>st;
    
    st.push(-1);

    for(int i=0;i<size;i++){
        
        int curr = arr[i];
        while(st.top() >= curr){
            st.pop();
        }
        //ans mil gya hoga yha 

        ans[i] = st.top();

        st.push(curr);
    }
    return ans;
} 

int main() {

    int arr[] = {8,4,6,2,3};
    int size = 5;

    vector<int>next(size);
    
    next =  nextSmallerElement(arr,size,next);

    cout << "next:";
    for(auto i:next){
        cout << i <<" ";
    }

    cout << endl;

    vector<int>prev(size);  

    prev = prevSmallerElement(arr,size,prev);

    cout << "prev :";
    for(int i : prev){
        cout << i << " " ;
    }

    return 0;
}