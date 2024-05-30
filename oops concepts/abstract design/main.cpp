#include"bird.h"

using namespace std;

void birddoessomething(Bird *&bird){
    bird ->eat();
    bird ->fly();
    bird->eat();
}

int main(){
    //Bird b ; -> we can't do this because we are not able to make instances of abstract class.

    Bird *bird = new Sparrow();
    birddoessomething(bird);
    return 0;
}