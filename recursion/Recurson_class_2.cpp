#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

void printArray(int *arr , int size , int index){
    //base case
    if(index >= size) return ;

    //processing
    cout << arr[index] << " ";
    //recursive call
    printArray(arr,size,index+1);

}

bool searchArray(int arr[] , int size ,int index, int target){
    //base case
    if(index >= size) return false;//iska matlab hame element nhi mila 

    //processing 
    if(arr[index] == target ){
        return true;
    }
    //recursive call
    searchArray(arr,size,index+1,target);

}//agar target present hoga array mai to return true else false!

void findMin(int arr[] , int size,int index,int &mini){
    if(index >= size) return ;
    
    mini = min(mini,arr[index]); 
    //recursive call
    findMin(arr,size,index+1,mini);

}

void findMax(int arr[] , int size,int index,int &maxi){
    if(index >= size) return ;
    
    maxi = max(maxi,arr[index]); 
    //recursive call 
    findMax(arr,size,index+1,maxi);

} 
//solve function pushes all the even numbers into vector ans from the array.
void solve(int arr[] , int size , int index ,vector<int>&ans){
    if(index >= size) return;

    if(arr[index]%2 == 0){
        ans.push_back(arr[index]);

    }
    //recursive call
    solve(arr,size,index+1,ans);

}

void do_double(int arr[] , int size , int index ){
    if(index >= size) return;

    arr[index] = 2*arr[index];

    //call
    do_double(arr,size,index+1);
}

int findinarray(int arr[] , int size,int index , int target){
    if(index >= size) return -1;

    if(arr[index] == target){
        return index;
    }

    findinarray(arr,size,index+1,target);
}

void findoccurences(int arr[] , int size , int index,int target,vector<int>&ans){
    if(index >= size) return ;
    if(arr[index] == target){
        ans.push_back(index);
    }
    findoccurences(arr,size,index+1,target,ans);

}

void printdigits(int num,vector<int>&ans) {
    if(num == 0) return ;
    
    int digit = num%10;
    //first call
    printdigits(num/10,ans);

    //processing
    ans.push_back(digit);
}

int main(){
    // int arr[] = {10,20,30,40,50};
    // int size = 5;
    // int index = 0;
    // int target = 30;
    // cout << searchArray(arr,size,index,target)<<endl;
    // printArray(arr,size,index);

    // int A[] = {9,2,1,4,5,6};
    // int size = 6;
    // int index  = 0;
    // // int mini = INT_MAX;//stores the min element
    // // findMin(A,size,index,mini);
    // // cout << "Minimum element :" << mini << endl;
    // int maxi = INT_MIN;  
    // findMax(A,size,index,maxi);
    // cout << "Maximum element :" << maxi << endl;  
    // int arr[] = {2,3,4,5,6,7,8,9,10,11};
    // int size = 11;
    // int index = 0;
    // vector<int> ans;
    // solve(arr,size,index,ans);//solve stores all even numbers from arr
    // for(int num:ans){
    //     cout << num <<" ";
    // }

    // int arr[] = {10,20,30,40,50};
    // int size = 5;
    // int index = 0;
    // vector<int> ans;
    // do_double(arr,size,index);
    // for(auto num:arr){
    //     cout<<num<<" ";
    // }
//     int arr[] = {10,20,30,40,50};
//     int size = 5;
//     int index = 0;
//     int target = 50;
//   cout <<  "Element found at index :" << findinarray(arr,size,index,target);

    // int arr[] = {10,50,50,30,50,30,20,30,40,50};
    // int size = 10;
    // int index = 0;
    // int target = 50;
    // vector<int>ans;//stores the index of all the occurences
    // findoccurences(arr,size,index,target,ans);

    // for(auto num:ans){
    //     cout << num << " ";
    // }
    int num = 4197;
    vector<int>ans;
    printdigits(num,ans);

    for(auto num : ans){
        cout << num <<" ";
    }

    return 0;
}
