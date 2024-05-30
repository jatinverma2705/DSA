#include<iostream>

using namespace std;
#define PI 3.14 //It is a good practice to declare macro name in Capital FOR easy code readability.
#define MAXX(x , y) (x > y? x:y)


float circleArea(float r){
    return PI * r * r;
}


float cirleparameter(float r){
    return 2 * PI * r;
}

void fun(){
    int x = 6;
    int b = 3;
    int z = MAXX(x,b);
    cout << "max value : " << z << endl;
}

int main(){
    // float ans = circleArea(2.4);
    // cout << ans << endl;

    // float ans = cirleparameter(2.4);
    // cout << ans << endl;

    fun();

    return 0;
}