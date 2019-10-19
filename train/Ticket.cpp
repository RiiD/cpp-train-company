#include "pch.h"

#pragma warning(disable: 4996)
#include <iostream>
#include <cstring>

#include "Ticket.h"

using namespace std;

unsigned long Ticket::last_serial = 0;

Ticket::Ticket() : serial(++last_serial)
{
}

unsigned long Ticket::get_serial() const
{
	return serial;
}

void Ticket::set_source(const Station* source)
{
	this->source = source;
}

const Station* Ticket::get_source() const
{
	return source;
}

const Station* Ticket::get_destination() const
{
	return destination;
}

void Ticket::set_destination(const Station* destination)
{
	this->destination = destination;
}

void Ticket:: show() const
{
	cout << *this;

}

 std::ostream& operator<<(std::ostream& os, const Ticket& ticket)
{
	return os << "to" << ticket.destination << "from" << ticket.source << "serial number" << ticket.serial;
}