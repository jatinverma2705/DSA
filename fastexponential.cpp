#include<iostream>
using namespace std;

int slowexponentiation(int a,int b){
    int ans = 1;
    for(int i=0;i<b;i++){
        ans *= a;
    }
    return ans;
}

int fastexponentiation(int a,int b){
    int ans = 1;
    while(b>0){
        if(b & 1){
            //ODD
            ans = ans*a;
        }
        a=a*a;
        b = b>>1;
    }
    return ans;
}

int main(){
    int a = 5;
    int b = 4;
    cout<<fastexponentiation(a,b) << endl;
    
    return 0;

}