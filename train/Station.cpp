#include "pch.h"

#pragma warning(disable: 4996)
#include <iostream>
#include <cstring>

#include "Station.h"
#include "CancelledException.h"

using namespace std;

Station::~Station()
{
	auto next = platforms.get_head();
	while (next != nullptr)
	{
		delete next->item;
		next = next->prev;
	}
}

Station::Station(City city)
{
	this->city = city;
	coordinate_X = City_Coordinates[city][0];
	coordinate_Y = City_Coordinates[city][1];

	for (int c = 0, p = 0; c < NUM_OF_CITIES; c++)
	{
		if (city != c) {
			platforms.append(new Platform(p++, this));
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
	auto next = platforms.get_head();
	while (next != nullptr)
	{
		if (!next->item->is_occupied())
		{
			return true;
		}
		next = next->prev;
	}
	return false;
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

Platform* Station::select_platform()
{
	int selection;
	do
	{
		int i = 0;
		platforms.for_each([&] (Platform* p) { cout << i << "." << p << endl; });

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
	auto next = platforms.get_head();
	while (next != nullptr)
	{
		if (!next->item->is_occupied())
		{
			return next->item;
		}
		next = next->prev;
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
