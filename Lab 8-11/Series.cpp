#include "Series.h"
#include <string>

Series::Series() {
	this->producerName = NULL;
	this->modelName = NULL;
	this->units = 0;
}

Series::Series(const char* producerName, const char* modelName, int units) {
	this->producerName = new char[strlen(producerName) + 1];
	strcpy_s(this->producerName, strlen(producerName) + 1, producerName);
	this->modelName = new char[strlen(modelName) + 1];
	strcpy_s(this->modelName, strlen(modelName) + 1, modelName);
	this->units = units;
}

Series::Series(const Series& series) {
	this->producerName = new char[strlen(series.producerName) + 1];
	strcpy_s(this->producerName, strlen(series.producerName) + 1, series.producerName);
	this->modelName = new char[strlen(series.modelName) + 1];
	strcpy_s(this->modelName, strlen(series.modelName) + 1, series.modelName);
	this->units = series.units;
}

Series::Series(string line, char delim) {
	vector<string> tokens = splitLine(line, delim);
	this->producerName = new char[tokens[0].length() + 1];
	strcpy_s(this->producerName, tokens[0].length() + 1, tokens[0].c_str());

	this->modelName = new char[tokens[1].length() + 1];
	strcpy_s(this->modelName, tokens[1].length() + 1, tokens[1].c_str());
	units = stoi(tokens[2]);
}

char* Series::getProducerName() {
	return this->producerName;
}

char* Series::getModelName() {
	return this->modelName;
}

int Series::getUnits() {
	return this->units;
}

void Series::setProducerName(const char* newName) {
	if (this->producerName) delete[] this->producerName;
	this->producerName = new char[strlen(newName) + 1];
	strcpy_s(this->producerName, strlen(newName) + 1, newName);
}

void Series::setModelName(const char* newName) {
	if (this->modelName) delete[] this->modelName;
	this->modelName = new char[strlen(newName) + 1];
	strcpy_s(this->modelName, strlen(newName) + 1, newName);
}

void Series::setUnits(int newUnitsNumber) {
	this->units = newUnitsNumber;
}

Series::~Series() {
	if (this->producerName) delete[] this->producerName;
	if (this->modelName) delete[] this->modelName;
	producerName = NULL;
	modelName = NULL;
}

Series& Series::operator=(const Series& series) {
	if (this != &series) {
		if (this->producerName)
			delete[] this->producerName;
		if (this->modelName)
			delete[] this->modelName;
		this->producerName = new char[strlen(series.producerName) + 1];
		strcpy_s(this->producerName, strlen(series.producerName) + 1, series.producerName);
		this->modelName = new char[strlen(series.modelName) + 1];
		strcpy_s(this->modelName, strlen(series.modelName) + 1, series.modelName);
		this->units = series.units;
	}
	return *this;
}

bool Series::operator==(const Series& series) {
	if(series.producerName!=NULL and series.modelName!=NULL)
	return (strcmp(this->producerName, series.producerName) == 0)
		and (strcmp(this->modelName, series.modelName) == 0)
		and (this->units == series.units);
	return false;
}

bool Series::operator<(const Series& series) {
	return (strcmp(this->producerName, series.producerName) < 0);
}

ostream& operator<<(ostream& os, Series& series) {
	os << series.toString();
	return os;
}

istream& operator>>(istream& is, Series& c) {
	cout << "Producer Name: ";
	char* producer = new char[20];
	is >> producer;
	cout << "Model Name: ";
	char* model = new char[20];
	is >> model;
	cout << "Number of products: ";
	int unit;
	is >> unit;
	c.setProducerName(producer);
	c.setModelName(model);
	c.setUnits(unit);
	delete[] producer;
	delete[] model;
	return is;
}