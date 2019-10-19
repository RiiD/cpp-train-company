#ifndef __DRIVER_H
#define __DRIVER_H

#include <iostream>

#include "Person.h"

class Driver : virtual public Person
{
public:
	Driver(const char* name);
	Driver(const Driver& other);

	virtual void show() const;
	virtual ostream& dynamic_ostream(ostream& os, const Person* person) const override;
	virtual Person* clone() const override;

};

#endif