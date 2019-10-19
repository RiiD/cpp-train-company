#ifndef __TICKET_H
#define __TICKET_H

#include <iostream>
#include "Station.h"

class Ticket
{
private:
	char* serial;
	Ticket(const Ticket& ticket);

public:
	Ticket();
	~Ticket();

	char* get_serial() const;
	void set_serial(const char* serial);
	Station* get_source() const;
	void set_source(const Station* source);
	Station* get_destination() const;
	void set_destination(const Station* destination);

	void show() const;
	Ticket operator=(const Ticket& other) const;
	friend std::ostream& operator<<(std::ostream& os, const Ticket& ticket);

};


#endif