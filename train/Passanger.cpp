#include "pch.h"

#pragma warning(disable: 4996)
#include <iostream>

#include "Passanger.h"

using namespace std;

Passanger::Passanger(char* name) : Person(name)
{
}

Passanger::Passanger(const Passanger& other) : Person(other.get_name())
{
	ticket = other.ticket;
}

const Ticket* Passanger::get_ticket() const
{
	return this->ticket;
}

void Passanger::show() const
{
	cout << this << endl;
}

ostream& Passanger::dynamic_ostream(ostream & os, const Person* person) const
{
	return os << "Passanger: name=" << person->get_name();
}

Person* Passanger::clone() const
{
	return new Passanger(*this);
}
