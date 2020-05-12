#include "SerializerSeries.h"
#include<string>

Series* SerializerSeries::fromString(string line, char delim) {
	vector<string> tokens;
	stringstream ss(line);
	string item;
	while (getline(ss, item, delim)) {
		tokens.push_back(item);
	}
	if (tokens.size() == 4) {
		try {
			int i = stoi(tokens[3]);
			Series* a = new Drone(line, delim);
			return a;
		}
		catch (...) {
			Series* a = new Phone(line, delim);
			return a;
		}
	}
}

string SerializerSeries::toString(Series* series, char delim) {
	return series->toStringDelimiter(delim);
}

Series* SerializerSeries::goodObj(Series* series) {
	return series->clone();
}

bool SerializerSeries::isEqual(Series* s1, Series* s2) {
	if (s1->toString().compare(s2->toString()) == 0)
		return true;
	return false;
}