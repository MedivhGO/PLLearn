#include <iostream>
#include <string>

using namespace std;
class Animal
{
public:
    Animal(int aAge = 0);
    Animal(const Animal& rhs);
    Animal&operator= (const Animal& rhs);

    int getAge() {return age;}

private:
    int age;
};
Animal::Animal(int aAge) : age(aAge){}
Animal::Animal(const Animal &rhs) : age(rhs.age){}

Animal&  Animal::operator=(const Animal &rhs)
{
    age = rhs.age;
    return *this;
}
class Dog : public Animal
{
public:
    Dog(int aAge = 0,string aBreed = "\0");
    Dog(const Dog& rhs);
    Dog&operator= (const Dog& rhs);

    void ToString();

private:
    string breed;
};
Dog::Dog(int aAge, string aBreed) : Animal(aAge),breed(aBreed){}
Dog::Dog(const Dog& rhs): Animal(rhs),breed(rhs.breed)
{}

void Dog::ToString()
{
    cout << "Age:" << getAge() << "; Breed: " << breed << endl;
}
Dog& Dog::operator=(const Dog &rhs)
{
   // Animal::operator=(rhs); 这句如果不加，会造成对象赋值不完全
    breed = rhs.breed;
    return *this;
}
int main44()
{
    Dog d1(10,"Bull Dog");
    cout << "Dog d: " << endl;
    d1.ToString();

    Dog d2(d1);
    cout << endl << "Dog d2: " << endl;
    d2.ToString();

    Dog d(13,"Alsasian");
    Dog d3(10,"Labrador");

    d3 = d;
    cout << endl << "Dog d3: " << endl;
    d3.ToString();
    return 0;

}

