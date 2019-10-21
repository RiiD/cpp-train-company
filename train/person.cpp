#include "pch.h"

#pragma warning(disable: 4996)
#include <iostream>

#include "person.h"

using namespace std;

Person::Person(string name) : name(name)
{
}

void Person::show() const
{
	cout << "Name: " << name << ".\n";
}

string Person::get_name() const
{
	return name;
}

void Person::set_name(string newName)
{
	name = newName;
}

bool Person::operator==(const Person& person) const
{
	return get_name() == person.get_name();
}

std::ostream & operator<<(std::ostream& os, const Person* person)
{
	return person->dynamic_ostream(os, person);
}
