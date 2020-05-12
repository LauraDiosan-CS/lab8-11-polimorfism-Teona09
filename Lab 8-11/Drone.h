#pragma once
#include "Series.h"
class Drone :
	public Series
{
private:
	int rotorsNumber;
public:
	Drone();
	Drone(const char*, const char*, int, int);
	Drone(const Drone&);
	Drone(string, char);
	~Drone();
	void setRontorsNumber(int);
	int getRotorsNumber();
	string toString();
	string toStringDelimiter(char);

	Drone& operator=(const Drone&);
	bool operator==(const Drone&);
	Series* clone();

	friend ostream& operator<<(ostream&, Drone&);
	friend istream& operator>>(istream&, Drone&);
};

