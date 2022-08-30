#include <iostream>
#include <mutex>

using namespace std;

std::mutex mtx;
class SingleTon {
public:
    SingleTon();
    SingleTon(const SingleTon& rhs);
    SingleTon& operator=(const SingleTon& rhs);
    SingleTon* getInstance();
private:
    static SingleTon* singleptr; // 保证指针类型的赋值操作是原子的
};

SingleTon* SingleTon::singleptr = nullptr;

SingleTon* SingleTon::getInstance() {
    if (singleptr == nullptr) {
        mtx.lock();
        if (singleptr == nullptr) {
            singleptr = new SingleTon();
        }
    }
    return singleptr;
}