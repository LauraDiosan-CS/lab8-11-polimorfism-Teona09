#pragma once
#include "Serializer.h"
#include"Series.h"
#include"Drone.h"
#include"Phone.h"
#include<sstream>
using namespace std;

class SerializerSeries :
	public Serializer<Series*>{
public:
	SerializerSeries(){}
	Series* fromString(string, char);
	string toString(Series*, char);
	Series* goodObj(Series*);
	bool isEqual(Series*, Series*);
	~SerializerSeries(){}
};

