#include<iostream>


using namespace std;

class Student{
    string gf;
public:
    int id;
    int age; 
    bool present;
    string name;
    int nos;
    int *v;

    void study(){
        cout << "Studying" << endl;
    }

    void sleep(){
        cout << "Sleeping" << endl;
    }

    void bunk(){
        cout << "Bunking" << endl;  
    }
    
    //Getter | Setter functions -> used for accessing and setting the private members.
    void setGfName(string gf){
        this->gf = gf;
    }

    string getGfName(){
        return gf;
    }


   
    Student(){
        cout << "student ctor called" << endl;
    }
    
    //Parameterized ctor
    /* Student(int _id,int _age,bool _present,string _name,int _nos){
        id = _id;
        age = _age;
        present = _present;
        name = _name;
        nos = _nos;

        cout << "parameterized ctor called" << endl;
    } */

    Student(int id,int age,bool present,string name,int nos){
        this->id = id;
        this->age = age;
        this->present = present;
        this->name = name;
        this->nos = nos;
        this->v = new int(10);
    
        cout << "Parameterized ctor called" << endl;
    }

    //copy ctor
    // We declared (const Student &srcobj) const to prevent it from modifying the srcobj .
    Student(const Student &srcobj){
        this->name = srcobj.name;
        this->id = srcobj.id;
        this->gf = srcobj.gf;
        this->present = srcobj.present;
        this->nos = srcobj.nos;
        this->age = srcobj.age;
       

        cout << "Student copy ctor called" << endl;

    }

    //Destructor
    ~Student(){
        delete v;
        cout << "Student destructor called" << endl;
    }

    
};

int main() {

    Student s1(1, 12, 1, "Chota Bheem", 1);
    Student s2(s1);
    // Student s2 = s1;
    //Student s2(s1);
    // s2 = s1;
    cout << s1.name << endl;
    cout << s2.name << endl;

    s1.setGfName("Indumati");

    cout << s1.getGfName() << endl;

   return 0;
}