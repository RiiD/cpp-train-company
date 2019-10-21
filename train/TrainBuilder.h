#pragma once

#include <vector>
#include <exception>

#include "Person.h"
#include "Carriage.h"
#include "Platform.h"
#include "Driver.h"
#include "Conductor.h"
#include "Train.h"

using namespace std;

class Person;
class Carriage;
class Platform;
class Train;

class TrainBuilder
{
private:
	vector<Person*> crew;
	vector<Carriage*> carriages;
	Platform* platform;

	bool isCrewExists(Person* person) const;
public:
	class DuplicateException : public exception {};
	TrainBuilder();
	TrainBuilder(const TrainBuilder& other);
	~TrainBuilder();

	void operator = (const TrainBuilder& other);

	TrainBuilder& addCrew(Person* crew);

	TrainBuilder& addCarriage(Carriage::Type type);
	TrainBuilder& setPlatform(Platform* platform);

	Train build();
};

