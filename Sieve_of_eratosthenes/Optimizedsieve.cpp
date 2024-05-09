#include<iostream>
#include<vector>

using namespace std;

vector<bool>Sieve(int n){
    vector<bool>sieve(n+1,true);

    sieve[0]=sieve[1]=false;

    for(int i=2;i*i<=n;i++){//2nd optimization->less than route n tak!
        if(sieve[i]){
           // int j=2*i;
           int j=i*i;//Optimization 1;
           //first unmarked number would be i*i,because others have been 
           //marked by 2 to (i-1);
            while(j<=n){
                sieve[j] = false;
                 j += i;
            }
        }
    }
    return sieve;
}

//Here we are printing the prime numbers <=n
int main(){
    int a = 10;
    vector<bool>sieve = Sieve(25);
    for(int i=0;i<=25;i++){
        if(sieve[i]){
            cout << i <<" ";
        }
    }
    return 0;
}