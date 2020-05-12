#pragma once
#include"Phone.h"
#include"Series.h"
#include"MyExceptionList.h"
using namespace std;
class ValidatorPhone{
public:
	ValidatorPhone(){}
	void validate(Phone phone) {
		vector<string> errors;
		if (phone.getUnits() < 100)
			errors.push_back(string("Your series have less that 100 units\n"));
		if (phone.getOperators().empty())
			errors.push_back(string("No operators in the list\n"));
		if (errors.size() > 0)
			throw MyExceptionList(errors);
	}
	~ValidatorPhone(){}
};

