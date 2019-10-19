#pragma warning(disable: 4996)
#include <iostream>
#include <cstring>
#include "Carriage.h"
using namespace std;



Carriage::Carriage(Carriage_Type type)
{
	this->type = type;
}


Carriage::Carriage(const Carriage& other)
{
	this->type = other.get_carriage_type();
}

enum Carriage_Type  Carriage::get_carriage_type() const
{
	return this->type;
}

void Carriage::show() const
{
	cout << "type of carriage is: " << this->get_carriage_type()  << ".\n";
}
std::ostream& operator<<(std::ostream& os, const Carriage& Carriage)
{
	os << "type of carriage is:" << Carriage.get_carriage_type();
}

bool Carriage::operator==(const Carriage& other) const
{
	if (this->type == other.get_carriage_type())
		return true;
	else return false;
}

bool Carriage::operator!=(const Carriage& other) const
{
	return !(*this == other);
}



