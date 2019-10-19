#pragma warning(disable: 4996)
#include <iostream>
#include <cstring>
#include "Driver.h"
using namespace std;


Driver::Driver(const Driver& Driver) : Person(Driver.get_name())
{

}

Driver::Driver(const char* name) : Person(name)
{

}

void  Driver::show() const
{
	cout << "Driver name is:" << this->get_name << ".\n";

}

std::ostream& operator<<(std::ostream& os, const Driver& Driver)
{
	os << "Driver name is:" << Driver.get_name();
}

