//mergeSort for sorting the single array in place.
#include<iostream>
#include<vector>

using namespace std;

void inplace_mergesort(vector<int>&v,int start,int mid,int end){
    int total_len = end-start+1;
    int gap = total_len/2 + total_len%2 ;// gap = ceil(total_len/2) = total_len/2 + total_len %2

    while(gap > 0){
        int i = start;
        int j = start + gap;
        while(j <= end){
            if(v[i]>v[j]){
                swap(v[i],v[j]);
            }
            i++;j++;
        }
        gap = gap <= 1 ? 0 : (gap/2) + (gap%2) ;

    }
}

void mergeSort(vector<int>&v, int s,int e){
    if(s >= e) return;

    int mid = s + (e-s)/2;

    mergeSort(v,s,mid);
    mergeSort(v,mid+1,e);
    inplace_mergesort(v,s,mid,e);
}

int main(){
    vector<int>v = {7,1,3,4,8,9};
    mergeSort(v,0,v.size()-1);

    for(int i:v){
        cout <<i << " ";
    }

    return 0;
}