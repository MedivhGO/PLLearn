#include "Sales_data.h"

std::ostream& operator << (std::ostream& co, const Sales_data& item) {
	co << "isbn is : " << item.bookNo << std::endl;
	co << "units_sold is : " << item.units_sold << std::endl;
	co << "revenue is : " << item.revenue << std::endl;
	return co;
}

std::istream& operator >> (std::istream& io, Sales_data& item) {
	io >> item.bookNo;
	io >> item.units_sold;
	io >> item.revenue;
	return io;
}

Sales_data& Sales_data::combine(const Sales_data& rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}