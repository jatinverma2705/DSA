#include<iostream>
#include<vector>
using namespace std;

int mysqrt(int n) {
    int s = 0;
    int e = n;
    int ans = -1;
    int mid = s+ (e-s)/2;
    while(s <= e) {
        if(mid*mid <= n) {
            ans = mid;
            //right me jaege
            s = mid + 1;
        }
        else{
            //left me jaege
            e = mid - 1;
        }
        //update mid
        mid = s + (e-s)/2;
    }
    return ans;
}

double mysqrtprecision(int n) {
    double sqrt = mysqrt(n);

    double step = 0.1;
    int precision = 5;
    for(int i=0;i<precision;i++)
    {
        double j = sqrt;
        while(j*j <= n){
              sqrt = j;
            j = j+step;
        }
        step = step/10;
    }
    return sqrt;
}

int main() {
    //To find the  square root of the number with precision ;
    int n = 63;
    cout << mysqrtprecision(n) << endl;


    return 0;
}
