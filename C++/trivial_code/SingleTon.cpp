#include <iostream>
#include <mutex>

using namespace std;

std::mutex mtx;
class Foo {
public:
    Foo() {
        cout << "Create a foo object" << endl;
    }
};

class SingleTon {
public:
    static SingleTon* getInstance();
private:
    SingleTon() {
        cout << "Create a object" << endl;
    };
    SingleTon(const SingleTon& rhs) = default;
    SingleTon& operator=(const SingleTon& rhs) = default;
    static SingleTon* singleptr; // 保证指针类型的赋值操作是原子的
};
SingleTon* SingleTon::singleptr = nullptr;

SingleTon* SingleTon::getInstance() {
    if (singleptr == nullptr) {
        mtx.lock();
        if (singleptr == nullptr) {
            singleptr = new SingleTon();
        }
        mtx.unlock();
    }
    return singleptr;
}

template <typename T>
class Singleton : private T {
private:
    Singleton() = default;
    ~Singleton() = default;
public:
    static T& getInstance();
};

template <typename T>
T& Singleton<T>::getInstance() {
    static T s_oT;
    return s_oT;
}

int main()
{
    SingleTon* obj1 = SingleTon::getInstance();
    SingleTon* obj2 = SingleTon::getInstance();

    Foo iobj1 = Singleton<Foo>::getInstance();
    Foo iobj2 = Singleton<Foo>::getInstance();

    return 0;
}