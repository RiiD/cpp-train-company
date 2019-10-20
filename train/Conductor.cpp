#include "pch.h"

#pragma warning(disable: 4996)
#include <iostream>

#include "Conductor.h"

using namespace std;

Conductor::Conductor(string name) : Person(name)
{
}

void  Conductor::show() const
{
	cout << this << endl;

}

Person* Conductor::clone() const
{
	return new Conductor(*this);
}

ostream & Conductor::dynamic_ostream(ostream& os, const Person* person) const
{
	return os << "Conductor name is:" << person->get_name();
}
