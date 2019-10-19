#pragma warning(disable: 4996)
#include <iostream>
#include <cstring>
#include "Conductor.h"
using namespace std;


Conductor::Conductor(const Conductor& conductor): Person(conductor.get_name()) 
{

}

Conductor::Conductor(const char* name): Person(name)
{

}

void  Conductor::show() const
{
	cout << "Conductor name is:" << this->get_name << ".\n";

}

std::ostream& operator<<(std::ostream& os, const Conductor& conductor)
{
	os << "Conductor name is:" << conductor.get_name();
}

