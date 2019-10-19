#ifndef __STATION_H
#define __STATION_H

#include "Platform.h"

enum City { Paris, Berlin, Vienna, Prague, Rome };
constexpr char* City_Name[] = { "Paris", "Berlin", "Vienna", "Prague", "Rome" };
constexpr int City_Coordinates[6][2] = { {0,0}, {1,1}, {2,2}, {3,3}, {4,4} };
constexpr int NUM_OF_CITIES = 5;

class Platform;

class Station 
{
private:
	City city;
	int coordinate_X;
	int coordinate_Y;
	Platform* platforms[NUM_OF_CITIES - 1];
	Station(const Station& station);

public:
	Station(City city);
	~Station();

	City get_city() const;
	
	int get_coordinate_X() const;
	int get_coordinate_Y() const;
	void set_coordinates(int x, int y);
	
	bool platforms_are_available() const;
	Platform& get_platform(int platform_number) const;

	void show() const;

	bool operator!=(const Station& other) const;
	bool operator==(const Station& other) const;
	Platform& operator[](int index) const;

	Platform* select_platform() const;

	friend std::ostream& operator<<(std::ostream& os, const Station& platform);
	friend std::ostream& operator<<(std::ostream& os, const Station* platform);
};

#endif