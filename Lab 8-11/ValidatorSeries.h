#pragma once
#include "Series.h"
#include"MyExceptionList.h"
using namespace std;

class ValidatorSeries
{public:
	ValidatorSeries() {}
	void validate(Series* series) {
		vector<string> errors;
		if (series->getUnits() < 100)
			errors.push_back(string("Your series have less that 100 units!\n"));
		if (errors.size() > 0)
			throw MyExceptionList(errors);
	}
	~ValidatorSeries() {}
};

