#include<iostream>

using namespace std;


void quickSort(int arr[] , int s, int e) {
    //base case-> don't forget
    if(s >= e) return;
    //two pointers i and j are placed to the array. i -> start - 1 .   j->start
    int i=s-1;
    int j=s;
    int pivot = e;//always point the last element of the array as pivot element
    //Now we have to place the pivot element to partition the array properly so that to the right of the pivot element all elements should be greater than pivot and left elements should be less than pivot.
    while(j < pivot){
        if(arr[j] < arr[pivot]){
            i++;
            swap(arr[i],arr[j]);
        }
        j++;
    }
    
    //now we have to increment i-> i++ so that we can place the pivot to the right position
    i++;
    swap(arr[i],arr[pivot]);//now pivot element is placed at right position. (matlab uski sahi positiion par place hogya hai pivot)
    //Now we also have to place the left array pivot and right array pivot to its right position.

    //call for left array and right array
    quickSort(arr,s,i-1); // left call
    quickSort(arr,i+1,e);//right call
}
 

int main() {
    int a[] = {2,1,3,4,6,7,5,8};
    int size = 8;
    int s = 0;
    int e = size-1;
    
    quickSort(a,s,e);


    //ye algorithm bhi actual array mein hi changes karti hai !
    for(int i:a){
        cout << i << " ";
    }

    return 0;
}