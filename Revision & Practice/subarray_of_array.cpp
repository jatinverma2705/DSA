#include<iostream>
#include<vector>

using namespace std;

void printsubarrays(vector<int>a){
    for(int i=0;i<a.size();i++){
        for(int j=i;j<a.size();j++){
            for(int k=i;k<=j;k++){
                cout << a[k] << " ";
            }
            cout << endl;
        }
    }
}
/*this code gives o/p like this ->
1 
1 2        
1 2 3      
1 2 3 4    
1 2 3 4 5  
2 
2 3        
2 3 4      
2 3 4 5    
3 
3 4        
3 4 5      
4 
4 5        
5 */

int main() {
    
    vector<int>a = {1,2,3,4,5};

    printsubarrays(a);

    return 0;
}