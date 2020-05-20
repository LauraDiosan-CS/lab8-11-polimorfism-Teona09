#pragma once
#include"Ship.h"
#include"FireResult.h"
#include<vector>
using namespace std;

class Fleet{
private:
	vector<Ship> ships;
	Square::State squaresState[10][10];
	bool checkPositionForSquare(const Square&) const;
public:
	Fleet();
	bool checkPositionForShip(const Ship& ship)const;
	void addShip(Ship ship);
	FireResult fire(const Square& square);
	bool hasAttacked(const Square& square)const;
	int getHealth()const;
	bool isDestroyed()const;
	Square::State getSquareState(int x, int y)const;
	void printSquaresState();
	vector<Ship> getShips()const;
	int findShipIndex(const Square&) const;
};

