#include "Phone.h"
#include <string>

Phone::Phone() :Series() {
}

Phone::Phone(const char* producerName, const char* modelName, int units, vector<string> vect) :
	Series(producerName, modelName, units) {
	/*this->producerName = new char[strlen(producerName) + 1];
	strcpy_s(this->producerName, strlen(producerName) + 1, producerName);
	this->modelName = new char[strlen(modelName) + 1];
	strcpy_s(this->modelName, strlen(modelName) + 1, modelName);
	this->units = units;*/
	//this->operators.assign(vect.begin(), vect.end());
	this->operators = vect;
}

Phone::Phone(const Phone& phone) : Series(phone) {
	//this->operators.assign(phone.operators.begin(), phone.operators.end());
	this->operators = phone.operators;
}

Phone::Phone(string line, char delim) {
	vector<string> tokens = splitLine(line, delim);
	this->producerName = new char[tokens[0].length() + 1];
	strcpy_s(this->producerName, tokens[0].length() + 1, tokens[0].c_str());

	this->modelName = new char[tokens[1].length() + 1];
	strcpy_s(this->modelName, tokens[1].length() + 1, tokens[1].c_str());

	units = stoi(tokens[2]);

	vector <string> token = splitLine(tokens[3], '-');
	for (int i = 0; i < token.size(); i++) {
		this->operators.push_back(token[i]);
	}
}

Phone::~Phone() {
	this->operators.clear();
}

void Phone::setOperators(vector <string> op) {
	this->operators = op;
	//this->operators.assign(op.begin(), op.end());
}

vector<string> Phone::getOperators() {
	return this->operators;
}

void Phone::addOperator(string op) {
	this->operators.push_back(op);
}

string Phone::toString() {
	string producer = this->producerName;
	string model = this->modelName;
	string op = operators[0];
	for (int i = 1; i < this->operators.size(); i++)
	{
		op = op + "-" + this->operators[i];
	}
	return  producer + " " + model + " " + to_string(this->units) + " " + op;
}
string Phone::toStringDelimiter(char delim) {
	string producer = this->producerName;
	string model = this->modelName;
	string op = operators[0];
	for (int i = 1; i < this->operators.size(); i++)
	{
		op = op + "-" + this->operators[i];
	}
	return  producer + delim + model + delim + to_string(this->units) + delim + op;
}

Phone& Phone::operator=(const Phone& phone) {
	if (this != &phone) {
		Series::operator=(phone);
		operators = phone.operators;
		//this->operators.assign(phone.operators.begin(), phone.operators.end());
	}
	return *this;
}

bool Phone::operator==(const Phone& phone) {
	bool ok = true;
	for (int i = 0; i < operators.size(); i++)
		if (operators[i] != phone.operators[i])
			ok = false;
	return (Series::operator==(phone)&&ok);
}

Series* Phone::clone() {
	Phone* newPhone = new Phone;
	newPhone->setProducerName(this->producerName);
	newPhone->setModelName(this->modelName);
	newPhone->setUnits(this->units);
	newPhone->operators.assign(this->operators.begin(), this->operators.end());
	return newPhone;
}

ostream& operator<<(ostream& os, Phone& phone) {
	os << phone.toString();
	return os;
}

istream& operator>>(istream& is, Phone& c) {
	cout << "Producer Name: ";
	char* producer = new char[20];
	is >> producer;
	cout << "Model Name: ";
	char* model = new char[20];
	is >> model;
	cout << "Number of products: ";
	int unit;
	is >> unit;
	int max;
	cout << "Number of operators: " << endl;
	is >> max;
	vector<string> op;
	char ch[20];
	cout << "List of GSM operators: " << endl;
	for (int j = 0; j < max; j++)
	{
		is >> ch;
		op.push_back(ch);
	}
	c.setProducerName(producer);
	c.setModelName(model);
	c.setUnits(unit);
	c.setOperators(op);
	delete[] producer;
	delete[] model;
	return is;
}