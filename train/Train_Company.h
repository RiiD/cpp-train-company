#ifndef __TRAIN_COMPANY_H
#define __TRAIN_COMPANY_H

#include "Station.h"

constexpr int MAX_NUMBER_OF_TRAINS = 25;
constexpr int MAX_NUMBER_OF_EMPLOYEES = 25 * (2 + 1);

class Train_Company
{
private:
	const Station* stations[NUM_OF_CITIES];
	Train* trains[MAX_NUMBER_OF_TRAINS];
	Person* employees[MAX_NUMBER_OF_EMPLOYEES];

	int number_of_trains = 0;
	int number_of_stations = 0;
	int number_of_employees = 0;

	Train_Company(const Train_Company& train_company);
public:
	Train_Company();
	~Train_Company();

	//regular functions:

	const Station* get_station(City city) const;
	
	const Train* get_train(int index) const;
	int get_number_of_trains() const;
	void decomission_train(Train* train);
	void show() const;

	void operator += (const Station& station);
};

#endif