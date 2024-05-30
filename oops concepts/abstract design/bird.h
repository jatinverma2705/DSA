#if !defined(BIRD_H)
#define BIRD_H
#include<iostream>

//Here Bird is an abstract class which means that bird class must contain one pure virtual fn.
class Bird{
    public:
        virtual void eat() = 0;
        virtual void fly() = 0;
        //classes that inherits this class
        //has to implement pure virtual fns.

};

class Sparrow: public Bird{
    public: 
        void eat(){
            std::cout << "Sparrow is eating" << std::endl;
        }
        void fly(){
            std::cout << "Sparrow is flying"<< std::endl;
        }
};

class Eagle: public Bird{
    public: 
        void eat(){
            std::cout << "Eagle is eating"<< std::endl;
        }
        void fly(){
            std::cout << "Eagle is flying"<< std::endl;
        }
};

#endif // BIRD_H


