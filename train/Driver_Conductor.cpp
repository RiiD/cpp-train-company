#include "pch.h"

#pragma warning(disable: 4996)
#include <iostream>
#include <cstring>

#include "Driver_Conductor.h"

using namespace std;

Driver_Conductor::Driver_Conductor(const char* name) : Driver(name), Conductor(name)
{
}

void Driver_Conductor::show() const
{
	cout << "Driver_Conductor name is:" << this->get_name() << ".\n";

}

std::ostream& operator<<(std::ostream& os, const Driver_Conductor& driver_conductor)
{
	return os << "Driver_Conductor name is:" << driver_conductor.get_name();
}

const char* Driver_Conductor::get_name() const 
{
	return Driver::get_name();
}
