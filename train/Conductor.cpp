#include "pch.h"

#pragma warning(disable: 4996)
#include <iostream>

#include "Conductor.h"

using namespace std;

Conductor::Conductor(const char* name): Person(name)
{
}

void  Conductor::show() const
{
	cout << *this << endl;

}

std::ostream& operator<<(std::ostream& os, const Conductor& conductor)
{
	return os << "Conductor name is:" << conductor.get_name();
}