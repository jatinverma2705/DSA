#include<iostream>
//T.C -> O(NLOGN)
using namespace std;
//merge sort has time complexity of O(nlogn).
void merge(int arr[],int s,int e){
    int mid = (s+e)/2;
    
    int lenLeft = mid - s + 1;//left array length
    int lenRight = e-mid;//right array length

    //create a left array and a right array dynamically
    int *left = new int[lenLeft];
    
    int *right = new int[lenRight];

    //copy values from the original array to the left array
    int k = s;
    //k -> starting index of the left array values in the original array
    for(int i=0;i<lenLeft;i++){
        left[i] = arr[k];
        k++;
    }
    
    //copy values from the original array to the right array
    k = mid+1;
    for(int i=0;i<lenRight;i++){
        right[i] = arr[k];
        k++;
    }

    //actual merge logic here
    //left array is already sorted
    //right array is already sorted
    int leftIndex = 0;
    int rightIndex = 0;

    //yhi par galti karte hai log
    int mainArrayIndex = s;

    while(leftIndex < lenLeft && rightIndex < lenRight){
        
        if(left[leftIndex] < right[rightIndex]){
            arr[mainArrayIndex] = left[leftIndex];
            mainArrayIndex ++;
            leftIndex++;
        }

       else{
            arr[mainArrayIndex] = right[rightIndex];
            mainArrayIndex ++;
            rightIndex++;
        }
    }

    //2 more cases 
    
    //case 1-> jab left array exhaust but right array me element abhi bhi bache hai
    while(rightIndex < lenRight){
        //bachi hui right ki values copy kar denge
        arr[mainArrayIndex] = right[rightIndex];
        mainArrayIndex++;
        rightIndex++;
    }

    //case2 -> jab right array exhaust but left array me element abhi bhi bache hai
    while(leftIndex < lenLeft) {
        //bachi hui left ki values copy kar denge
        arr[mainArrayIndex] = left[leftIndex];
        mainArrayIndex++;
        leftIndex++;
    }

    //1 more step pending
    //whenever you create dynamic memory access make sure to delete it
    delete[] left;
    delete[] right;
}
    
void mergesort(int arr[] , int s,int e){
    //base case
   if(s>=e){
    return;
   }

    //break
    int mid = (s+e)/2;
    //recursive call for left array
    mergesort(arr,s,mid);
    
    //recursive call for right array
    mergesort(arr,mid+1,e);

    //merge two sorted arrays
    merge(arr,s,e); // hamne isme original array pass kia hai uska starting index pass kia h and uska ending index pass kia h
}

int main() {
    int arr[] = {2,1,6,9,8,5};
    int size = 6;
    int s = 0;
    int e = size-1;

     
    cout << "Before merge sort : " <<endl;
    for(int i=0;i<size;i++) {
        cout << arr[i] <<" ";
    }

    cout << endl;
    mergesort(arr,s,e);
    cout << "After merge sort :" <<endl;
    for(int i=0;i<size;i++) {
        cout << arr[i] <<" ";
    }
 return 0;
}