#ifndef __TICKET_H
#define __TICKET_H

#include <iostream>
#include "Station.h"

class Ticket
{
private:
	unsigned long  serial=0 ; // was changed from char *
    Station*  destination;
	Station*  source;



	Ticket(const Ticket& ticket);

public:
	Ticket();
	~Ticket();

	unsigned long get_serial() const;
	void set_serial(const int serial); 
	void make_serial(); // was added by me 
	Station* get_source() const;
	void set_source(const Station* source);
	Station* get_destination() const;
	void set_destination(const Station* destination);

	void show() const;
	Ticket operator=(const Ticket& other) ;// was change to not const
	friend std::ostream& operator<<(std::ostream& os, const Ticket& ticket);

};


#endif