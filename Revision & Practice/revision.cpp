#include<iostream>
#include<limits.h>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int Binarysearch(vector<int>&arr , int s ,int e , int target){
    int mid = s + (e-s)/2;
   while(s <= e){
    if(arr[mid] == target) return mid;
    else if (target > arr[mid]){
        s = mid+1;
    }
    else{
        e = mid-1;
    }
    mid = s + (e-s)/2;
   }
   return -1;
}

int Exponentialsearch(vector<int>& arr , int n , int target){
    if(arr[0] == target ) return 0;
    int i = 1;
    while(i<n && arr[i] <= target){
        i=i*2;
    }
    return Binarysearch(arr,i/2,min(i,n-1),target);
}

void rotatebyK(vector<int>& nums,int k){
    int n = nums.size();
    vector<int>ans;
    for(int i=0;i<n;i++){
        int newIndex = (i+k)%n;
        ans[newIndex] = nums[i];
    }
    nums=ans;

  for(int i=0;i<n;i++){
    cout<<nums[i]<<" ";
  }
}
int findoddoccuringelement(int arr[],int n){
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;
    while(s<=e) {
        if(s == e){
            return s;
        }
        if(mid & 1){
            //odd index par khada hoon
            if(arr[mid] == arr[mid-1]){
                //left par khada hoon
                //right me jana h
                s = mid +1;

            }
            else{
                e = mid-1;

            }
            
        }
        else{
            if(arr[mid] == arr[mid+1]){
                //right me jana hai 
                s = mid + 2;
            }
            else{
                e = mid;
            }
        }
        mid = s + (e-s)/2;
    }
    return -1;
}

int kdiffpairs(vector<int>& nums,int k){
    sort(nums.begin(),nums.end());
    set<pair<int,int>> ans;
    int i=0,j=1;
    while(j < nums.size()){
        int difference = nums[j] - nums[i];
        
        if(difference == k){
           ans.insert({nums[i],nums[j]});
            i++;j++;
        }
        else if(difference > k){i++;}
        else{//agar difference chota hai to j ko aage badhaege
            j++;
        }
         if(i == j){
            j++;
        }
       
    }
    return ans.size();

}
int main() {
    // int arr[20];
    // int N ;
    // cin >>N;
    // while(N > 0) {
    //     int onesplace = N%10;
    //     arr[N] = onesplace;
    //     N = N/10;
    // }

    // for(int i=N-1;i>=0;i++){
    //     cout << arr[i] << " " ;
    // }
    // int arr[] = {20,10,50,5,1,2,3,1};
    // int n = 8;
    // int minAns = INT_MAX;
    // for(int i =0;i<n;i++){
    //     if(arr[i] < minAns){
    //         minAns = arr[i];
    //     }
    // }
    // cout << "minimum element is :" << minAns << endl;
//     int arr[] = {20,-10,-20,40,50};
//     int n = 5;
//     //shift negative numbers to one side
//    int j=0;
//    for(int index=0;index<n;index++){
//     if(arr[index] < 0){
//         swap(arr[index],arr[j]);
//         j++;
//     }
//    }
    
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
    // int nums[] = {2,0,2,1,1,0};
    // int n = 6;
    // int left = 0;
    // int right = n-1;
    // int index=0;
    // while(index <= right){
    //     if(nums[index] == 2){
    //         swap(nums[index],nums[right]);
    //         right--;//catch
    //     }
    //     else if(nums[index] == 0){
    //         swap(nums[index] , nums[left]);
    //         index++;
    //         left++;
    //     }
    //     else{
    //         index++;
    //     }
    // }
    // for(int i=0;i<n;i++){
    //     cout<<nums[i]<<" ";
    // }
    // vector<int>nums;
    // nums.push_back(1);
    // nums.push_back(2);
    // nums.push_back(3);
    // nums.push_back(4);
    // nums.push_back(5);
    // nums.push_back(6);
    // nums.push_back(7);
    // int k = 3;
    // rotatebyK(nums,k);

    //find the odd occuring element in an array jisme even no. pairs me exist kar rahe hai
    // int arr[] = {10,10,2,2,5,5,1,5,5,20,20,11,11,10,10};
    // int n = 15;

    // int ans = findoddoccuringelement(arr,n);
    // cout << arr[ans] << endl;

    //k diff pair question
    // vector<int>nums = {1,1,1,1,1};
    // int k = 0;
    // int numberofkdiffpairs = kdiffpairs(nums,k);
    // cout << numberofkdiffpairs << endl;

    //Exponential search
//    int arr[] = {3,4,5,6,11,13,14,15,56,70};//sorted hona chahiye
//    int n = sizeof(arr)/sizeof(int);
//    int target = 13;

//    Exponentialsearch(arr,n,target);
   
    return 0;
}