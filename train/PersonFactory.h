#pragma once

#include "Person.h"

class PersonFactory
{
public:
	enum Type { Conductor, Driver, DriverConductor, Passanger };

	Person* getPerson(Type type, string name);
};