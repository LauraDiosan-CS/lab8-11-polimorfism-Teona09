#include "Airplane.h"

Airplane::Airplane(Square startSquare, bool horizontal) {
	int dirX[] = { 0,0,0,0,1,2,1,-1,-2,-1 };
	int dirY[] = { 0,1,2,3,1,1,3, 1, 1, 3 };
	if (horizontal)
		for (int i = 0; i < 10; i++) {
			Square square(startSquare.getX() + dirX[i], startSquare.getY() + dirY[i]);
			this->squares.push_back(square);
		}
	else
		for (int i = 0; i < 10; i++) {
			Square square(startSquare.getX() + dirY[i], startSquare.getY() + dirX[i]);
			this->squares.push_back(square);
		}
	this->horizontal = horizontal;
	this->health = 10;
}

int Airplane::getHealth() const {
	return this->health;
}

void Airplane::setHealth(int health) {
	this->health = health;
}

vector<Square>Airplane::getSquares() const {
	return this->squares;
}

Square Airplane::getStartSquare() const {
	return this->squares[0];
}

bool Airplane::isHorizontal() const {
	return this->horizontal;
}

bool Airplane::isDown() const {
	return health == 0;
}