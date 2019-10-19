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

public:
	Passanger(char* name);
	Passanger(const Passanger& other);

	const Ticket* get_ticket() const;

	virtual void show() const;
	virtual ostream& dynamic_ostream(ostream& os, const Person* person) const override;
	virtual Person* clone() const override;
};

#endif