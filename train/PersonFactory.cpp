#include "pch.h"

#include <string>
#include <exception>

#include "PersonFactory.h"
#include "Person.h"
#include "Conductor.h"
#include "Driver.h"
#include "Driver_Conductor.h"
#include "Passanger.h"

Person* PersonFactory::getPerson(Type type, string name)
{
	switch (type)
	{
	case PersonFactory::Conductor:
		return new class Conductor(name);
	case PersonFactory::Driver:
		return new class Driver(name);
	case PersonFactory::DriverConductor:
		return new Driver_Conductor(name);
	case PersonFactory::Passanger:
		return new class Passanger(name);
	default:
		throw std::logic_error("not implemented");
	}
}
