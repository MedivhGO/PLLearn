#include <iostream>
using namespace std;
//绝不在构造或者析构的过程中调用虚函数
class Animal
{
public:
    Animal();
    virtual void init();
};
void Animal::init()
{
    cout << "Animal ctor" << endl;
}
Animal::Animal()
{
    init();
}



class Dog: public Animal
{
public:
    Dog();
    virtual void init();

private:
    int age;

};
Dog::Dog()
{}
void Dog::init()
{
    age = 0;
    cout << "Dog ctor" << endl;
}
int main1()
{
    Dog d; //输出 Animal ctor //在base class构造期间，virtual函数不是virtual函数
    //derived class 的成员变量尚未确定，virtual如果在 dervied阶层，充满不确定行为。
}

