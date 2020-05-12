#pragma once
#include<vector>
#include<string>
using namespace std;

class MyExceptionList:public exception
{
private:
	vector<string> errors;

public:
	MyExceptionList(vector<string> err) {
		errors = err;
	}
	vector<string> getErrors() const {
		return this->errors;
	}
};

