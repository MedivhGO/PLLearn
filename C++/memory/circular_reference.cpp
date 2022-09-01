#include <iostream>
#include <memory>

using namespace std;

class B;
class A { // A 拥有一个B的指针
public:
	A() : m_sptrB(nullptr) {};
	~A() { cout << " A is destroyed" << endl; }
	shared_ptr<B> m_sptrB;
};

class B { // B 拥有一个A的指针
public:
	B() : m_sptrA(nullptr) {};
	~B() { cout << " B is destroyed" << endl; }
	shared_ptr<A> m_sptrA;
};

int main() {
	shared_ptr<B> sptrB(new B);         // 定义一个sptrB变量
	shared_ptr<A> sptrA(new A);         // 定义一个sptrA变量
	cout << sptrA.use_count() << endl;  // 1 sptrA
	cout << sptrB.use_count() << endl;  // 1 sptrB
	sptrB->m_sptrA = sptrA;             // sptA count 2, sptrB拥有B, 申请A.
	sptrA->m_sptrB = sptrB;             // sptB count 2, sptrA拥有A, 申请B.
	cout << sptrA.use_count() << endl;  // 2
	cout << sptrB.use_count() << endl;  // 2
	// 所以直到最后, 资源都没有被释放, 因为这两个shared_ptr的引用计数都不是0
	return 0;
}