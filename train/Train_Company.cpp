#include "pch.h"

#pragma warning(disable: 4996)
#include <iostream>
#include <cstring>
#include <algorithm>

#include "Train_Company.h"
#include "CancelledException.h"

using namespace std;

Train_Company Train_Company::instance;

Train_Company::Train_Company() 
{
}

Train_Company::~Train_Company() 
{
	for_each(trains.begin(), trains.end(), [](Train* t) { delete t; });
	for_each(employees.begin(), employees.end(), [](Person* t) { delete t; });
}

Station* Train_Company::get_station(City city) const
{
	auto it = find_if(stations.begin(), stations.end(), [&](Station* s) { return city == s->get_city(); });
	if (it != stations.end())
	{
		return *it;
	}

	return nullptr;
}

const Train* Train_Company::get_train(int index) const
{
	return trains[index];
}

int Train_Company::get_number_of_trains() const
{
	return trains.size();
}

void Train_Company::decomission_train(Train* train)
{
	for (auto it = trains.begin(), end = trains.end(); it != end; ++it)
	{
		auto c = *it;
		if (c == train)
		{
			trains.erase(it);
			delete c;
			break;
		}
	}
}

void Train_Company::show() const
{
	cout << "Train company has " << stations.size() << " stations, " << trains.size() << " trains, and " << employees.size() << " employees" << endl;
}

void Train_Company::operator+=(Station & station)
{
	stations.push_back(&station);
}

Train * Train_Company::operator+=(Train& train)
{
	Train* company_train = new Train(train);
	trains.push_back(company_train);
	return company_train;
}

Station* Train_Company::select_station() const
{
	int selection;
	do
	{
		int i = 0;
		for_each(stations.begin(), stations.end(), [&](Station* s) { cout << ++i << ". " << s << endl; });

		cout << ": ";
		cin >> selection;
	} while (selection < 0 || selection > stations.size());

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
		int i = 0;
		for_each(trains.begin(), trains.end(), [&](Train* s) { cout << ++i << ". " << s << endl; });

		cout << ": ";
		cin >> selection;
	} while (selection < 0 || selection > trains.size());

	if (selection == 0)
	{
		throw CancelledException();
	}

	return trains[selection - 1];
}
