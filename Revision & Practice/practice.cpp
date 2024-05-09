#include<iostream>
#include<vector>

using namespace std;

int fib(int n){
    //base case
    if(n == 0) return 0;
    if(n == 1) return 1;

    //call
    int ans = fib(n-1) + fib(n-2);
    
    return ans;
}

int sqrt(int n){
    int start = 0;
    int end = n;
    int mid = start + (end-start)/2;
    int ans =  0;
    while(start <= end) {
        if((mid*mid) == n) return mid;
        if((mid*mid) < n) {
            ans = mid;
            start = mid +1;
        }
        else{
            end = mid - 1;
        }
        mid = (start+end)/2;
    }
    return ans;
}

int binarySearchDivide(int dividend , int quotient) {
    int s = 0;
    int e = dividend;
    int ans = -1;
    int mid = s + (e-s)/2;
    while(s <= e) {
        if(mid*quotient == dividend) {
            return mid;
        }
        else if(mid*quotient < dividend) {
            ans = mid;
            s= mid +1;
        }
        else{
            e = mid -1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main() {

   
    // cout << fib(5);
    // cout << "here i am starting my first proggram and lets go" << endl;
    // int arr[3] = {100,200,300};
    // int size = 3;
    // for(int i=0; i<size ; i++) {
    //     for(int j=i+1;j<size;j++){
    //         cout << arr[i] << "," << arr[j] << endl ;
    //     }
    // }

    // vector<char> ch (5);
    // ch.push_back('a');
    // ch.push_back('b');
    // ch.push_back('c');
    // ch.push_back('d');

    // for(auto i : ch){
    //     cout << i  << endl;
    // }
    // cout << "Running" << endl ;
    // cout << sqrt(49) << endl;
    // vector<vector<int>>v = {{1,2,3},{2,3,10,4},{4,3,9},{20,23,30}};
    // cout << v.size() << endl;
    // cout << v[1].size() << endl;
    int ans = binarySearchDivide(80,7);
    cout << ans << endl;
    return 0;
}