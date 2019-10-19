#ifndef __PERSON_H
#define __PERSON_H

#include <iostream>

using namespace std;

class Person
{
private:
	char* name;
	

public:
	Person(const char* name);
	Person(const Person& other);
	virtual ~Person();

	virtual void show() const;
	virtual ostream& dynamic_ostream(ostream& os, const Person* person) const = 0;

	char* get_name() const;
	void set_name(const char* name);

	virtual Person* clone() const =0;

	friend std::ostream& operator<<(std::ostream& os, const Person* person);
};

#endif