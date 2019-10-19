#include "pch.h"

#pragma warning(disable: 4996)
#include <iostream>

#include "Driver.h"

using namespace std;

Driver::Driver(const char* name) : Person(name)
{
}

Driver::Driver(const Driver & other) : Person(other)
{
}

void  Driver::show() const
{
	cout << this << endl;
}

ostream & Driver::dynamic_ostream(ostream & os, const Person* person) const
{
	return os << "Driver: name=" << person->get_name();
}

Person* Driver::clone() const
{
	return new Driver(*this);
}