#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

struct Sales_data {
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const { return revenue / units_sold; }
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;

	friend std::ostream& operator << (std::ostream&, const Sales_data&);
	friend std::istream& operator >> (std::istream&, Sales_data&);
};

#endif // !SALES_DATA_H
