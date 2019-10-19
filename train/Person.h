#ifndef __PERSON_H
#define __PERSON_H

class Person
{
private:
	char* name;
	Person(const Person& other);

public:
	Person(const char* name);
	virtual ~Person();

	virtual void show() const;

	char* get_name() const;
	void set_name(const char* name);
};

#endif