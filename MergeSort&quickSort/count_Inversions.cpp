#include<iostream>
#include<vector>
using namespace std;

//naive approach
int approach1(int arr[] , int n ){
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
               count++;
            }
        }
    }
    return count;
}

// Merge function used in the merge sort-based approach
int merge(vector<int>&arr,vector<int>&temp,int start ,int mid , int end) {
    int c = 0;
    int i=start,j=mid+1,k=start;
    //here i points to the starting element of the left portion/array
    //And j points to the starting element of the right portion/array

    while(i <= mid && j<=end){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            //agar arr[i] > arr[j]
            temp[k++] = arr[j++];
            
            //VIP STEP
            c += mid - i + 1;//// All elements from arr[i] to arr[mid] are inversions with arr[j]
        }
    }

    // Copy remaining elements from the left half
    while(i <= mid){
        temp[k++] = arr[i++];
    }

    // Copy remaining elements from the right half
    while(j <= end){
        temp[k++] = arr[j++];
    }

    // Copy back to the original array from temp array.
    while(start <= end){
        arr[start] = temp[start];
        start++;
    }
    //you can either do this->
    //  for (int m = start; m <= end; m++) {
    //     arr[m] = temp[m];
    // }

    return c;//return the number of inversions.
}

// Merge sort function used to count inversions
int mergeSort(vector<int>&arr,vector<int>&temp,int start,int end){

    //base case
    if(start >= end) return 0;

    int mid = start + (end-start)/2;
    int c = 0;

    // Recursively divide and merge
   c += mergeSort(arr,temp,start,mid);  // Count inversions in the left half
   c += mergeSort(arr,temp,mid+1,end); // Count inversions in the right half
   c += merge(arr,temp,start,mid,end);//count and merge
    return c;
}

int main() {
    // int arr[]= {8,4,2,1};
    // int n = 4;
    // int ans = approach1(arr,n);
    // cout << ans;

    vector<int>arr = {8,4,2,1}; //Input array
    vector<int>temp(arr.size(),0);//temporary array for merge sort
    int c  =  mergeSort(arr,temp,0,arr.size()-1);//Get the inversion count
    cout << c << endl;//Output the inversion count
    return 0;

}