#ifndef __PERSON_H
#define __PERSON_H

#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
	string name;

public:
	Person(string name);
	virtual ~Person() 
	{
	}

	virtual void show() const;
	virtual ostream& dynamic_ostream(ostream& os, const Person* person) const = 0;

	string get_name() const;
	void set_name(string name);

	virtual Person* clone() const =0;

	friend std::ostream& operator<<(std::ostream& os, const Person* person);

	bool operator == (const Person& person);
};

#endif