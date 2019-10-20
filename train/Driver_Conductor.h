#ifndef __DRIVER_CONDUCTOR_H
#define __DRIVER_CONDUCTOR_H

#include <iostream>
#include <string>

#include "Driver.h"
#include "Conductor.h"

class Driver_Conductor : public Driver, public Conductor
{
public:
	Driver_Conductor(string name);

	virtual void show() const override;
	virtual ostream& dynamic_ostream(ostream& os, const Person* person) const override;
	virtual Person* clone() const override;
};

#endif