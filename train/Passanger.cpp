
#pragma warning(disable: 4996)
#include <iostream>
#include <cstring>


#include "Passanger.h"

using namespace std;


Passanger::Passanger( char* name) : Person(name)
{

}


Passanger::Passanger(const Passanger& other) : Person(other.get_name()) 
{
	this->ticket = other.get_ticket();
}

const Ticket&  Passanger::get_ticket() const
{
	return this->ticket;
}


void Passanger::show() const
{
	cout << "Name: " << this->get_name() << "ticket:" << this->get_ticket() << ".\n";
}




