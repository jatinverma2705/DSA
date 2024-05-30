#include<iostream>

using namespace std; 

//virtual basically kehta hai ki runtime par decision lenge
class Animal{
public:
    
    virtual void sound(){
        cout << "Animal making sound" << endl;
    }
    
};

class Dog : public Animal{
public:
    //overrride increases readability->good practice to write override
    //The override keyword is used in the derived class to explicitly indicate that a method is overriding a virtual method from the base class.
    void sound() override{
        cout << "Dog is barking " << endl;
    }
};

class Cat : public Animal{
public:
    void sound() override { 
        cout << "Cat Meowing" << endl;
    }
};

class Parrot : public Animal{
public:
    void sound() override{
        cout << "Parrot Mithu Mithu" << endl;
    }
};

//to access all the different sounds thru animal pointer
void sound(Animal *animal){
    animal->sound();//30th line is polymorphic(many forms.)
    //animal->sound is behaving as per required object allocated at runtime.
}

int main    (){

    // Animal *animal = new Animal;
    // animal->sound();

    // Animal *dog = new Dog();
    // dog->sound();

    // Dog *dg = new Dog();
    // dg->sound();

    Animal *animal = new Dog();
    sound(animal);

    animal = new Cat();
    sound(animal); 

    animal = new Parrot();
    sound(animal);
    
    return 0; 
}