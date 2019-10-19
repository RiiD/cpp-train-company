#pragma warning(disable: 4996)
#include <iostream>
#include <cstring>
#include "Station.h"
using namespace std;



Platform::Platform(const int platform_number)
{
	this->platform_number = platform_number;
	this->train_in_platform = nullptr;

}


Platform::Platform(const Platform& platform)
{
	this->platform_number= platform.get_platform_number;
	this->train_in_platform = platform.get_train_in_platform();
}

Platform::~Platform()
{
	delete train_in_platform;

}

Train* Platform:: get_train_in_platform() const // was added by efi 
{
	return train_in_platform;
}


int Platform :: get_platform_number() const
{
	return this->platform_number;
}

void Platform:: set_platform_number(const int platform_number)
{
	this->platform_number = platform_number;
}




void Platform:: add_train(const Train* train) 
{
	train_in_platform= new Train(train) ;
}



void Platform::remove_train()
{
	delete train_in_platform;
	train_in_platform = nullptr;
	
}

bool Platform::is_occupied() 
{

	if (train_in_platform== nullptr)
	{
			return false;
	}
	return true;
}


void Platform:: show() const 
{
		cout << "platform" << this->platform_number << (this->is_occupied ? " is occupied:" : "is available:") << ".\n";
}

std::ostream& operator<<(std::ostream& os, const Platform& platform)
{
	os << "to" << platform.get_platform_number << (platform.is_occupied ? "is occupied" : "is not occupied");
}

const Platform& Platform::operator+=(const Train& train) // i am not sure what we suppose to add here ?
{
	this->add_train(&train);
	return *this;
}

const Platform& Platform::operator-=(const Train& train) // same ?
{
	this->remove_train();
	return *this;
}



