#include "pch.h"

#pragma warning(disable: 4996)
#include <iostream>
#include <cstring>

#include "Platform.h"

using namespace std;

Platform::Platform(const int platform_number) : platform_number(platform_number)
{
}

const Train* Platform::get_train_in_platform() const
{
	return train_in_platform;
}

int Platform::get_platform_number() const
{
	return this->platform_number;
}

void Platform::set_train(const Train* train) 
{
	train_in_platform = train;
}

void Platform::remove_train()
{
	train_in_platform = nullptr;
}

bool Platform::is_occupied() const
{
	return train_in_platform != nullptr;
}

void Platform::show() const 
{
	cout << "platform" << this->platform_number << (this->is_occupied() ? " is occupied:" : "is available:") << ".\n";
}

std::ostream& operator<<(std::ostream& os, const Platform& platform)
{
	return os << "platform" << platform.get_platform_number() << (platform.is_occupied() ? "is occupied" : "is not occupied");
}

const Platform& Platform::operator+(const Train& train)
{
	this->set_train(&train);
	return *this;
}

const Platform& Platform::operator-(const Train& train)
{
	this->remove_train();
	return *this;
}
