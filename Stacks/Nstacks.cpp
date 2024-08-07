#include<iostream>

using namespace std;

class NStacks{
    
    int *A;
    int *top;
    int *next;
    int n;  //no. of stacks 
    int size;   //size of main array
    int freespot; //tells freespace in main array.

    public:

        NStacks(int _n, int _s):n(_n), size(_s) {
            A = new int[size];
            top = new int[n];
            next = new int[size];

            //Initialize free spot;
            freespot = 0;

            //Insert -1 in all the top array.
            for(int i=0;i<n;i++){
                top[i] = -1;
            }
            
            //Inserting values in next array.
            for(int i=0;i<size;i++){
                next[i] = i+1;
            }

            //update last index to -1.
            next[size-1] = -1;

        }

        //m->denoting konse stack me push karna h.
        bool push(int x,int m){

            //check for overflow.
            if(freespot == -1){
                return false;
            }
            
            //find index
            int index = freespot;

            //update freespot
            freespot = next[index];

            //insert element to an array
           A[index] = x;

           //update next;
           next[index] = top[m-1];

            //update top
            top[m-1] = index;

            return true;
        }

        int pop(int m){

            //check underflow condition
            if(top[m-1] == -1){
                return -1;
            }

            int index = top[m-1];

            top[m-1] = next[index];

            next[index] = freespot;

            freespot = index;

            return A[index];
        }

        ~NStacks(){
            delete[] A;
            delete[] top;
            delete[] next;
        }


};

int main(){

    NStacks s(3,6);
    cout << s.push(10,1) << endl;
    cout << s.pop(1) << endl;

}