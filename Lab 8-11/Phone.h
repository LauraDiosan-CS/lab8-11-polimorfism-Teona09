#pragma once
#include "Series.h"
#include<vector>
using namespace std;

class Phone :
	public Series
{
private:
	vector <string> operators;
public:
	Phone();
	Phone(const char*, const char*, int, vector<string>);
	Phone(const Phone&);
	Phone(string, char);
	~Phone();
	void setOperators(vector <string>);
	vector<string> getOperators();
	void addOperator(string);
	string toString();
	string toStringDelimiter(char);

	Phone& operator=(const Phone&);
	bool operator==(const Phone&);
	Series* clone();

	friend ostream& operator<<(ostream&, Phone&);
	friend istream& operator>>(istream&, Phone&);
};

