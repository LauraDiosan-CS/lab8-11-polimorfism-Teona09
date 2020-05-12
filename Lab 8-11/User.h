#pragma once
#include<string>
#include<vector>
#include"Utils.h"
using namespace std;

class User
{
private:
	string username;
	string password;
public:
	User();
	User(string, string);
	User(string, char);
	void fromString(string, char);
	User* clone();
	string getUsername();
	string getPassword();
	void setUsername(string);
	void setPassword(string);
	bool operator==(const User&);
	string toString();
	string toStringDelimiter(char delimiter);
	~User();
};

