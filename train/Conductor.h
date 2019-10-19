#ifndef __CONDUCTOR_H
#define __CONDUCTOR_H

#include <iostream>

#include "Person.h"

class Conductor : virtual public Person
{
public:
	Conductor(const char* name);
	Conductor(const Conductor& other);

	virtual void show() const;
	virtual Person* clone() const override;
	virtual ostream& dynamic_ostream(ostream& os, const Person* person) const override;
};

#endif