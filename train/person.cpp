#include "pch.h"

#pragma warning(disable: 4996)
#include <iostream>

#include "person.h"

using namespace std;

Person::~Person()
{
	delete[]name;
}

Person::Person(const char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	
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