#ifndef __DRIVER_H
#define __DRIVER_H

#include <iostream>
#include <string>

#include "Person.h"

class Driver : virtual public Person
{
public:
	Driver(string name);

	virtual void show() const override;
	virtual ostream& dynamic_ostream(ostream& os, const Person* person) const override;
	virtual Person* clone() const override;

};

#endif