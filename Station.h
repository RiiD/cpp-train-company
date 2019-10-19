#ifndef __STATION_H
#define __STATION_H

#include "Platform.h"

const enum City { Paris, Berlin, Vienna, Prague, Rome, COUNT };
const char* City_Name[] = { "Paris", "Berlin", "Vienna", "Prague", "Rome", "" };
const int City_Coordinates[6][2] = { {0,0}, {1,1}, {2,2}, {3,3}, {4,4} };

class Station 
{
private:
	enum City city;
	int coordinate_X;
	int coordinate_Y;
	Platform platfroms[5];
	Station(const Station& station);

public:
	Station(const enum City city);
	~Station();

	const enum City get_city() const;
	
	int get_coordinate_X() const;
	int get_coordinate_Y() const;
	void set_coordinates(int x, int y);
	
	bool platforms_are_available() const;
	Platform& get_platform(int platform_number) const;
	Platform& select_platform() const;

	void show();

	bool operator!=(const Station& other) const;
	bool operator==(const Station& other) const;
	int& operator[](int index) const;

};

#endif