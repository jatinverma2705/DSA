#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool isPossibleSolution(vector<long long int>trees , long long int m , long long int mid) {
     long long int woodcollected = 0;
     for(int i=0;i<trees.size();i++) {
        if(trees[i] > mid){
            woodcollected = woodcollected+ trees[i] - mid;
        }
     }
     return woodcollected >= m;
}

long long int maxsawbladeheight(vector<long long int>trees , long long int m) {
    long long int start,end;
    start = 0;
    end = *max_element(trees.begin(),trees.end());
    long long int ans = -1;

    while(start <= end) {
        //yha par sawblade ki height jo hame nikalni hai vo mid hai 
        long long int mid = start + (end-start)/2;
        if(isPossibleSolution(trees,m,mid)){
            ans = mid;
            start = mid + 1;
        }
        else{
            end = mid-1;
        }
    }
    return ans;
}

int main() {
    long long int n,m;
    cin>>n>>m;
    vector<long long int> trees;
    while(n--){
      long long int height;
      cin >> height;
      trees.push_back(height);
    }


    cout << maxsawbladeheight(trees,m) << endl;
   

    return 0;
}