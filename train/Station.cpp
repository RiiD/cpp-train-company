#pragma warning(disable: 4996)
#include <iostream>
#include <cstring>
#include "Station.h"
using namespace std;

Station:: ~Station()
{
	delete [] platfroms;
}

Station::Station(const enum City city)
{
	this->city = city;
	this->coordinate_X = City_Coordinates[city][0];
	this->coordinate_Y = City_Coordinates[city][1];

	for (int i = 0; i < PLATFORM_COUNT; i++)
	{
		this->platfroms[i] = new Platform(i); 
	}
}


Station::Station(const Station& other)
{
	this->city = other.get_city();
	this->coordinate_X = other.get_coordinate_X;
	this->coordinate_Y = other.coordinate_Y;

	delete[] platfroms;

	for (int i = 0; i < PLATFORM_COUNT; i++)
	{
		this->platfroms[i] = new Platform(other.get_platform(i).get_platform_number());
	}
}

Station:: ~Station()
{
	delete[] platfroms;
}

const enum City Station::get_city() const
{
	return this->city;
}

int Station::get_coordinate_X() const
{
	return this->coordinate_X;
}
int Station::get_coordinate_Y() const
{
	return this->coordinate_Y;
}


void Station::set_coordinates(int x, int y)
{
	this->coordinate_X = x;
	this->coordinate_Y = y;
}

bool Station::platforms_are_available() const
{

	for (int i = 0; i < PLATFORM_COUNT; i++)  
	{
		if (this->platfroms[i]->is_occupied)
			return false;
	}
	return true;
}

Platform& Station::get_platform(int platform_number) const
{
	return *this->platfroms[platform_number]; //error check
}


Platform& Station::select_platform() const 
{
	int action = -1;
	std::cin >> action; //error check

	return this->get_platform(action);
}

void Station::show() 
{
	cout << "Station of: " << this->get_city() << "coordinate:" << "("<<this->get_coordinate_X()<<","<<this->get_coordinate_Y()<<")"  << ".\n";
	for (int i = 0; i < 5; i++)
	{
		cout << "platform" << i  << (this->get_platform(i).is_occupied()  ? " is occupied:" : "is available:")  << ".\n";
	}

}

bool Station::operator!=(const Station& other) const
{
	if (this->city == other.get_city())
		return false;
	else if (this->coordinate_X == other.get_coordinate_X())
		return false;
	else if (this->coordinate_Y == other.get_coordinate_Y())
		return false;

	return true;
}

bool Station:: operator==(const Station& other) const
{
	return  !(*this != other);
}


int& Station:: operator[](int index) const // what can we return ?
{
	
}


