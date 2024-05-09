//Q-> You are given with two sorted arrays you have to merge them.
#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int>a,vector<int>b){ 
    int n = a.size();
    int m = b.size();
    int total_len = n + m;
    int gap = (total_len/2) + (total_len%2);
    while(gap > 0) {
        int i=0, j=gap;
        while(j < total_len){
            /*comparing elements in first array-> if a[i]>b[j] swap their values*/
            if(j < n && a[i]>a[j]) swap(a[i],a[j]);

            /*comparing elements in both arrays*/
            else if(j >= n && i<n && a[i]>b[j-n]) swap(a[i],b[j-n]);

            /*comparing elements in second array*/
            else if(j >= n && i >= n && b[i-n]>b[j-n]) swap(b[i-n],b[j-n]);

            j++;
            i++;
        }

        gap = gap <= 1 ? 0 : (gap/2) + (gap % 2);
    }
}

int main() {
    vector<int> a = {1, 5, 9, 10, 15}; // First sorted array
    vector<int> b = {2, 3, 8, 13, 20}; // Second sorted array 

    merge(a,b);

    for(auto i:a){
        cout << i << " ";
    }
   
    
    return 0;
}