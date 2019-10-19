#pragma warning(disable: 4996)
#include <iostream>
#include <cstring>
#include "Driver_Conductor.h"
using namespace std;

// not sure if i did it right 

Driver_Conductor:: Driver_Conductor(const Driver_Conductor& Driver_Conductor) : Person(Driver_Conductor.get_name()), Driver(Driver_Conductor.get_name()), Conductor(Driver_Conductor.get_name())
{

}

Driver_Conductor::Driver_Conductor(const char* name) :Person(name), Driver(name), Conductor(name) // not sure if its right ?
{

}

void Driver_Conductor::show() const
{
	cout << "Driver_Conductor name is:" << this->get_name << ".\n";

}

std::ostream& operator<<(std::ostream& os, const Driver_Conductor& Driver_Conductor)
{
	os << "Driver_Conductor name is:" << Driver_Conductor.get_name();
}

