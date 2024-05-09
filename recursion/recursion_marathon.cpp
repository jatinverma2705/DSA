#include<iostream>
#include<vector>

using namespace std;

int find_possible_dearrangements (int n){
    //base case
    if(n == 1){
        return 0;
    }
    if(n == 2) {
        return 1;
    }

    int ans = (n-1) * (find_possible_dearrangements(n-1) + find_possible_dearrangements(n-2));
    return ans;
}

int getpaintways(int n , int k ) {
    //base case
    if(n == 1) return k;

    if(n == 2) return k + k*(k-1);

    int ans = (k-1) * (getpaintways(n-1,k) + getpaintways(n-2,k));
    return ans;
}

int main() {
    //we are calculating possible number of dearrangement of n elements in an array

    // int n = 4 ;
    // cout << find_possible_dearrangements(n) << endl;

    //get paint ways option \ Painting fence algorithm
    int n = 3;
    int k = 3;
    int ans = getpaintways(n,k);
    cout << ans << endl;
    return 0;
}