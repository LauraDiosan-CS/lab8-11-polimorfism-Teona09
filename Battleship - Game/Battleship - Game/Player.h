#pragma once
#include<iostream>
#include"Square.h"
#include"Airplane.h"
#include"Fleet.h"
using namespace std;

class Player
{
protected:
	Fleet playerFleet;
	int numberOfPlanes = 1;
public:
	Player() {};
	virtual void placePlanes() = 0;
	virtual Square makeGuess() = 0;
	virtual void receiveGuess(Square&) = 0;
	int healthLeft() {
		return playerFleet.getHealth();
	}
	bool verifyGuess(Square& s) {
		return !playerFleet.hasAttacked(s);
	}
	void printPlayerTable() {
		vector<vector<Square>> table = playerFleet.printPlayerTable();
		cout << "  ";
		for (int i = 0; i < 10; i++)
			cout << " | " << i;
		cout << endl;
		for (int i = 0; i < table.size(); i++) {
			cout << i;
			cout << "  | " << table[i][0].getOccupied();
			for (int j = 1; j < table[i].size(); j++)
				cout << " | " << table[i][j].getOccupied();
			cout << endl;
		}
	}
	void printBattleTable() {
		vector<vector<Square>> table = playerFleet.printPlayerTable();
		cout << "  ";
		for (int i = 0; i < 10; i++)
			cout << " | " << i;
		cout << endl;
		for (int i = 0; i < table.size(); i++) {
			cout << i;
			cout << "  | " << table[i][0].getState();
			for (int j = 1; j < table[i].size(); j++)
				cout << " | " << table[i][j].getState();
			cout << endl;
		}
	}
	virtual ~Player() {};
};
