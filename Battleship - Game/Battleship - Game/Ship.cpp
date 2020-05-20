#include "Ship.h"

Ship::Ship(Square startSquare, bool horizontal) {
	int dirX[] = { 0,0,1,2,-1,-2,0,0,1,-1 };
	int dirY[] = { 0,1,1,1, 1, 1,2,3,3, 3 };
	if (horizontal==false) 
		for (int i = 0; i<10; i++) {
			Square square(startSquare.getX()+dirX[i], startSquare.getY()+dirY[i]);
			this->squares.push_back(square);
		}
	else
		for (int i = 0; i < 10; i++) {
			Square square(startSquare.getX() + dirY[i], startSquare.getY() + dirX[i]);
			this->squares.push_back(square);
		}
	this->health = 10;
}

int Ship::getHealth() const {
	return this->health;
}

void Ship::setHealth(int health) {
	this->health = health;
}

vector<Square>Ship::getSquares() const{
	return this->squares;
}

Square Ship::getStartSquare() const {
	return this->squares[0];
}

bool Ship::isHorizontal() const {
	return squares.size() == 1 or squares[0].getY() == squares[1].getY();
}

bool Ship::isSunk() const {
	return health == 0;
}