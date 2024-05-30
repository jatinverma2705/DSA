#include<iostream>
#include<string>
#include<cstring>//This header file is used to use all the c inbuilt string functions!

using namespace std;


int main() {
   
    //creation of strings
    //string name;
    //taking input
    // cin >> name;
    // getline(cin,name); -> It says ki hame cin karana h name ke andar
    //printing the string  
    // cout << name << endl;
    // int index=0;
    //printing by loop method
    // while(name[index] != '\0'){
    //     cout << name[index];
    //     index++;
    // }
    // //finding the length of the string 
    // string name = "Jatin";
    // cout << name.length() << endl;
    // return 0;
    //checking whether the string is empty or not

    // string name = "";
    // cout << name.empty() << endl;
    // return 0;
    //using the  at(ith index) function
    // string str1 = "Jatin Verma";
    // cout << str1.at(1) << endl;
    //using the front and back function
    // string name = "Jatin" ;
    // cout << name.front() << endl;
    // cout << name.back() << endl;
    //Append function
    // string str1 = "Jatin";
    // string str2 = "Verma";
    // cout << str1.append(str2) << endl;
    // cout << str1 << endl;
    // cout << str2 << endl;

    //Erase function
    // string name = "Jatin is a good boy";
    // name.erase(6,4);
    // cout << name << endl;

    //Insert function
    // string name = "Jatin Verma";
    // string middle = " kumar";
   
    // cout <<  name.insert(5,middle) << endl;
//     string name = "Jatin Verma";
//    name.push_back('J');
//    cout << name << endl;
//    name.pop_back();
//    cout << name << endl;

//Find function
// string str1 = "Yaar tera superstar desi kallakar";
// string str2 = "desi katta";
// if(str1.find(str2) == string::npos){
//     //not found
//     cout << "Not found " << endl;
// }
// else{
//     cout << "Found " << endl;
// }

//Compare function
// string str1 = "Jatin Verma";
// string str2 = "Jatin Verma";
// if(str1.compare(str2) == 0) {
//     cout << "Equal string" <<endl;
// }
// else{
//     cout << "Not equal strings";
// }

//function for calculating substring
// string name = "Jatin is a good boy";
// cout << name.substr(5,14) << endl;
// string name = "KUMAR AND SONS";
// string name1 = "AND";

// cout << name.find(name1) << endl; -> It will return the index from which "And " is starting.
// char str[] = "Hello world";
// cout << str[0];
//We can't do like size(str) because str is a char array and the size fn only used with STL fnks like vector and strings.
// string str ;
// cin >> str;
// cout << str;
// char ch1[6] = "jatin";
// char ch2[6] = "verma";
// char ch3[12] = ch1 + ch2;
// cout << ch3;
// string init("this is init");
//     string add(" added now");
 
//     // Appending the string.
//     init.append(add);
 
//     cout << init << endl;
    // char init[] = "this is init";
    // char add[] = " added now";
 
    // // Concatenating the string.
    // strcat(init, add);
 
    // cout << init << endl;
//     string s;
//     s = s + 'a';
//     cout << s << endl;
//    s.push_back('jatin');
//    cout << s;
// string s("Sanboundry.");
// s.back() = '!';//basically this replaces the back element from. to !
// cout << s ;
// cout << s.substr(3).substr(4) << endl;
//the above statement basically do like substr(3).substr(4) -> It basically
//does -> addition substr(3+4)->substr(7);and goes upto the 7th index. and print onwards
// char str1[] = "Jatin";
// char str2[] = "Verma";
// // strcat(str1,str2);
// cout << "before concatenation :";
// cout << str1 << endl;
// cout << str2 << endl;
// cout << "afTER CONCATENATION" << endl;
// strcat(str1,str2);
// cout << str1 << endl;
// cout << str2 << endl;
// cout << strcat(str1,str2);
// int a =strlen("string");
// cout << a;
// char p[20];
// char s[] = "string";
// int length = strlen(s);
// for(int i=0;i<length;i++){
//     p[i] = s[length-i];
//     cout << p << endl;
// }
// char str[5] = "ABC";
// cout << str;

// char ch[100] ;
// cin >> ch;
// cout << sizeof(ch) ;
return 0;
}