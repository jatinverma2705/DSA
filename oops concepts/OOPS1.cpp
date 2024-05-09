#include<iostream>
#include<vector>
#include<string>

using namespace std;

// Every class has a private pointer invisible (*this) which points to at a  particular object.
//  By default class is private.
//Constructor is the only function in cpp which has no return type.
//ctor -> constructor
class Student{
//ACCESS modifiers -> They define scope of access.(public & private).

 private: 
    string gf;

 public:
    int id;
    int age;
    string name;
    int nos;
    bool present;

    /*Default ctor->
    Student(){

    }*/

    //ctor
    //ctor is always a public figure.
    Student(){
        cout << "student ctor called" << endl;
    }

    //parameterized ctor
    Student(int _id,int _age,string _name,int _nos,bool _present ){
        id = _id;
        age = _age;
        name = _name;
        nos = _nos;
        present = _present;

        cout << "Student parameterized ctor called" << endl;
    }

    void study(){
        cout << "Studying" << endl;
    }

    void sleep(){
        cout << "Sleeping" << endl;
    }

    void bunk(){
        cout << "Bunking" << endl;  
    }

private:
    void gfchatting(){
        cout << "Chatting" << endl;
    }

};

int main() {
    
    // cout << sizeof(Student) << endl;//An empty class has size of 1Byte. -> Smallest addressable space.


    Student s1;
    // s1.name = "Jatin";
    // s1.id = 1;
    // s1.nos = 5;
    // s1.present = 0;
    // cout << s1.age << endl; //Due to default ctor , whenever a instance is called like student s1 in our case , it by default assign values , values assign kar deta h (garbage value) 

    
    // Student s2;
    // s2.name = "Anmol";
    // s2.id = 1;
    // s2.nos = 5;
    // s2.present = 0;

    Student s2(1,8,"jatin",5,1);
    cout << s2.name << endl;
    cout << s2.id << endl;
    cout << s2.nos << endl;

    //Storing the class on the heap memory.
    //s3 is a pointer that created in stack that points to the memory block named student that is located in the Heap.
    //For accessing the heap based class data members.
    //Syntax -> (A) s3->property  (B) (*s3).property
    Student *s3 = new Student(3,6,"chintu",7,0);
    cout << s3->name << endl;
    cout << (*s3).name << endl;

    //make sure to delete memory (Memory leak)
    delete s3;


    return 0;
}