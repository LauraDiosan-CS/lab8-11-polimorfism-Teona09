#pragma once
#include"Square.h"
#include"Fleet.h"
#include<iostream>
using namespace std;

class Game2
{
private:
	Fleet humanFleet;
	Fleet AIFleet;
	bool winner = false;
	int numberOfShips = 3;
public:
	Game2() {}
	void printInitialTable(Fleet fleet) {
		vector<vector<Square>> table = fleet.printPlayerTable();
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
	void printBattleTable(Fleet fleet) {
		vector<vector<Square>> table = fleet.printPlayerTable();
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
	void humanTurn();
	void AITurn();
	void play();
	void receiveGuess(Square&, Fleet&);
	void humanPlacePlanes();
	Square humanMakeGuess();
	void AIPlacePlanes();
	Square AIMakeGuess();
	~Game2() {}
};
