#include<iostream>
#include<vector>

using namespace std;

void findlastoccurenceLTR(string str,char x,int index,int &ans){
    //base case
    if(index >= str.size()){
        return;
    }
    //ak case solution
    if(str[index] == x){
        ans = index;
    }
    //call
    findlastoccurenceLTR(str,x,index+1,ans);
}

void findlastoccurenceRTL(string str,char x,int index,int &ans){
    //base case
    if(index < 0){
        return;
    }
    //ak case solution
    if(str[index] == x){
        ans = index;
        return ;
    }
    //call
    findlastoccurenceRTL(str,x,index-1,ans);
}

void reverse_str(string &str,int s,int e){
    //base case
    if(s >= e) return;
    //ak case solve 
    swap(str[s],str[e]);

    //call
    reverse_str(str,s+1,e-1);
}

bool isPalindrome(string &s,int start,int end){
    //base case
    if(start  >= end) return true;//poora iterate ho chuka hai 
    //one case solution
    if(s[start] != s[end]){
        return false;
    }
    //RE call
    isPalindrome(s,start+1,end-1);
} 


void printsubarray_util(vector<int>&nums, int start ,int end){
    //base case
    if(end == nums.size()) return;
    //1 case solve
    for(int i=start;i<=end;i++)
    {
        
        cout << nums[i] << " ";
    }
    cout << endl;
    //RE
    printsubarray_util(nums,start,end+1);
}


void printsubarray(vector<int>&nums){

    for(int start=0;start<nums.size();start++)
    {
            int end = start;
            printsubarray_util(nums,start,end);
    }
}

int main(){
     
    // int ans = -1;
    // string str;
    // cout << "Enter the string:";
    // cin>>str;
    // char x ;
    // cout << "Enter the character which you wan't to find last occurence in str:";
    // cin >> x;
    
    // findlastoccurenceRTL(str,x,str.size()-1,ans);
    // cout <<"INDEX :" << ans;

    // string str ;
    // cout << "Enter the string :" ;
    // cin >> str;
    // int s = 0;
    // int e = str.size()-1; 
    // reverse_str(str,s,e);

    // cout << str;

//     string s ;
//     cout << "Enter string :" ;
//     cin>>s;

//    bool ans =  isPalindrome(s,0,s.size()-1);
//    if(ans){
//     cout << "string is a palindrome";
//    }
//    else{
//     cout<<"String is not a palindrome";
//    }

    vector<int> nums = {1,2,3,4,5};
    
    printsubarray(nums);


     
    return 0;
}