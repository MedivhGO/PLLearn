#include <iostream>
#include "Sales_data.h"
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
int main()
{
	unsigned u = 10, u2 = 42;
	cout << u - u2 << std::endl;
	int i = 10, i2 = 42;
	cout << i - u << endl;
	cout << u - i << endl;

	return 0;
}