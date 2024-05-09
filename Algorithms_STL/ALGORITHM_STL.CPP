#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    vector<int> v;

    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(10);
    v.push_back(15);

    //STL FOR BINARY SEARCH->
    cout << binary_search(v.begin(),v.end(),3)<<endl;//returns true if found 3 in v , else false

    //STL FOR LOWER BOUND->
    cout<<lower_bound(v.begin(),v.end(),3)-v.begin()<<endl;

    //STL FOR UPPER BOUND->
    cout<<upper_bound(v.begin(),v.end(),3)-v.begin()<<endl;

    //stl for calculating max and min->
    int a = 10;
    int b=9;
    cout<<max(a,b)<<endl;
    cout<<min(a,b)<<endl;


    //STL FOR SWAP
    swap(a,b);
    cout << a<<" " <<b<<endl;


    //STL FOR REVERSING THE STRING
    string str = "ABCD";
    reverse(str.begin(),str.end());
    cout << "Reversed string->"<<str<<endl;

    //STL FOR ROTATING THE STRING
    rotate(v.begin(),v.begin()+1,v.end());
    for(int i:v){
        cout<<i<<" ";
    }

    return 0;
}