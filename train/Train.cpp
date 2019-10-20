#include "pch.h"

#pragma warning(disable: 4996)
#include <iostream>
#include <cstring>
#include <algorithm>

#include "Train.h"
#include "globals.h"

using namespace std;

Train::Train(Platform* platform)
{
	this->platform = platform;
	++created;
}

Train::Train(const Train& other)
{
	*this = other;

	++created;
}

Train:: ~Train()
{
	for_each(carriages.begin(), carriages.end(), [](Carriage* c) { delete c; });
	for_each(passangers.begin(), passangers.end(), [](Passanger* p) { delete p; });
	for_each(crew_members.begin(), crew_members.end(), [](Person* p) { delete p; });

	if (platform->get_train_in_platform() == this) {
		platform->set_train(nullptr);
	}

	--created;
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

const Passanger* Train::get_passanger(string name)
{
	auto it = find_if(passangers.begin(), passangers.end(), [&](Passanger* p) { return name == p->get_name(); });
	if (it != passangers.end())
	{
		return *it;
	}

	return nullptr;
}

const Person* Train::get_crewmember(string name)
{
	auto it = find_if(crew_members.begin(), crew_members.end(), [&](Person* p) { return name == p->get_name(); });
	if (it != crew_members.end())
	{
		return *it;
	}

	return nullptr;
}

int Train::get_number_of_crew_member() const
{
	return crew_members.size();
}

int Train::get_number_of_carriage() const
{
	return carriages.size();
}

int Train::get_number_of_passangers() const
{
	return passangers.size();

}

void Train::add_carriage(Carriage::Type type)
{
	this->carriages.push_back(new Carriage(type));
}

void Train::remove_carriage(Carriage::Type type)
{

	for (auto it = carriages.begin(), end = carriages.end(); it != end; ++it)
	{
		auto c = *it;
		if (c->get_carriage_type() == type)
		{
			carriages.erase(it);
			delete c;
			break;
		}
	}
}

void Train::add_crew_member(const Person& person)
{
	crew_members.push_back(person.clone());
}

void Train::remove_crew_member(const Person& person)
{
	for (auto it = crew_members.begin(), end = crew_members.end(); it != end; ++it)
	{
		auto p = *it;
		if (p->get_name() == person.get_name())
		{
			crew_members.erase(it);
			delete p;
			break;
		}
	}
}

void Train::add_passanger(const Passanger& passanger)
{
	if (!is_passanger_onboard(passanger))
	{
		passangers.push_back(new Passanger(passanger));
	}
}

void Train::remove_passanger(const Passanger& passanger)
{
	for (auto it = passangers.begin(), end = passangers.end(); it != end; ++it)
	{
		Passanger* p = *it;
		if (p->get_name() == passanger.get_name())
		{
			passangers.erase(it);
			delete p;
			break;
		}
	}
}

void Train::remove_all_passangers()
{
	for_each(passangers.begin(), passangers.end(), [](Passanger* p) { delete p; });
	passangers.clear();
}

bool Train::can_passanger_board() const
{
	return any_of(carriages.begin(), carriages.end(), [](Carriage* c) { return c->get_carriage_type() == Passangers; });
}

bool Train::has_passangers_onboard() const
{
	return !passangers.empty();
}

bool Train:: is_passanger_onboard(const Passanger& passenger) const
{
	return any_of(passangers.begin(), passangers.end(), [&](Passanger* c) { return c->get_name() == passenger.get_name(); });
}

bool Train::are_there_drivers() const
{
	return count_if(crew_members.begin(), crew_members.end(), [&](Person* c)
	{
		return dynamic_cast<const Driver*>(c) != nullptr;
	}) >= 2;
}

bool Train::is_there_conductor() const
{
	return any_of(crew_members.begin(), crew_members.end(), [&](Person* c)
	{
		return dynamic_cast<const Conductor*>(c) != nullptr;
	});
}

bool Train::is_there_engine() const
{
	return any_of(carriages.begin(), carriages.end(), [](Carriage* c) { return c->get_carriage_type() == Engine; });
}

bool Train::can_train_depart() const
{
	return is_there_engine() && is_there_conductor() && are_there_drivers();
}

const  Train& Train::operator=(const Train& other)
{
	for_each(carriages.begin(), carriages.end(), [](Carriage* c) { delete c; });
	for_each(passangers.begin(), passangers.end(), [](Passanger* p) { delete p; });
	for_each(crew_members.begin(), crew_members.end(), [](Person* p) { delete p; });

	platform = other.platform;
	platform->set_train(this);

	crew_members.resize(other.crew_members.size());
	transform(other.crew_members.begin(), other.crew_members.end(), crew_members.begin(), [](Person* p) { return p->clone(); });

	passangers.resize(other.passangers.size());
	transform(other.passangers.begin(), other.passangers.end(), passangers.begin(), [](Passanger* p) { return new Passanger(*p); });

	carriages.resize(other.carriages.size());
	transform(other.carriages.begin(), other.carriages.end(), carriages.begin(), [](Carriage* c) { return new Carriage(c->get_carriage_type()); });

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
		 << train->carriages.size() << " carriages, " 
		 << train->crew_members.size() << " crew members and "
		 << train->passangers.size() << "passangers";
 }
