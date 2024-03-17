#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;


//this is the iterative approach for this question the RE approach is on leetcode.
int main() {
    vector<int>nums = {7,6,4,3,1};
    int minprice = INT_MAX;
    int maxprofit = INT_MIN;

    for(int i=0;i<nums.size();i++){
        if(nums[i] < minprice) {
            minprice = nums[i];
        }
        int todaysprofit = nums[i] - minprice;
        if(todaysprofit > maxprofit) {
            maxprofit = todaysprofit;
        }
    } 


    cout << maxprofit << endl;
  
    


    
    return 0;
}