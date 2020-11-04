//#include <iostream>
//using namespace std;
//class Animal
//{
//private:
//    int agility;
//public:
//    Animal& operator = (const Animal& rhs);
//    Animal& operator = (int agility);
//    Animal& operator+=(const Animal& rhs);
//
//    operator int(); //类型转换？？
//};
//Animal::operator int()
//{
//    return this->agility;
//}
//Animal& Animal::operator=(const Animal &rhs)
//{
//    this->agility = rhs.agility;
//    return *this;
//}
//Animal& Animal::operator=(int agility)
//{
//    this->agility = agility;
//    return *this;
//}
//Animal& Animal::operator+=(const Animal &rhs)
//{
//    this->agility += rhs.agility;
//    return *this;
//}
//int main3()
//{
//    Animal genX;
//    Animal genY;
//    Animal genZ;
//
//    genX = 10;
//    genZ = 20;
//    genY = genX;
//    genZ += genY;
//
//    cout << genX << endl;
//    return 0;
//
//}