#pragma warning(disable: 4996)
#include <iostream>
#include <cstring>

using namespace std;

#include "person.h"

Person::~Person()
{
	delete[]name;
}

Person::Person(const char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	
}

Person::Person(const Person& other)
{
	delete[] this->name;
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);

}


void Person::show() const
{
	cout << "Name: " << name << ".\n";
}

char* Person::get_name() const
{
	return name;
}

void Person::set_name(const char* newName)
{
	delete[]name;
	name = new char[strlen(newName) + 1];
	strcpy(name, newName);
}

 

