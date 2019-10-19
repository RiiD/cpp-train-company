#pragma warning(disable: 4996)
#include <iostream>
#include <cstring>
#include "Ticket.h"
#include "Station.h"
using namespace std;



Ticket::Ticket() 
{

	this->make_serial();
	this->destination = nullptr;
	this->source = nullptr;

}


Ticket::Ticket(const Ticket& other) 
{
	set_serial(other.get_serial());
	this->destination = other.destination;
	this->source = other.source;
	delete  &other;
}

void Ticket::make_serial() 
{
	++serial;
}


void Ticket::set_serial(const int number)
{
	if ((number) <serial )
	serial=number;
}

unsigned long  Ticket::get_serial() const
{
	return serial;
}

void Ticket::set_source(const Station* source)
{
	 source=new Station(source->get_city());
}

Station* Ticket::get_source() const
{
	return source;
}

Station* Ticket::get_destination() const
{
	return destination;
}
void Ticket::set_destination(const Station* destination)
{
	delete destination;
	destination = new Station(destination->get_city());
}

Ticket Ticket:: operator=(const Ticket& other) 
{
	/*this->serial = other.get_serial();
	this->destination =other.get_destination();
	this->source = other.get_source();*/
	Ticket(other);
	return *this;
}
void Ticket:: show() const
{
	cout << "serial number: " << this->get_serial() << "from:" << this->destination  << "to:" << this->source << ".\n";

}



 std::ostream& operator<<(std::ostream& os, const Ticket& ticket)
{
	 os << "to" << ticket.destination << "from" << ticket.source << "serial number" << ticket.serial;
}

