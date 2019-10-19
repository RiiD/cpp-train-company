#include "pch.h"

#pragma warning(disable: 4996)
#include <iostream>

#include "Passanger.h"

using namespace std;

Passanger::Passanger(char* name, const Ticket* ticket) : Person(name)
{
	this->ticket = ticket;
}

const Ticket* Passanger::get_ticket() const
{
	return this->ticket;
}

void Passanger::show() const
{
	cout << *this << endl;
}

std::ostream & operator<<(std::ostream & os, const Passanger & passanger)
{
	return os << "Name: " << passanger.get_name() << "ticket:" << passanger.get_ticket();
}
