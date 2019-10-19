#include "pch.h"

#pragma warning(disable: 4996)
#include <iostream>
#include <cstring>

#include "Station.h"
#include "CancelledException.h"

using namespace std;

Station::~Station()
{
	for (int i = 0; i < NUM_OF_CITIES - 1; i++) {
		delete platforms[i];
	}
}

Station::Station(City city)
{
	this->city = city;
	coordinate_X = City_Coordinates[city][0];
	coordinate_Y = City_Coordinates[city][1];

	for (int c = 0, p = 0; c < NUM_OF_CITIES, p < NUM_OF_CITIES - 1; c++)
	{
		if (city != c) {
			platforms[p] = new Platform(c, this);
			++p;
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
		if (!this->platforms[i]->is_occupied())
		{
			return true;
		}
	}
	return false;
}

Platform& Station::get_platform(int platform_number) const
{
	if (platform_number < 0 || platform_number >= NUM_OF_CITIES)
	{
		throw "Index out of bound";
	}
	return *this->platforms[platform_number];
}

void Station::show() const
{
	cout << this << endl;
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

Platform& Station::operator[](int index) const
{
	return get_platform(index);
}

Platform * Station::select_platform() const
{
	int selection;
	do
	{
		for (int i = 0; i < NUM_OF_CITIES - 1; i++)
		{
			cout << i + 1 << ". " << platforms[i] << endl;
		}

		cout << ": ";
		cin >> selection;
	} while (selection < 0 || selection >  NUM_OF_CITIES - 1);

	if (selection == 0) 
	{
		throw CancelledException();
	}

	return platforms[selection - 1];
}

Platform* Station::get_available_platform() const
{
	for (int i = 0; i < NUM_OF_CITIES - 1; i++)
	{
		if (!platforms[i]->is_occupied()) 
		{
			return platforms[i];
		}
	}
	return nullptr;
}

std::ostream & operator<<(std::ostream & os, const Station& station)
{
	return os << &station;
}

std::ostream & operator<<(std::ostream & os, const Station* station)
{
	return os 
		<< "Station " << City_Name[station->get_city()] << "(" << station->get_coordinate_X() << ", " << station->get_coordinate_Y() << ")";
}
