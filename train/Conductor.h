#ifndef __CONDUCTOR_H
#define __CONDUCTOR_H

#include <iostream>
#include "Person.h"

class Conductor : virtual public Person
{
private:
	Conductor(const Conductor& conductor);

public:
	Conductor(const char* name);
	~Conductor();

	virtual void show() const;
	friend std::ostream& operator<<(std::ostream& os, const Conductor& conductor);
};

#endif