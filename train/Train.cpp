#include "pch.h"

#pragma warning(disable: 4996)
#include <iostream>
#include <cstring>

#include "Train.h"

using namespace std;

Train::Train(const Station* station)
{
	this->station = station;
}

Train:: ~Train()
{
	for (int i = 0; i < number_of_carriages; i++)
	{
		delete carriages[i];
	}
}

const Station* Train::get_station() const
{
	return station;
}

void Train::set_station(const Station* station)
{
	this->station = station;
}

const Passanger* Train::get_passanger(char* name)
{
	for (int i = 0; i < number_of_passangers; i++)
	{
		if (strcmp(this->passangers[i]->get_name(), name))
		{
			return this->passangers[i];
		}
	}
	return nullptr;
}

const Person* Train::get_crewmember(char* name)
{
	for (int i = 0; i < number_of_crew_members; i++)
	{
		if (strcmp(this->crew_members[i]->get_name(), name))
		{
			return this->crew_members[i];
		}
	}
	return nullptr;
}

int Train::get_number_of_crew_member() const
{
	return number_of_crew_members;
}

int Train::get_number_of_carriage() const
{
	return number_of_carriages;
}

int Train::get_number_of_passangers() const
{
	return number_of_passangers;

}

void Train::add_carriage(Carriage::Type type)
{
	this->carriages[number_of_carriages] = new Carriage(type);
	number_of_carriages++;
}

void Train::remove_carriage(Carriage::Type type)
{
	int found = -1;

	for (int i = 0; i < number_of_carriages; i++)
	{
		if (this->carriages[i]->get_carriage_type() == type)
		{
			found = i;
			break;
		}
	}

	if (found >= 0)
	{
		delete this->carriages[found];
		for (int i = found; i < number_of_carriages - 1; ++i)
		{
			this->carriages[i] = this->carriages[i + 1];
		}
		number_of_carriages--;
	}
}

void Train::add_crew_member(const Person* person)
{
	this->crew_members[number_of_crew_members] = person;
	number_of_crew_members++;
}

void Train::remove_crew_member(const Person* person)
{
	   int found = -1;

		for (int i = 0; i < number_of_crew_members; i++)
		{
			if (strcmp(this->crew_members[i]->get_name(), person->get_name()))
			{
				found = i;
			}
		}
	
		if (found >= 0)
		{
			for (int i = found; i < number_of_crew_members - 1; ++i)
			{
				this->crew_members[i] = this->crew_members[i + 1];
			}
			number_of_crew_members--;
		}
}

void Train::add_passanger(const Passanger* passanger)
{
	if (!is_passanger_onboard(passanger))
	{
		this->passangers[number_of_passangers] = passanger;
		number_of_passangers++;
	}
}

void Train::remove_passanger(const Passanger* passanger)
{
	int found = -1;

	for (int i = 0; i < number_of_passangers; i++)
	{
		if (this->passangers[i] == passanger)
		{
			found = i;
		}
	}

	if (found > 0)
	{
		for (int i = found; i < number_of_passangers - 1; ++i)
		{
			this->passangers[i] = passangers[i + 1];
		}
		number_of_passangers--;
	}
}

void Train::remove_all_passangers()
{
	number_of_passangers = 0;
}

bool Train::can_passanger_board() const
{
	for (int i = 0; i < number_of_carriages; i++)
	{
		if (this->carriages[i]->get_carriage_type() == Carriage::Type::Passangers)
		{
			return true;
		}
	}

	return false;
}

bool Train::has_passangers_onboard() const
{
	return number_of_passangers > 0;
}

bool Train:: is_passanger_onboard(const Passanger* passenger) const
{
	for (int i = 0; i < number_of_passangers; i++)
	{
		if (this->passangers[i] == passenger)
		{
			return true;
		}
	}
	return false;
}

bool Train:: are_there_drivers() const
{
	int counter = 0;

	for (int i = 0; i < number_of_crew_members; i++)
	{
		const Driver* driver = dynamic_cast<const Driver*>(crew_members[i]);
		const Driver_Conductor* driver_conductor = dynamic_cast<const Driver_Conductor*>(crew_members[i]);

		if (driver != nullptr || driver_conductor != nullptr)
		{
			counter++;
			if (counter >= 2)
			{
				return true;
			}
		}
	}
	return false;
}

bool Train:: is_there_conductor() const
{
		for (int i = 0; i < number_of_crew_members; i++)
		{
			const Conductor* conductor = dynamic_cast<const Conductor*>(crew_members[i]);
			const Driver_Conductor* driver_conductor = dynamic_cast<const Driver_Conductor*>(crew_members[i]);

			if (conductor != nullptr || driver_conductor != nullptr)
			{
				return true;
			}
		}
		return false;
}

bool Train::is_there_engine() const
{
	for (int i = 0; i < number_of_carriages; i++)
	{
		if (this->carriages[i]->get_carriage_type() == Engine)
		{
			return true;
		}
	}

	return false;
}

bool Train::can_train_depart() const
{
	return is_there_engine() && is_there_conductor() && are_there_drivers();
}

const  Train& Train:: operator=(const Train& other)
{
	for (int i = 0; i < number_of_carriages; i++) {
		delete carriages[i];
	}
	number_of_carriages = other.number_of_carriages;
	number_of_crew_members = other.number_of_crew_members;
	number_of_passangers = other.number_of_passangers;



	for (int i = 0; i < number_of_carriages; i++) {
		carriages[i] = new Carriage(other.carriages[i]->get_carriage_type());
	}

	for (int i = 0; i < number_of_crew_members; i++) 
	{
		crew_members[i] = other.crew_members[i];
	}

	for (int i = 0; i < number_of_passangers; i++)
	{
		passangers[i] = other.passangers[i];
	}

	station = other.station;

	return *this;
}

const Train& Train::operator+(const Carriage* carriage)
{
	add_carriage(carriage->get_carriage_type());
	return *this;

}
const Train& Train::operator-(const Carriage* carriage)
{
	remove_carriage(carriage->get_carriage_type());
	return *this;
}

const Train& Train:: operator+(const Person* crewmember)
{
	add_crew_member(crewmember);
	return *this;
}

const Train& Train:: operator-(const Person* crewmember)
{
	remove_crew_member(crewmember);
	return *this;
}

const Train& Train:: operator+(const Passanger* passanger)
{
	add_passanger(passanger);
	return *this;
}
const Train& Train:: operator-(const Passanger* passanger)
{
	remove_passanger(passanger);
	return *this;
}

void Train:: show() const
{
	cout << *this << endl;
}

 std::ostream& operator<<(std::ostream& os, const Train& Train)
{
	 return os << "in this train there are:" << Train.number_of_carriages << "carriages" << Train.number_of_crew_members << "crew members" << Train.number_of_passangers << "passangers";
}