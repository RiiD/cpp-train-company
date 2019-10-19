#ifndef __DRIVER_H
#define __DRIVER_H

#include <iostream>
#include "Person.h"

class Driver : virtual public Person
{
private:
	Driver(const Driver& other); 

public:
	Driver(const char* name);
	~Driver();

	virtual void show() const;
	friend std::ostream& operator<<(std::ostream& os, const Driver& driver);

};

#endif
