#include "pch.h"

#pragma warning(disable: 4996)

#include <algorithm>

#include "TrainBuilder.h"

using namespace std;

bool TrainBuilder::isCrewExists(Person* person) const
{
	return any_of(crew.begin(), crew.end(), [&](Person* p) { return *person == *p; });
}

TrainBuilder::TrainBuilder()
{
}

TrainBuilder::TrainBuilder(const TrainBuilder & other)
{
	*this = other;
}

TrainBuilder::~TrainBuilder()
{
	for_each(carriages.begin(), carriages.end(), [](Carriage* c) { delete c; });
	for_each(crew.begin(), crew.end(), [](Person* p) { delete p; });
}

void TrainBuilder::operator=(const TrainBuilder & other)
{
	for_each(carriages.begin(), carriages.end(), [](Carriage* c) { delete c; });
	for_each(crew.begin(), crew.end(), [](Person* p) { delete p; });

	carriages.resize(other.carriages.size());
	crew.resize(other.carriages.size());

	transform(other.carriages.begin(), other.carriages.end(), carriages.begin(), [](Carriage* c) { return new Carriage(c->get_carriage_type()); });
	transform(other.crew.begin(), other.crew.end(), crew.begin(), [](Person* c) { return c->clone(); });
}

TrainBuilder & TrainBuilder::addDriver(Driver& driver)
{ 
	if (isCrewExists(&driver))
	{
		throw TrainBuilder::DuplicateException();
	}

	crew.push_back(driver.clone());
	return *this;
}

TrainBuilder & TrainBuilder::addConductor(Conductor& conductor)
{
	if (isCrewExists(&conductor))
	{
		throw TrainBuilder::DuplicateException();
	}

	crew.push_back(conductor.clone());
	return *this;
}

TrainBuilder & TrainBuilder::addCarriage(Carriage::Type type)
{
	carriages.push_back(new Carriage(type));
	return *this;
}

TrainBuilder & TrainBuilder::setPlatform(Platform* platform)
{
	this->platform = platform;
	return *this;
}

Train TrainBuilder::build()
{
	Train train(platform);
	train.carriages = carriages;
	train.crew_members = crew;

	carriages.clear();
	crew.clear();

	return train;
}
