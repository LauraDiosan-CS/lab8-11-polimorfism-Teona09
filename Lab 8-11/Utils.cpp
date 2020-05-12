#include "Utils.h"
#include <sstream>
#include <iostream>
using namespace std;

vector<string> splitLine(string linie, char delim)
{

	std::stringstream ss(linie);
	std::string item;
	std::vector<std::string> elems;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}
