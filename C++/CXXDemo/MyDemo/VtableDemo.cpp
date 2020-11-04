#include <iostream>
#include <vector>
#include <memory>
using namespace std;
class TestBase {
 public:
	TestBase() {
		std::cout << "TestBase construct" << std::endl;
	}
	~TestBase() {
		std::cout << "TestBase destroy" << std::endl;
	}
	void print_info() {
		std::cout << "TestBase print_info" << info.c_str()<< std::endl;
	}
	void set_info(std::string str) {
		info = str;
	}
	std::string info;

};
class TestEqual : public TestBase {
public:
	TestEqual() {}
	~TestEqual() {}
	TestEqual& operator = (int a) {
		std::cout << "in operator = with int" << std::endl;
		return *this;
	}
	void operator = (bool a) {
		std::cout << "in operator = with return void" << std::endl;
		return;
	}
};
class DebugInfo {
public:
	DebugInfo(const char* info) {
		_info = info;
		std::cout << "-------in" << _info.c_str() << "-----" << std::endl;
	}

	~DebugInfo() {
		std::cout << "------out " << _info.c_str() << "------" << std::endl;
	}

private:
	std::string _info;

};
void test_equal()
{
	DebugInfo debug_auto_ptr("test_equal");
	TestEqual test_equal;
	test_equal = 1;
	test_equal = true;
	TestEqual test_equal1;
	test_equal1 = test_equal;
}
void test_auto_ptr()
{
	DebugInfo debug_auto_ptr("test_auto_ptr");
	std::auto_ptr<TestBase> base(new TestBase());
}

int main()
{
	//test_equal();
	test_auto_ptr();
	while (1);
	return 0;
}