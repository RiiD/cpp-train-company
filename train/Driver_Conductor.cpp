#include "pch.h"

#pragma warning(disable: 4996)
#include <iostream>
#include <cstring>

#include "Driver_Conductor.h"

using namespace std;

Driver_Conductor::Driver_Conductor(string name) : Driver(name), Conductor(name), Person(name)
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