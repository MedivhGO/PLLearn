#include <iostream>
#include <memory>

using namespace std;
class B;
class A {
 public:
  A() : m_sptrB(nullptr){};
  ~A() { cout << " A is destroyed" << endl; }
  shared_ptr<B> m_sptrB;
};
class B {
 public:
  B() : m_sptrA(nullptr){};
  ~B() { cout << " B is destroyed" << endl; }
  shared_ptr<A> m_sptrA;
};

int main() {
  shared_ptr<B> sptrB(new B);         // sptB count 1 有一个B对象，持有A对象的指针。
  shared_ptr<A> sptrA(new A);         // sptB count 1
  sptrB->m_sptrA = sptrA;             // sptA count 2
  cout << sptrA.use_count() << endl;  // 2 sptrA和sptrB 
  cout << sptrB.use_count() << endl;  // 1 sptrB
  sptrA->m_sptrB = sptrB;             // sptB count 2 sptrA和sptrB
  cout << sptrA.use_count() << endl;  // 2
  cout << sptrB.use_count() << endl;  // 2
  return 0;
}