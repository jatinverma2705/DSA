#include<iostream>

using namespace std;

bool checksorted(int arr[] , int size , int index ){
    //base case
    if(index >= size) return true;//matlab array poori sorted hai

    //processing 
    if(arr[index] > arr[index-1]){
        //ab aage check karna padega
        //recursion call
        bool aagekaans = checksorted(arr,size,index+1);
        return aagekaans;
    }
    else{
        return false;
    }
   
}

int binarysearch(int arr[], int s , int e ,int target){
    //base case
    if(s > e){
        return -1;
    }
    int mid  = s+ (e-s)/2;

    if(arr[mid] == target){
        return mid;
    }
    if(arr[mid] < target){
        return binarysearch(arr,mid+1,e,target);
    }
    else{
        return binarysearch(arr,s,mid-1,target);
    }
   
}

//you have to print all possible subsequences for str string
void findsubsequences(string str,string output,int index){
    //base case
    if(index >= str.length()){
        //agar meri index ka size str ki length ke equal ya usse jyada ho gya hai matlab mera answer ouput string me aa gya hai to print kar denge
        cout << "->" << output << endl;
        return;
    }

    char ch = str[index]; // current character jispar ham khade hain

    //include
    output.push_back(ch);
    findsubsequences(str,output,index+1);
    //exclude
    //hamne push kar rakha h character output string mein pehle pop karna padega
    output.pop_back();
    findsubsequences(str,output,index+1);
}

int main(){
//     int A[] = {10,20,30,40,50,60};
//     int n = 6;
//     int index  = 1;//index = 1 because agar index 0 se initialize karte to outof bound chala jaata  arr[index-1].

//    bool issorted =  checksorted(A,n,index);
//    if(issorted){
//     cout<<"Array is sorted" << endl;
//    }
//    else{
//     cout << "Array is not sorted"<<endl;
//    }

//     int arr[] = {10,20,30,40,50,60};
//     int start = 0;
//     int end = 5;
//     int target = 60;
//   cout << "Element found at index :"<<  binarysearch(arr,start,end,target);
        string str = "abc";
        string output = "";
        int index = 0;
        findsubsequences(str,output,index);

    return 0;
}