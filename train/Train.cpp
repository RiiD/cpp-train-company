#pragma warning(disable: 4996)
#include <iostream>
#include <cstring>
#include "Train.h"
using namespace std;


Train::Train(const Station& station)
{
	 this->station = new Station(station.get_city());

}

Train::Train(const Train& train)
{

	for(int i=0 ; i< train.get_number_of_carriage;i++)
		this->carriages[i] = new Carriage(train.carriages[i]->get_carriage_type());
	this->number_of_carriages = train.get_number_of_carriage();


	for (int i = 0; i < train.get_crewmember; i++)
		this->crew_members[i] = new Person(train.crew_members[i]->get_name());
	number_of_crew_members = train.get_number_of_crew_member();

	for (int i = 0; i < train.get_number_of_passangers; i++)
		this->passangers[i] = new Passanger(train.passangers[i]->get_name());
	number_of_passangers = train.get_number_of_passangers();
	
	station = new Station(train.station->get_city());
}

Train:: ~Train()
{
	delete[] station;
	delete[] carriages;
	delete[] crew_members;
	this->remove_all_passangers();
}


Station* Train::get_station() const
{
	return this->station;
}

void Train::set_station(const Station* station)
{
	this->station = new Station( station->get_city() );

}

Passanger* Train:: get_passanger(char* name)
{
	for (int i = 0; i < number_of_passangers; i++)
	{
		if (this->passangers[i]->get_name() == name)
		{
			return this->passangers[i];
		}
	}
	return nullptr;

}

Person* Train:: get_crewmember(char* name)
{
	for (int i = 0; i < number_of_crew_members; i++)
	{
		if (this->crew_members[i]->get_name() == name)
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

void Train::add_carriage(const Carriage* carriage) 
{
	this->carriages[number_of_carriages] = new Carriage(carriage->get_carriage_type());
	number_of_carriages++;
}

void Train::remove_carriage(Carriage_Type type)
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


	if (found > 0)
	{
		delete this->carriages[found];             //Destroys the object in question.
		for (int i = found; i < number_of_carriages - 1; ++i)
			this->carriages[i] = this->carriages[i + 1];   //Moves the entire list up by one.
		number_of_carriages--;
	}


}

void Train::add_crew_member(const Person* person)
{
	this->crew_members[number_of_crew_members] = new Person(person->get_name());
	number_of_crew_members++;
}

void Train::remove_crew_member(const Person* person)
{

	   int found = -1;

		for (int i = 0; i < number_of_crew_members; i++)
		{
			if (this->crew_members[i]->get_name() == person->get_name())
			{
				found = i;
			}
		}
	

		if (found > 0)
		{
			delete this->crew_members[found];             //Destroys the object in question.
			for (int i = found; i < number_of_crew_members - 1; ++i)
				this->crew_members[i] = this->crew_members[i + 1];   //Moves the entire list up by one.
			number_of_crew_members--;
		}
	
}

void Train::add_passanger(const Passanger* passanger) // maybe we should change it to bool so we know if the process was succesfull
{


	if (!is_passanger_onboard(passanger->get_name()))
	{
		this->passangers[number_of_passangers] = new Passanger(passanger->get_name());
		number_of_passangers++;
	}
}

void Train::remove_passanger(const Passanger* passanger)
{
	int found = -1;

	if (is_passanger_onboard(passanger->get_name()))
	{
		for (int i = 0; i < number_of_passangers; i++)
		{
			if (this->passangers[i]->get_name() == passanger->get_name())
			{
				found = i;
			}
		}
	}

	if (found > 0)
	{
		delete this->passangers[found];             //Destroys the object in question.
		for (int i = found; i < number_of_passangers - 1; ++i)
			this->passangers[i] = passangers[i + 1];   //Moves the entire list up by one.
		number_of_passangers--;
	}
}

void Train:: remove_all_passangers()
{

	delete[] this->passangers;
	number_of_passangers = 0;
}

bool Train:: can_passanger_board() const
{
	for (int i = 0; i < number_of_carriages; i++)
	{
		if (this->carriages[i]->get_carriage_type() == Passangers)
		{
			return true;
		}
	}

	return false;

}

bool Train::has_passangers_onboard() const
{
	if (number_of_passangers == 0)
	{
		return false;
	}
	return true;
}

bool Train:: is_passanger_onboard(char* name) const
{

	for (int i = 0; i < number_of_passangers; i++)
	{
		if (this->passangers[i]->get_name() == name)
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
		if ((typeid(Driver) == typeid(crew_members[i])) || (typeid(Driver_Conductor) == typeid(crew_members[i])))
		{
			counter++;
			if (counter > 2)
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
			if ((typeid(Conductor) == typeid(crew_members[i])) || (typeid(Driver_Conductor) == typeid(crew_members[i])))
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

	if (is_there_engine() && is_there_conductor() && are_there_drivers())
	{
		return true;
	}
	return false;
}

const  Train& Train:: operator=(const Train& other)
{
	delete[] station;
	delete[] carriages;
	delete[] crew_members;
	this->remove_all_passangers();

	for (int i = 0; i < other.get_number_of_carriage; i++)
		this->carriages[i] = other.carriages[i];
	this->number_of_carriages = other.get_number_of_carriage();


	for (int i = 0; i < other.get_crewmember; i++)
		this->crew_members[i] = other.crew_members[i];
	number_of_crew_members = other.get_number_of_crew_member();

	for (int i = 0; i < other.get_number_of_passangers; i++)
		this->passangers[i] = other.passangers[i];
	number_of_passangers = other.get_number_of_passangers();

	station = other.station;
}

const Train& Train::operator+(const Carriage* carriage)
{
	add_carriage(carriage);
	return *this;

}
const Train& Train::operator-(const Carriage* carriage)
{
	remove_carriage(carriage->get_carriage_type());
	return *this;
}

const Train& Train:: operator+=(const Carriage* carriage) //  not sure what to do here ?
{
	add_carriage(carriage);
	return *this;

}

const Train& Train:: operator-=(const Carriage* carriage) //  not sure what to do here ?
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

const Train& Train:: operator+=(const Person* crewmember) //  not sure what to do here ?
{
	add_crew_member(crewmember);
	return *this;
}

const Train& Train:: operator-=(const Person* crewmember) //  not sure what to do here ?
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


const Train& Train:: operator+=(const Passanger* passanger) //  not sure what to do here ?
{
	add_passanger(passanger);
	return *this;
}

const Train& Train:: operator-=(const Passanger* passanger)  //  not sure what to do here ?
{
	remove_passanger(passanger);
	return *this;
}



void Train:: show() const
{
	

}

 std::ostream& operator<<(std::ostream& os, const Train& Train)
{
	 os << "in this train there are:" << Train.number_of_carriages << "carriages" << Train.number_of_crew_members << "crew members" << Train.number_of_passangers << "passangers";
 }


