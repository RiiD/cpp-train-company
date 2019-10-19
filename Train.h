#ifndef __TRAIN_H
#define __TRAIN_H

#define MAX_NUMBER_OF_CREW_MEMBERS 5
#define MAX_NUMBER_OF_CARRAIGES 20

#include <iostream>
#include "Carriage.h"
#include "Passanger.h"
#include "Station.h"

class Train
{
private:
	Station* station;
	Carriage* carriages[MAX_NUMBER_OF_CARRAIGES]; 
	Person* crew_members[MAX_NUMBER_OF_CREW_MEMBERS];
	Passanger* passangers[];

public:
	Train(const Station& station); 
	Train(const Train& train);
	~Train();

	//regular functions:

	Station* get_station() const;
	void set_station(const Station* station);
	Passanger* get_passanger(char* name);
	Person* get_crewmember(char* name);

	void add_carriage(Carriage* carriage);
	void remove_carriage(Carriage_Type type);
	void add_crew_member(Person* person);
	void remove_crew_member(Person* person);
	void add_passanger(Passanger* passanger);
	void remove_passanger(Passanger* passanger);
	void remove_all_passangers();

	bool can_passanger_board() const;
	bool has_passangers_onboard() const;
	bool is_passanger_onboard(char* name) const;
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
	const Train& operator+=(const Carriage* carriage);	
	const Train& operator-=(const Carriage* carriage);	
	
	const Train& operator+(const Person* crewmember);
	const Train& operator-(const Person* crewmember);
	const Train& operator+=(const Person* crewmember);
	const Train& operator-=(const Person* crewmember);
	
	const Train& operator+(const Passanger* passanger);		
	const Train& operator-(const Passanger* passanger);		
	const Train& operator+=(const Passanger* passanger);	
	const Train& operator-=(const Passanger* passanger);	

};

#endif