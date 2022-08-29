#include <iostream>
using namespace std;

enum TESTTYPE {
    A1, A2, A3 ,A4
};

template <TESTTYPE T>
struct TYPETRAITS{};

template<>
struct TYPETRAITS<A1>{
    using MYTYPE = int;
};

template<>
struct TYPETRAITS<A2>{
    using MYTYPE = double;
};

template<>
struct TYPETRAITS<A3>{
    using MYTYPE = long;
};


int main()
{
    TYPETRAITS<A1>::MYTYPE a;
    TYPETRAITS<A2>::MYTYPE b;
    TYPETRAITS<A3>::MYTYPE c;
    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;
    cout << typeid(c).name() << endl;
}