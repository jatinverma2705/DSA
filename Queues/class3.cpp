#include<iostream>
#include<queue>
#include<deque>
#include<vector>

using namespace std;

//first non repeating element in a stream
void firstUniqChar(string &str) {
    queue<char>q;
    int freq[26] = {0};

    for(int i=0;i< str.length() ; i++) {
        //find the character 
        char ch = str[i];

        //freq updation
        freq[ch - 'a']++;

        //push the ch
        q.push(ch);


        //ans find out karo 
        while(!q.empty()){
            char frontCharacter = q.front();

            if(freq[frontCharacter - 'a'] > 1){
                //yeh ans nhi hai
                q.pop();
            }
            else{
                // == 1 vala case
                //yhi answer hai 
                cout << frontCharacter << "->";
                break;
            }
        }

        //Agar pop karne ke baad queue empty hogya 
        if(q.empty()){
            cout << "#" << "->";
        }
    }
}

//sum of minimum and maximum in window of size k 
int sumOfMaxMinWindowK(vector<int>nums , int k){

    //dq1->stores maximum of every window  ( Stores indexes)
    //dq2->stores min of every window   (Stores indexes)
    deque<int>dq1,dq2;
    int ans = 0;

    //process first window
    for(int i=0;i<k;i++){
        
        //dq1->stores elements in decreasing order
        //matlab dq1 ke front pe max element hoga.
        while(!dq1.empty() && nums[i] >= nums[dq1.back()]){
            dq1.pop_back();
        }

        //dq2->stores elements in increasing order
        //matlab dq2 ke front pe min element hoga.
        while(!dq2.empty() && nums[i] <= nums[dq2.back()]){
            dq2.pop_back();
        }

        dq1.push_back(i);
        dq2.push_back(i);
    }

    //Store ans;
    ans += nums[dq1.front()] + nums[dq2.front()];

    //process remaining windows
    for(int i=k;i<nums.size();i++){

        //removal -> both for dq1 and dq2 
        while(!dq1.empty() && i - dq1.front() >= k){
            dq1.pop_front();
        }

        while(!dq2.empty() && i - dq2.front() >= k){
            dq2.pop_front();
        }

        //current element ke liye chote element remove karne h
         while(!dq1.empty() && nums[i] >= nums[dq1.back()]){
            dq1.pop_back();
        }

        while(!dq2.empty() && nums[i] <= nums[dq2.back()]){
            dq2.pop_back();
        }

        //Inserting index so that we can checkout of window element
        dq1.push_back(i);
        dq2.push_back(i);

        //current window ka ans store karna hai 
        ans += nums[dq1.front()] + nums[dq2.front()];

    }

    return ans;
    
}

int main() {

    // Q1 -> First non repeating character in a stream.
    // string str = "ababc";
    
    // firstUniqChar(str);


    //Q2->Given an array of both positive and negative integers, the task is to compute sum of minimum and maximum elements of all sub-array of size k.

    vector<int>v = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;

    cout << sumOfMaxMinWindowK(v,k) << endl;
}