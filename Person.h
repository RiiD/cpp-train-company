#ifndef __PERSON_H
#define __PERSON_H

class Person
{
private:
	char* name;
	Person(const Person& person);

public:
	Person(const char* name);
	~Person();

	virtual void show() const;

	char* get_name() const;
	void set_name(const char* name);
};

#endif
