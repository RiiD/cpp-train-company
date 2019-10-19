#ifndef __PLATFORM_H
#define __PLATFORM_H

#define PLATFORM_COUNT 5

#include <iostream>
#include "Train.h"

class Platform
{
private:
	int platform_number;
	Train* train_in_platform;
	Platform(const Platform& platform);

public:
	Platform(const int platform_number);
	~Platform();

	int get_platform_number() const;
	void set_platform_number(const int platform_number);
	void add_train(const Train* train);
	void remove_train();
	bool is_occupied();

	void show() const;

	friend std::ostream& operator<<(std::ostream& os, const Platform& platform);
	const Platform& operator+=(const Train& train);
	const Platform& operator-=(const Train& train);
};

#endif