#include "pch.h"

#pragma warning(disable: 4996)
#include <iostream>
#include <cstring>

#include "Driver_Conductor.h"

using namespace std;

Driver_Conductor::Driver_Conductor(const char* name) : Driver(name), Conductor(name), Person(name)
{
}

Driver_Conductor::Driver_Conductor(const Driver_Conductor& other) : Driver(other), Conductor(other), Person(other)
{
}

void Driver_Conductor::show() const
{
	cout << this << endl;

}

ostream & Driver_Conductor::dynamic_ostream(ostream & os, const Person * person) const
{
	return os << "Driver_Conductor: name=" << person->get_name();
}

Person* Driver_Conductor::clone() const
{
	return new Driver_Conductor(*this);
}