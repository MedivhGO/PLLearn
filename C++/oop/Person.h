#ifndef PERSON_H
#define PERSON_H
#include <string>
struct Person {
    string name;
	string address;
	string getName() const { return this->name; }
	string getAddress() const { return this->address; }
};
#endif // !PERSON_H
