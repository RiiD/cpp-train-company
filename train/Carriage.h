#ifndef __CARRIAGE_H
#define __CARRIAGE_H

#include <iostream>

enum Carriage_Type { Passangers, Cargo, Restaurant, Engine };

class Carriage
{
private:
	enum Carriage_Type type;

	Carriage(const Carriage& carriage);

public:
	Carriage(Carriage_Type type);
	~Carriage();

	enum Carriage_Type get_carriage_type() const;
	
	void show() const; 
	
	friend std::ostream& operator<<(std::ostream& os, const Carriage& Carriage);
	
	bool operator==(const Carriage& carriage) const;
	bool operator!=(const Carriage& carriage) const;
};

#endif