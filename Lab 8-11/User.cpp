#include "User.h"

User::User(){
	username = "";
	password = "";
}

User::User(string u, string p) :username(u), password(p){}

User::User(string line, char delim) {
	vector<string> tok = splitLine(line, delim);
	this->username = tok[0];
	this->password = tok[1];
}

void User::fromString(string line, char delim) {
	vector<string> tokens = splitLine(line, delim);
	this->username = tokens[0];
	this->password = tokens[1];
}

User* User::clone() {
	User* newUser = new User();
	newUser->setUsername(this->username);
	newUser->setPassword(this->password);
	return newUser;
}

string User::getUsername(){
	return username;
}

string User::getPassword(){
	return password;
}

void User::setUsername(string u){
	username = u;
}

void User::setPassword(string p){
	password = p;
}

bool User::operator==(const User& u){
	return (username == u.username) and (password == u.password);
}

string User::toString(){
	return username + " " + password;
}

string User::toStringDelimiter(char delimiter){
	return username + delimiter + password;
}


User::~User(){}
