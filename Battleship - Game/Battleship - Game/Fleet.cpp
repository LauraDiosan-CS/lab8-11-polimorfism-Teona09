#include "Fleet.h"
#include<iostream>

Fleet::Fleet() {
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 12; j++)
			table[i][j] = Square(i, j);
}

int Fleet::findAirplaneIndex(const Square& square) const {
	for (int i = 0; i < Airplanes.size(); i++) {
		vector<Square> AirplaneSquares = Airplanes[i].getSquares();
		for (int j = 0; j < Airplanes[i].getSquares().size(); j++) {
			if (AirplaneSquares[j] == square) {
				return i;
			}
		}
	}
	return -1;
}

bool Fleet::checkPositionForSquare(const Square& square) const {
	if (square.getX() < 0 || square.getX() >= 10 ||
		square.getY() < 0 || square.getY() >= 10 ||
		table[square.getX()][square.getY()].getOccupied() == 'A')
		return false;
	return true;
}

bool Fleet::checkPositionForAirplane(const Airplane& Airplane) const {
	auto startSquare = Airplane.getStartSquare();
	auto horizontal = Airplane.isHorizontal();
	int dirX[] = { 0,0,0,0,1,2,1,-1,-2,-1 };
	int dirY[] = { 0,1,2,3,1,1,3,1,1,3 };
	if (horizontal) {
		for (int i = 0; i < 10; i++) {
			Square square(startSquare.getX() + dirX[i], startSquare.getY() + dirY[i]);
			if (!checkPositionForSquare(square)) {
				return false;
			}
		}
	}
	else {
		for (int i = 0; i < 10; i++) {
			Square square(startSquare.getX() + dirY[i], startSquare.getY() + dirX[i]);
			if (!checkPositionForSquare(square)) {
				return false;
			}
		}
	}
	return true;
}

void Fleet::addAirplane(Airplane Airplane) {
	Airplanes.push_back(Airplane);
	markAirplaneSquares(Airplane);
}

void Fleet::markAirplaneSquares(const Airplane& airplane) {
	vector<Square> planeSquares = airplane.getSquares();
	for (int i = 0; i < planeSquares.size(); i++) {
		int x = planeSquares[i].getX();
		int y = planeSquares[i].getY();
		this->table[x][y].setOccupied();
	}
}
char Fleet::fire(const Square& square) {
	int attackedAirplane = findAirplaneIndex(square);
	char newState = 'O';

	if (attackedAirplane == -1) {
		newState = 'M';
		this->table[square.getX()][square.getY()].setState(newState);
		return newState;
	}

	newState = 'H';
	this->table[square.getX()][square.getY()].setState(newState);
	Airplanes[attackedAirplane].setHealth(Airplanes[attackedAirplane].getHealth() - 1);
	cout << Airplanes[attackedAirplane].getHealth() << endl;

	if (Airplanes[attackedAirplane].getStartSquare() == square) {
		newState = 'D';
		Airplanes[attackedAirplane].setHealth(0);
		markDestroyedAirplane(Airplanes[attackedAirplane]);
		return newState;
	}
	else
		if (Airplanes[attackedAirplane].getHealth() == 0) {
			newState = 'D';
			markDestroyedAirplane(Airplanes[attackedAirplane]);
			return newState;
		}
		else
			return newState;
}

void Fleet::markDestroyedAirplane(const Airplane& airplane) {
	vector<Square> planeSquares = airplane.getSquares();
	for (int i = 0; i < planeSquares.size(); i++) {
		int x = planeSquares[i].getX();
		int y = planeSquares[i].getY();
		this->table[x][y].setState('D');
	}
}

bool Fleet::hasAttacked(const Square& square) const {
	return table[square.getX()][square.getY()].getState() != 'O';
}

int Fleet::getHealth() const {
	int sumHPs = 0;
	for (int i = 0; i < Airplanes.size(); i++) {
		sumHPs += Airplanes[i].getHealth();
	}
	return sumHPs;
}

bool Fleet::isDestroyed() const {
	return !getHealth();
}

Square Fleet::getSquare(int x, int y) const {
	return this->table[x][y];
}

//void Fleet::printBattleTable() {
//	cout << "  ";
//	for (int i = 0; i < 10; i++)
//		cout << " | " << i + 1;
//	cout << endl;
//	for (int i = 0; i < 10; i++) {
//		cout << i;
//		cout << "  | " << table[i][0].getState();
//		for (int j = 1; j < 10; j++)
//			cout << " | " << table[i][j].getState();
//		cout << endl;
//	}
//}

vector<vector<Square>> Fleet::printPlayerTable() {

	//cout << "  ";
	//for (int i = 0; i < 10; i++)
	//	cout << " | " << i;
	//cout << endl;
	//for (int i = 0; i < 10; i++) {
	//	cout << i;
	//	cout << "  | " << table[i][0].getOccupied();
	//	for (int j = 1; j < 10; j++)
	//		cout << " | " << table[i][j].getOccupied();
	//	cout << endl;
	//}
	vector<vector<Square>> playerTable;
	for (int i = 0; i < 10; i++) {
		vector<Square> line;
		for (int j = 0; j < 10; j++)
			line.push_back(table[i][j]);
		playerTable.push_back(line);
	}
	return playerTable;
}

vector<Airplane> Fleet::getAirplanes() const {
	return this->Airplanes;
}