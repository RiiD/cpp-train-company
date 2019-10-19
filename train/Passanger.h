#ifndef __PASSANGER_H
#define __PASSANGER_H

#include <iostream>

#include "Ticket.h"
#include "Person.h"

class Ticket;

class Passanger : public Person
{
private:
	const Ticket* ticket;
	Passanger(const Passanger& passanger);

public:
	Passanger(char* name, const Ticket* ticket);

	const Ticket* get_ticket() const;

	virtual void show() const;
	friend std::ostream& operator<<(std::ostream& os, const Passanger& passanger);
};

#endif