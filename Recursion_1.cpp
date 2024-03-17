#include<iostream>

using namespace std;

int factorial(int n){
    //base case
    if(n==0 || n==1){
        return 1;
    }
    //recursive function 
    int ans = n * factorial(n-1);
    return ans;
    //processing
}

void counting(int n){
    //base condition
    if(n==1){
        cout<<1<<" ";
        return ;
    } 
    //processing
    cout << n<< " ";
    //recursive call
    counting(n-1);

}

int pow(int n){
    //base case
    if(n == 0) return 1;

    //recursive relation
    int ans = 2 * pow(n-1);
    return ans;
}

int fib(int n){
    if(n==0) return 0;
    if(n==1) return 1;

    int ans = fib(n-1) + fib(n-2);
    return ans;
}

int sum(int n){
    if(n==1) return 1;

    int ans = n + sum(n-1);
    return ans;
}

int BS(int A[],int k,int start,int end){
    if(start>end) return -1;

    int mid = start + (end-start)/2;
    if(A[mid] == k) return mid;
    else if(k>A[mid]){
        BS(A,k,mid+1,end);
    }
    else{
        BS(A,k,start,mid-1);

    }
    // return mid;
}

int main(){
    // cout<< factorial(5) << endl;
    // counting(5);
    // cout << pow(5);//give 2^5
    // cout << fib(7)<<endl;

    // cout << sum(5) << endl;
    // int A[10] = {10,20,30,40,50,60,70,80,90,100};
    // int k = 70;
    // BS(A,k,0,10);

    return 0;
}