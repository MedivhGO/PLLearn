
#include "SalesData/Sales_data.h"

using namespace std;
int main()
{
	Sales_data item1;
	cin >> item1;
	cout << item1;

	Sales_data item2;
	item2.bookNo = item1.isbn();
	item2.revenue = 20;
	item2.units_sold = 100;

	item1.combine(item2);
	cout << "combine item2 revenue 20, units_sold 100 " << endl;
	cout << item1;
	return 0;
}