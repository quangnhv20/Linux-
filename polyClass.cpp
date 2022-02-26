#include <iostream>
using namespace std;

class Animal{
public:
        void sound(){
            cout << "animal's sound" << endl;
        }
};

class Dog : public Animal{
public:
        void sound(){
            cout << "gow gow" << endl;
        }
};

class Cat: public Animal{
public:
        void sound(){
            cout << "mew mew" << endl;
        }
};

int main(){
    Animal newAnimal;
    Dog newDog;
    Cat newCat;

    newAnimal.sound();
    newDog.sound();
    newCat.sound();
    return 0;
}
