#pragma once 

#include<iostream>
#include<string.h>
#include"Utils.h"
using namespace std;

class Series
{
protected:
	char* producerName;
	char* modelName;
	int units;

public:
	Series();
	Series(const char*,const char*, int);
	Series(const Series&);
	Series(string, char);
	char* getProducerName();
	char* getModelName();
	int getUnits();
	void setProducerName(const char*);
	void setModelName(const char*);
	void setUnits(int);
	
	virtual Series* clone()=0;
	virtual Series& operator=(const Series&);
	virtual bool operator==(const Series&);
	virtual bool operator<(const Series&);
	virtual string toString()=0;
	virtual string toStringDelimiter(char)=0;
	virtual ~Series();

	friend ostream& operator<<(ostream&, Series&);
	friend istream& operator>>(istream&, Series&);
};

