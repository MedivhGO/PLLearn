#include <iostream>
#include <string>
using namespace std;

class Animal
{
public:
    virtual ~Animal() = 0;
    virtual void makeSound() = 0;

private:
    int age;
};
Animal::~Animal() {}

class Dog : public Animal
{
public:
    Dog():str("Wow Wow"){}
    void makeSound() {cout << str << endl;}

private:
    string str;
};
//int main()
//{
//    Animal* al = new Dog();
//    al->makeSound();
//    delete al;
//    al = NULL;
//}