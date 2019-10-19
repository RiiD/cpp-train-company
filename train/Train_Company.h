#ifndef __TRAIN_COMPANY_H
#define __TRAIN_COMPANY_H

#define NUMBER_OF_STATIONS 5
#define MAX_NUMBER_OF_TRAINS 25

#include "Station.h"

class Train_Company
{
private:
	Station* stations[NUMBER_OF_STATIONS];
	Train* trains[MAX_NUMBER_OF_TRAINS];
	Train_Company(const Train_Company& train_company);

public:
	Train_Company();
	~Train_Company();

	//regular functions:

	Station& get_station(enum City city) const;
	Station& select_station() const;
	
	Train& get_train(int index) const;
	Train& select_train() const;
	int get_number_of_trains() const;
	void decomission_train(Train& train);

	void decomission_train(Train& train);
	void show() const;

	//operators:

	const Train_Company& operator+(const Station& station);
	const Train_Company& operator-(const Station& station);
	const Train_Company& operator+=(const Station& station);
	const Train_Company& operator-=(const Station& station);

	const Train_Company& operator+(const Train& train);
	const Train_Company& operator-(const Train& train);
	const Train_Company& operator+=(const Train& train);
	const Train_Company& operator-=(const Train& train);

	const Train_Company& operator+(const Person& employee);
	const Train_Company& operator-(const Person& employee);
	const Train_Company& operator+=(const Person& employee);
	const Train_Company& operator-=(const Person& employee);
};

#endif