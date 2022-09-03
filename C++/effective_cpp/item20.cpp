#include <iostream>
#include <string>

using namespace std;

class Animal
{
    string name;
    int age;

public:
    Animal(string animalName,int animalAge) : name(animalName),age(animalAge){}

    void printName() const {cout << name << " ";}
    void printAge() const {cout << age << " ";}
    virtual  void printBreed()const {cout << "" << " ";}
};
class Dog : public Animal
{
    string breed;
public:
    Dog(string animalName,int animalAge,string breedName) : Animal(animalName,animalAge),breed(breedName){}
    void printBreed() const {cout << breed << " ";}

};
void printAnimal(const Animal& dog) {dog.printName();dog.printAge();dog.printBreed();cout << endl;}

int main231123123()
{
    Dog scooby("ScoobyDoo",10,"GreatDane");
    printAnimal(scooby);
    return 0;
}