#include "pch.h"

#pragma warning(disable: 4996)
#include <iostream>
#include <cstring>

#include "Train.h"

using namespace std;

Train::Train(Platform* platform)
{
	this->platform = platform;
}

Train::Train(const Train& other)
{
	number_of_passangers = other.number_of_passangers;
	number_of_carriages = other.number_of_carriages;
	number_of_crew_members = other.number_of_crew_members;

	platform = other.platform;
	platform->set_train(this);

	for (int i = 0; i < number_of_crew_members; i++)
	{
		crew_members[i] = other.crew_members[i]->clone();
	}

	for (int i = 0; i < number_of_passangers; i++)
	{
		passangers[i] = new Passanger(*other.passangers[i]);
	}

	for (int i = 0; i < number_of_carriages; i++)
	{
		carriages[i] = new Carriage(other.carriages[i]->get_carriage_type());
	}
}

Train:: ~Train()
{
	for (int i = 0; i < number_of_carriages; i++)
	{
		delete carriages[i];
	}

	for (int i = 0; i < number_of_passangers; i++)
	{
		delete passangers[i];
	}

	for (int i = 0; i < number_of_crew_members; i++)
	{
		delete crew_members[i];
	}

	if (platform->get_train_in_platform() == this) {
		platform->set_train(nullptr);
	}
}

const Platform* Train::get_platform() const
{
	return platform;
}

void Train::set_platform(Platform* platform)
{

	if (this->platform->get_train_in_platform() == this) {
		this->platform->set_train(nullptr);
	}
	this->platform = platform;
	platform->set_train(this);
}

const Passanger* Train::get_passanger(char* name)
{
	for (int i = 0; i < number_of_passangers; i++)
	{
		if (strcmp(this->passangers[i]->get_name(), name) == 0)
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
		if (strcmp(this->crew_members[i]->get_name(), name) == 0)
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

void Train::add_crew_member(const Person& person)
{
	this->crew_members[number_of_crew_members] = person.clone();
	number_of_crew_members++;
}

void Train::remove_crew_member(const Person& person)
{
	   int found = -1;

		for (int i = 0; i < number_of_crew_members; i++)
		{
			if (strcmp(crew_members[i]->get_name(), person.get_name()) == 0)
			{
				found = i;
			}
		}
	
		if (found >= 0)
		{
			delete crew_members[found];
			for (int i = found; i < number_of_crew_members - 1; ++i)
			{
				crew_members[i] = crew_members[i + 1];
			}
			number_of_crew_members--;
		}
}

void Train::add_passanger(const Passanger& passanger)
{
	if (!is_passanger_onboard(passanger))
	{
		this->passangers[number_of_passangers] = new Passanger(passanger);
		number_of_passangers++;
	}
}

void Train::remove_passanger(const Passanger& passanger)
{
	int found = -1;

	for (int i = 0; i < number_of_passangers; i++)
	{
		if (strcmp(passangers[i]->get_name(), passanger.get_name()) == 0)
		{
			found = i;
		}
	}

	if (found > 0)
	{
		delete passangers[found];
		for (int i = found; i < number_of_passangers - 1; ++i)
		{
			passangers[i] = passangers[i + 1];
		}
		number_of_passangers--;
	}
}

void Train::remove_all_passangers()
{
	for (int i = 0; i < number_of_passangers; i++)
	{
		delete passangers[i];
	}

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

bool Train:: is_passanger_onboard(const Passanger& passenger) const
{
	for (int i = 0; i < number_of_passangers; i++)
	{
		if (strcmp(this->passangers[i]->get_name(), passenger.get_name()) == 0)
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

bool Train::is_there_conductor() const
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

const  Train& Train::operator=(const Train& other)
{
	for (int i = 0; i < number_of_carriages; i++) {
		delete carriages[i];
	}

	for (int i = 0; i < number_of_passangers; i++) {
		delete passangers[i];
	}

	for (int i = 0; i < number_of_crew_members; i++) {
		delete crew_members[i];
	}

	number_of_carriages = other.number_of_carriages;
	number_of_crew_members = other.number_of_crew_members;
	number_of_passangers = other.number_of_passangers;

	for (int i = 0; i < number_of_carriages; i++) {
		carriages[i] = new Carriage(other.carriages[i]->get_carriage_type());
	}

	for (int i = 0; i < number_of_crew_members; i++) 
	{
		crew_members[i] = other.crew_members[i]->clone();
	}

	for (int i = 0; i < number_of_passangers; i++)
	{
		passangers[i] = new Passanger(*other.passangers[i]);
	}

	platform = other.platform;
	platform->set_train(this);

	return *this;
}

const Train& Train::operator+=(const Carriage& carriage)
{
	add_carriage(carriage.get_carriage_type());
	return *this;

}
const Train& Train::operator-=(const Carriage& carriage)
{
	remove_carriage(carriage.get_carriage_type());
	return *this;
}

const Train& Train:: operator+=(const Person& crewmember)
{
	add_crew_member(crewmember);
	return *this;
}

const Train& Train:: operator-=(const Person& crewmember)
{
	remove_crew_member(crewmember);
	return *this;
}

const Train& Train:: operator+=(const Passanger& passanger)
{
	add_passanger(passanger);
	return *this;
}
const Train& Train:: operator-=(const Passanger& passanger)
{
	remove_passanger(passanger);
	return *this;
}

void Train:: show() const
{
	cout << *this << endl;
}

 std::ostream& operator<<(std::ostream& os, const Train& train)
{
	 return os << &train;
}

 std::ostream & operator<<(std::ostream & os, const Train * train)
 {
	 os << "Train ";
	 if (train->platform != nullptr)
	 {
		 os << "on platform " << train->platform;
	 }
	 return os 
		 << " with "
		 << train->number_of_carriages << " carriages, " 
		 << train->number_of_crew_members << " crew members and "
		 << train->number_of_passangers << "passangers";
 }
