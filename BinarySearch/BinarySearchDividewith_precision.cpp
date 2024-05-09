#include<iostream>
using namespace std;

int divide(int dividend , int divisor){
    int start = 0;
    int end = dividend;
    int ans = -1;
    int quotient = start + (end-start)/2;
    while(start <= end) {
         
        if(divisor*quotient == dividend){
            return quotient;
        }
        else if(divisor*quotient <= dividend){
            ans = quotient;
            start = quotient+1;
        }
        else{
            end = quotient-1;
        }
        quotient = start + (end-start)/2;//mid updated

    }
    return ans;
}

double dividewithprecision(int dividend , int divisor) {
    double ans = divide(dividend,divisor);
    int precision = 5;
    double step = 0.1;
    for(int i=0 ; i< precision ; i++) 
    {
        double j = ans;
        while(j*divisor <= dividend){
            ans = j;
            j=j+step;
        }
        step = step/10;
    }
    return ans;
}

int main(){
    int dividend = 101;
    int divisor = 8;
    cout << dividewithprecision(dividend,divisor)<<endl;

    return 0;
}