#ifndef __CARRIAGE_H
#define __CARRIAGE_H

#include <iostream>

using namespace std;

enum Carriage_Type { Passangers, Cargo, Restaurant, Engine };

class Carriage
{
public:
	enum Type { Passangers, Cargo, Restaurant, Engine };
private:
	const Type type;

	Carriage(const Carriage& carriage);
public:
	Carriage(Type type);

	enum Type get_carriage_type() const;
	
	void show() const; 
	
	friend ostream& operator<<(ostream& os, const Carriage& Carriage);
	
	bool operator==(const Carriage& carriage) const;
	bool operator!=(const Carriage& carriage) const;
};

#endif