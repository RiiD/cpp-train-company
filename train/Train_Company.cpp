#include "pch.h"

#pragma warning(disable: 4996)
#include <iostream>
#include <cstring>

#include "Train_Company.h"
#include "CancelledException.h"

using namespace std;

Train_Company::Train_Company() 
{
}

Train_Company::~Train_Company() 
{
	for (int i = 0; i < number_of_trains; i++) 
	{
		delete trains[i];
	}

	for (int i = 0; i < number_of_employees; i++)
	{
		delete employees[i];
	}
}

Station* Train_Company::get_station(City city) const
{
	for (int i = 0; i < number_of_stations; i++) 
	{
		if (stations[i]->get_city() == city) {
			return stations[i];
		}
	}

	return nullptr;
}

const Train* Train_Company::get_train(int index) const
{
	if (index < 0 || index >= number_of_trains)
	{
		throw CancelledException();
	}
	return trains[index];
}

int Train_Company::get_number_of_trains() const
{
	return number_of_trains;
}

void Train_Company::decomission_train(Train* train)
{
	int i = 0;
	for (; i < number_of_trains && trains[i] != train; i++) {}

	if (i < number_of_trains)
	{
		delete trains[i];
		--number_of_trains;
		for (; i < number_of_trains; i++) 
		{
			trains[i] = trains[i + 1];
		}
	}
}

void Train_Company::show() const
{
	cout << "Train company" << endl
		 << "Stations:" << endl;

	for (int i = 0; i < number_of_stations; i++)
	{
		cout << i << ". " << *stations[i] << endl;
	}

	cout << "Trains:" << endl;
	for (int i = 0; i < number_of_trains; i++)
	{
		cout << i << ". " << *trains[i] << endl;
	}

	cout << "Employees:" << endl;
	for (int i = 0; i < number_of_employees; i++)
	{
		cout << i << ". " << employees[i] << endl;
	}
}

void Train_Company::operator+=(Station & station)
{
	stations[number_of_stations++] = &station;
}

Train * Train_Company::operator+=(Train& train)
{
	Train* company_train = new Train(train);
	trains[number_of_trains++] = company_train;
	return company_train;
}

Station* Train_Company::select_station() const
{
	int selection;
	do
	{
		for (int i = 0; i < number_of_stations; i++)
		{
			cout << i + 1 << ". " << stations[i] << endl;
		}

		cout << ": ";
		cin >> selection;
	} while (selection < 0 || selection > number_of_stations);

	if (selection == 0)
	{
		throw CancelledException();
	}

	return stations[selection - 1];
}

Train* Train_Company::select_train() const
{
	int selection;
	do
	{
		for (int i = 0; i < number_of_trains; i++)
		{
			cout << i + 1 << ". " << trains[i] << endl;
		}

		cout << ": ";
		cin >> selection;
	} while (selection < 0 || selection > number_of_trains);

	if (selection == 0)
	{
		throw CancelledException();
	}

	return trains[selection - 1];
}
