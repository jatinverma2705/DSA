#include<iostream>
#include<vector>
using namespace std;

int sieveoferatosthenes(int n){
    vector<bool>primes(n,true);
    primes[0] = primes[1] = false;
    int ans = 0;

    for(int i=2;i<n;i++){
        if(primes[i]){
            ans++;

            int j=2*i;
            while(j<n){
                primes[j] = false;
                j += i;
            }
        }
    }
    return ans;
}

int main(){
    int n;
    cout<<"enter the value of n:";
    cin >>n;
    if(n==0) return false;
    
    cout << "Count of prime numbers less than n:" <<  sieveoferatosthenes(n) << " ";


    return 0;
}