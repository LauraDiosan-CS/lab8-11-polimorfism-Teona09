#include "Fleet.h"
#include<iostream>

Fleet::Fleet() {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			squaresState[i][j] = Square::NOT_ATTACKED;
}

int Fleet::findShipIndex(const Square& square) const {
    for (int i = 0; i < ships.size(); i++) {
        vector<Square> shipSquares = ships[i].getSquares();
        for (int j = 0; j < ships[i].getSquares().size(); j++) {
            if (shipSquares[j] == square) {
                return i;
            }
        }
    }
    return -1;
}

bool Fleet::checkPositionForSquare(const Square& square) const {
    if (square.getX() < 0 || square.getX() >= 10 ||
        square.getY() < 0 || square.getY() >= 10) 
        return false;
    return true;
}

bool Fleet::checkPositionForShip(const Ship& ship) const {
    auto startSquare = ship.getStartSquare();
    auto horizontal = ship.isHorizontal();
    int dirX[] = { 0,0,1,2,-1,-2,0,0,1,-1 };
    int dirY[] = { 0,1,1,1, 1, 1,2,3,3, 3 };
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

void Fleet::addShip(Ship ship) {
    ships.push_back(ship);
}

FireResult Fleet::fire(const Square& square) {
    int attackedShip = findShipIndex(square);

    if (attackedShip == -1) {
        squaresState[square.getX()][square.getY()] = Square::ATTACKED_MISS;
        return FireResult::BESIDE;
    }

    squaresState[square.getX()][square.getY()] = Square::ATTACKED_HIT;
    ships[attackedShip].setHealth(ships[attackedShip].getHealth() - 1);

    if (ships[attackedShip].getHealth()==0)
        return FireResult::SUNK;
    else
        return FireResult::INJURED;
}

bool Fleet::hasAttacked(const Square& square) const {
    return squaresState[square.getX()][square.getY()] != Square::NOT_ATTACKED;
}

int Fleet::getHealth() const {
    int sumHPs = 0;
    for (int i = 0; i < ships.size(); i++) {
        sumHPs += ships[i].getHealth();
    }
    return sumHPs;
}

bool Fleet::isDestroyed() const {
    return !getHealth();
}

Square::State Fleet::getSquareState(int x, int y) const {
    return this->squaresState[x][y];
}

void Fleet::printSquaresState() {
    cout << "  ";
    for (int i = 0; i < 10; i++)
        cout << " | " << i + 1;
    cout << endl;
    for (int i = 0; i < 10; i++) {
        cout << i + 1;
        if (i + 1 < 10) cout << "  | " << getSquareState(i, 0);
        else cout << " | " << getSquareState(i, 0);
        for (int j = 1; j < 10; j++)
            cout << " | " << getSquareState(i, j);
        cout << endl;
    }
}

vector<Ship> Fleet::getShips() const {
    return this->ships;
}