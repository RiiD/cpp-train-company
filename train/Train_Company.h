#ifndef __TRAIN_COMPANY_H
#define __TRAIN_COMPANY_H

#include <vector>

#include "Station.h"

using namespace std;

constexpr int MAX_NUMBER_OF_TRAINS = 25;
constexpr int MAX_NUMBER_OF_EMPLOYEES = 25 * (2 + 1);

class Train_Company
{
private:
	static Train_Company instance;

	vector<Station*> stations;
	vector<Train*> trains;
	vector<Person*> employees;

	Train_Company(const Train_Company& train_company);
	Train_Company();
public:
	static Train_Company& get_instance()
	{
		return instance;
	};
	
	~Train_Company();

	//regular functions:

	Station* get_station(City city) const;
	
	const Train* get_train(int index) const;
	int get_number_of_trains() const;

	void decomission_train(Train* train);
	void show() const;

	void operator += (Station& station);
	Train* operator += (Train& train);

	Station* select_station() const;
	Train* select_train() const;
};

#endif