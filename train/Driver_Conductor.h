#ifndef __DRIVER_CONDUCTOR_H
#define __DRIVER_CONDUCTOR_H

#include <iostream>

#include "Driver.h"
#include "Conductor.h"

class Driver_Conductor : public Driver, public Conductor
{
private:
	Driver_Conductor(const Driver_Conductor& driver_conductor);

public:
	Driver_Conductor(const char* name);

	const char* get_name() const;

	virtual void show() const override;
	friend std::ostream& operator<<(std::ostream& os, const Driver_Conductor& driver_conductor);
};

#endif