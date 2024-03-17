#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;

int findlength(char ch[] , int size) {
    int length=0;
    int index=0;
    while(ch[index] != '\0') {
        length++;
        index ++;
    }
    return length;
}

void reverseString(char ch[] , int size) {
    int i=0;
    int j= size-1;
    while(i <= j) {
        swap(ch[i] , ch[j]);
        i++;
        j--;
    }

}

void converttoUppercase(char ch[] , int n) {
    int index = 0;
    while(ch[index] != '\0') {
        int currentcharacter = ch[index];
        if(currentcharacter >='a' && currentcharacter <= 'z') {
            ch[index] = currentcharacter - 'a' + 'A';
        }
        index++;
    }
}
void replacesymboltospace(char ch[] , int size) {
    int index=  0;
    while(ch[index] != '\0')  {
        if(ch[index] == '@'){
            ch[index]=' ';
        }
        index++;
    }
}

bool checkPalindrome(char ch[] , int n) {
    int i=0;
    int j =n-1;
    while(i <= j ) {
        if(ch[i] == ch[j]) {
            i++;
            j--;
        }
        else{
            return false;
        }
    }
    return true;

}

int main() {
    // //int array
    // int arr[10];
    // //for taking input in integer array
    // for(int i=0;i<10;i++) {
    //     cin>>arr[i] ;
    // }
    // //for printing the integer array
    // for(int i=0;i<10;i++) {
    //     cout << arr[i] ;
    // }

    // char ch[100];
    //for taking input 
    // cin >> ch;


    //for taking output
    // cout <<"Printing the value of ch:" <<  ch;

    //for taking complete output
    // cin.getline(ch,100);

    //in case of char arrays-> getline(name of char array,size of char array).
    // cin.getline(ch,100);
    // int len = findlength(ch,100);


    // cout << "Printing the length of string  :" << strlen(ch) << endl;
    // char ch[100];
    // cin >> ch;
    // // int len = strlen(ch);
    // reverseString(ch,len);
    // strrev(ch);// Utility function used to reverse a string

    // cout << ch << endl;
    // char ch[100];
    // cin.getline(ch,100);
    // converttoUppercase(ch,100);
    // cout << "Printing the uppercase string:" << ch << endl;

    // replacesymboltospace(ch,100);
    // cout << ch << endl;
    // int len = findlength(ch,100);
    // bool ispalindrome = checkPalindrome(ch,len);
    // if(ispalindrome) {
    //     cout << "valid palindrome" << endl;
    // }
    // else{
    //     cout << "Invalid palindrome" << endl;
    // }
    // string name = "jatin";

    //in case of string getline function() -> getline(cin,name of string)!

    // int length = name.length();
    // cout << length;
    // string str1 = "jatin verma is good boy";
    // string str2 = "verma";
    // cout << endl;
    // cout << str1 << endl ;
    // cout << str1.erase(5,10);
    // cout << str1 ;

    // float i = 3.9;
    
    // cout << floor(i) << endl ;
    // cout << sqrt(2);//ye pura decimal ke saath and deta h 
    //one more way of addition
    // string str1 = "Jatin ";
    // string str2 = "Verma";
    // cout << str1+str2;
    return 0;
}