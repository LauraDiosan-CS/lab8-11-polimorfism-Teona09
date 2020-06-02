#pragma once
#include"Airplane.h"
#include<vector>
using namespace std;

class Fleet {
private:
	vector<Airplane> Airplanes = {};
	Square table[12][12];
public:
	Fleet();
	bool checkPositionForSquare(const Square&) const;
	bool checkPositionForAirplane(const Airplane& Airplane)const;
	void addAirplane(Airplane Airplane);
	char fire(const Square& square);
	void markAirplaneSquares(const Airplane&);
	bool hasAttacked(const Square& square)const;
	int getHealth()const;
	bool isDestroyed()const;
	Square getSquare(int x, int y)const;

	vector<vector<Square>> printPlayerTable();
	vector<Airplane> getAirplanes()const;
	int findAirplaneIndex(const Square&) const;
	void markDestroyedAirplane(const Airplane& airplane);
};
