#include "Drone.h"
#include <string>
Drone::Drone() :Series() {
	this->rotorsNumber = 0;
}

Drone::Drone(const char* producerName, const char* modelName, int units, int rotors) :
	Series(producerName, modelName, units) {
	/*this->producerName = new char[strlen(producerName) + 1];
	strcpy_s(this->producerName, strlen(producerName) + 1, producerName);
	this->modelName = new char[strlen(modelName) + 1];
	strcpy_s(this->modelName, strlen(modelName) + 1, modelName);
	this->units = units;*/
	this->rotorsNumber = rotors;
}

Drone::Drone(const Drone& drone):Series(drone) {
	this->rotorsNumber = drone.rotorsNumber;
}

Drone::Drone(string line, char delim) {
	vector<string> tokens = splitLine(line, delim);
	this->producerName = new char[tokens[0].length() + 1];
	strcpy_s(this->producerName, tokens[0].length() + 1, tokens[0].c_str());
	this->modelName = new char[tokens[1].length() + 1];
	strcpy_s(this->modelName, tokens[1].length() + 1, tokens[1].c_str());
	this->units = stoi(tokens[2]);
	this->rotorsNumber = stoi(tokens[3]);
}

Drone::~Drone(){}

void Drone::setRontorsNumber(int rotors) {
	this->rotorsNumber = rotors;
}
int Drone::getRotorsNumber() {
	return this->rotorsNumber;
}

string Drone::toString(){
	string producer = this->producerName;
	string model = this->modelName;
	return (producer + ' ' + model + ' ' + to_string(this->units)+
		' '+ to_string(this->rotorsNumber));
}

string Drone::toStringDelimiter(char delim){
	string producer = this->producerName;
	string model = this->modelName;
	return (producer + delim + model + delim + to_string(this->units)
		+ delim + to_string(this->rotorsNumber));
}

Drone& Drone::operator=(const Drone& drone) {
	if (this != &drone)
	{
		Series::operator=(drone);
		this->rotorsNumber = drone.rotorsNumber;
	}
	return *this;
}

bool Drone::operator==(const Drone& drone) {
	return (Series::operator==(drone) &&(this->rotorsNumber==drone.rotorsNumber));
}

Series* Drone::clone() {
	Drone* newDrone = new Drone();
	newDrone->setProducerName(this->producerName);
	newDrone->setModelName(this->modelName);
	newDrone->setUnits(this->units);
	newDrone->setRontorsNumber(this->rotorsNumber);
	return newDrone;
}

ostream& operator<<(ostream& os, Drone& drone) {
	os << drone.toString();
	return os;
}

istream& operator>>(istream& is, Drone& c)
{
	cout << "Producer Name: ";
	char* producer = new char[20];
	is >> producer;
	cout << "Model Name: ";
	char* model = new char[20];
	is >> model;
	cout << "Number of products: ";
	int unit;
	is >> unit;
	cout << "Number of rotors: ";
	int nr;
	is >> nr;
	c.setProducerName(producer);
	c.setModelName(model);
	c.setUnits(unit);
	c.setRontorsNumber(nr);
	delete[] producer;
	delete[] model;
	return is;
}
