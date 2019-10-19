#include "pch.h"

#pragma warning(disable: 4996)
#include <iostream>
#include <cstring>

#include "Carriage.h"

using namespace std;

Carriage::Carriage(Carriage::Type type) : type(type)
{
}

Carriage::Type Carriage::get_carriage_type() const
{
	return this->type;
}

void Carriage::show() const
{
	cout << *this << endl;
}

std::ostream& operator<<(std::ostream& os, const Carriage& Carriage)
{
	return os << "type of carriage is:" << Carriage.get_carriage_type();
}

bool Carriage::operator==(const Carriage& other) const
{
	return this->get_carriage_type() == other.get_carriage_type();
}

bool Carriage::operator!=(const Carriage& other) const
{
	return !(*this == other);
}
