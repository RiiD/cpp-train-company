#ifndef __PLATFORM_H
#define __PLATFORM_H

#include <iostream>

#include "Train.h"

class Train;

class Platform
{
private:
	int platform_number;
	const Train* train_in_platform;
	Platform(const Platform& platform);

public:
	Platform(const int platform_number);

	int get_platform_number() const;
	const Train* get_train_in_platform() const;
	void set_train(const Train* train);
	void remove_train();
	bool is_occupied() const;

	void show() const;

	friend std::ostream& operator<<(std::ostream& os, const Platform& platform);
	friend std::ostream& operator<<(std::ostream& os, const Platform* platform);
	const Platform& operator+=(const Train* train);
	const Platform& operator-=(const Train* train);
};

#endif