//question is to find the index of the odd occuring element from the array in which all the elements are present in pairs and we have to find out the index of that single odd element through binary Search.
#include <iostream>
using namespace std; 

int FindOddOccuringElement(int arr[] , int n) {
  int s = 0;
  int e = n-1;
  int mid = s + (e-s)/2;
  while(s <= e) {
    //single element vala case
    if(s == e) {
      return s;
    }
    if(mid & 1) {//Odd vala case
      if((mid-1)>=0 && arr[mid] == arr[mid-1]){
        s = mid + 1;
      }
      else{
        e = mid - 1;
      }
    }
    else{ //IMP -> Even index vala case 
      if((mid+1 < n) && arr[mid] == arr[mid+1]){
        //left me khade ho right me jao 
        s = mid + 2;
      }
      else{
        //catch
        e = mid;
      }
      }
    mid = s + (e-s)/2;
    }
  
return -1;
}

int main() {
  int arr[] = {10,10,2,2,5,5,1,5,5,20,20,11,11,10,10};
  int n = 15;

  int ansIndex = FindOddOccuringElement(arr,n);
  cout << "The odd occuring element is " << arr[ansIndex] << endl;
}