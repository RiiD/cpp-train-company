#ifndef __TRAIN_H
#define __TRAIN_H

#include <iostream>

#include "Carriage.h"
#include "Passanger.h"
#include "Station.h"
#include "Person.h"
#include "Driver.h"
#include "Driver_Conductor.h"

constexpr int MAX_NUMBER_OF_CREW_MEMBERS = 5;
constexpr int MAX_NUMBER_OF_CARRAIGES = 20;
constexpr int MAX_NUMBER_OF_PASSENGERS = 20;

class Passanger;
class Station;
class Carriage;

class Train
{
public:
	

private:
	int number_of_passangers = 0;
	int number_of_carriages = 0;
	int number_of_crew_members = 0;

	const Station* station;
	Carriage* carriages[MAX_NUMBER_OF_CARRAIGES];
	const Person* crew_members[MAX_NUMBER_OF_CREW_MEMBERS];
	const Passanger* passangers[MAX_NUMBER_OF_PASSENGERS];

	Train(const Train& train);

public:
	Train(const Station* station); 
	~Train();

	//regular functions:

	const Station* get_station() const;
	void set_station(const Station* station);

	const Passanger* get_passanger(char* name);
	const Person* get_crewmember(char* name);

	int get_number_of_crew_member() const;
	int get_number_of_carriage() const;
	int get_number_of_passangers() const;

	void add_carriage(Carriage::Type type);
	void remove_carriage(Carriage::Type type);

	void add_crew_member(const Person* person);
	void remove_crew_member(const Person* person);

	void add_passanger(const Passanger* passanger);
	void remove_passanger(const Passanger* passanger);

	void remove_all_passangers();

	bool can_passanger_board() const;
	bool has_passangers_onboard() const;
	bool is_passanger_onboard(const Passanger* passenger) const;
	bool are_there_drivers() const;
	bool is_there_conductor() const;
	bool is_there_engine() const;
	bool can_train_depart() const;

	void show() const;

	//operators:

	friend std::ostream& operator<<(std::ostream& os, const Train& Train);

	const Train& operator=(const Train& other);
	
	const Train& operator+(const Carriage* carriage);		
	const Train& operator-(const Carriage* carriage);	
	
	const Train& operator+(const Person* crewmember);
	const Train& operator-(const Person* crewmember);
	
	const Train& operator+(const Passanger* passanger);		
	const Train& operator-(const Passanger* passanger);		
};

#endif