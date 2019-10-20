#ifndef __TRAIN_H
#define __TRAIN_H

#include <iostream>
#include <string>

#include "Carriage.h"
#include "Passanger.h"
#include "Platform.h"
#include "Person.h"
#include "Driver.h"
#include "Driver_Conductor.h"

constexpr int MAX_NUMBER_OF_CREW_MEMBERS = 5;
constexpr int MAX_NUMBER_OF_CARRAIGES = 20;
constexpr int MAX_NUMBER_OF_PASSENGERS = 20;

class Passanger;
class Platform;
class Carriage;

class Train
{
public:
	

private:
	int number_of_passangers = 0;
	int number_of_carriages = 0;
	int number_of_crew_members = 0;

	Platform* platform;
	Carriage* carriages[MAX_NUMBER_OF_CARRAIGES];
	const Person* crew_members[MAX_NUMBER_OF_CREW_MEMBERS];
	const Passanger* passangers[MAX_NUMBER_OF_PASSENGERS];

public:
	Train(Platform* platform);
	Train(const Train& train);
	~Train();

	//regular functions:

	const Platform* get_platform() const;
	void set_platform(Platform* platform);

	const Passanger* get_passanger(string name);
	const Person* get_crewmember(string name);

	int get_number_of_crew_member() const;
	int get_number_of_carriage() const;
	int get_number_of_passangers() const;

	void add_carriage(Carriage::Type type);
	void remove_carriage(Carriage::Type type);

	void add_crew_member(const Person& person);
	void remove_crew_member(const Person& person);

	void add_passanger(const Passanger& passanger);
	void remove_passanger(const Passanger& passanger);

	void remove_all_passangers();

	bool can_passanger_board() const;
	bool has_passangers_onboard() const;
	bool is_passanger_onboard(const Passanger& passenger) const;
	bool are_there_drivers() const;
	bool is_there_conductor() const;
	bool is_there_engine() const;
	bool can_train_depart() const;

	void show() const;

	//operators:

	friend std::ostream& operator<<(std::ostream& os, const Train& Train);
	friend std::ostream& operator<<(std::ostream& os, const Train* Train);

	const Train& operator=(const Train& other);
	
	const Train& operator+=(const Carriage& carriage);		
	const Train& operator-=(const Carriage& carriage);
	
	const Train& operator+=(const Person& crewmember);
	const Train& operator-=(const Person& crewmember);
	
	const Train& operator+=(const Passanger& passanger);
	const Train& operator-=(const Passanger& passanger);
};

#endif