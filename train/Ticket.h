#ifndef __TICKET_H
#define __TICKET_H

#include <iostream>

#include "Station.h"

class Station;

class Ticket
{
private:
	static unsigned long last_serial;

	unsigned long serial;

    const Station* destination;
	const Station* source;

	Ticket(const Ticket& ticket);

public:
	Ticket();

	unsigned long get_serial() const;

	const Station* get_source() const;
	void set_source(const Station* source);

	const Station* get_destination() const;
	void set_destination(const Station* destination);

	void show() const;
	friend std::ostream& operator<<(std::ostream& os, const Ticket& ticket);
};

#endif