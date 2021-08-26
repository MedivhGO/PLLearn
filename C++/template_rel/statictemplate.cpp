#include <iostream>
#include <string>
using namespace std;

template <typename T> class Foo 
{
	public:
		static std::size_t count() {return ctr;}
	private:
		static std::size_t ctr;	
};
//因为类模板的每个实例都有一个独有的static对象,因此,与定义模板的成员函数类似,我们将static数据成员也定义为模板:
template <typename T>
size_t Foo<T>::ctr = 0;
template <> //模板特化
size_t Foo<std::string>::ctr = 20;
int main(int argc, char *argv[]) {
	Foo<string> foo;
	cout << foo.count() << endl;
}