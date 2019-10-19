#include "pch.h"

#pragma warning(disable: 4996)
#include <iostream>
#include <cstring>

#include "Station.h"

using namespace std;

Station::~Station()
{
	for (int i = 0; i < NUM_OF_CITIES - 1; i++) {
		delete platfroms[i];
	}
}

Station::Station(City city)
{
	this->city = city;
	coordinate_X = City_Coordinates[city][0];
	coordinate_Y = City_Coordinates[city][1];

	for (int i = 0; i < NUM_OF_CITIES - 1;)
	{
		if (city != i) {
			platfroms[i] = new Platform(i);
			++i;
		}
	}
}

City Station::get_city() const
{
	return city;
}

int Station::get_coordinate_X() const
{
	return coordinate_X;
}

int Station::get_coordinate_Y() const
{
	return coordinate_Y;
}

void Station::set_coordinates(int x, int y)
{
	this->coordinate_X = x;
	this->coordinate_Y = y;
}

bool Station::platforms_are_available() const
{

	for (int i = 0; i < NUM_OF_CITIES - 1; i++)
	{
		if (this->platfroms[i]->is_occupied())
			return false;
	}
	return true;
}

const Platform& Station::get_platform(int platform_number) const
{
	if (platform_number < 0 || platform_number >= NUM_OF_CITIES)
	{
		throw "Index out of bound";
	}
	return *this->platfroms[platform_number];
}

void Station::show() const
{
	cout << "Station of: " << this->get_city() << "coordinate:" << "("<<this->get_coordinate_X()<<","<<this->get_coordinate_Y()<<")"  << endl;
	for (int i = 0; i < NUM_OF_CITIES - 1; i++)
	{
		cout << "platform " << i << ": " << platfroms[i] << endl;
	}
}

bool Station::operator!=(const Station& other) const
{
	return !(*this == other);
}

bool Station:: operator==(const Station& other) const
{
	return 
		get_city() == other.get_city() && 
		get_coordinate_X() == other.get_coordinate_X() &&
		get_coordinate_Y() == other.get_coordinate_Y();
}

const Platform& Station::operator[](int index) const
{
	return get_platform(index);
}
