#include "pch.h"

#pragma warning(disable: 4996)
#include <iostream>

#include "Driver.h"

using namespace std;

Driver::Driver(const char* name) : Person(name)
{
}

void  Driver::show() const
{
	cout << *this << endl;
}

std::ostream& operator<<(std::ostream& os, const Driver& Driver)
{
	return os << "Driver name is:" << Driver.get_name();
}