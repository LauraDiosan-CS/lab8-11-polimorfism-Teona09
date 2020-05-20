#include "Square.h"

Square::Square(int x, int y) {
	this->x = x;
	this->y = y;
}

Square Square::makeSquare(int x, int y) {
	return Square(x, y);
}

int Square::getX() const{
	return this->x;
}

int Square::getY() const {
	return this->y;
}

void Square::setX(int x) {
	this->x = x;
}

void Square::setY(int y) {
	this->y = y;
}

bool Square::operator==(const Square& square) const {
	return this->x == square.getX() and this->y == square.getY();
}

bool Square::operator!=(const Square& square) const {
	return !(this->x == square.getX() and this->y == square.getY());
}

Square& Square::operator=(const Square& square) {
	this->x = square.getX();
	this->y = square.getY();
	return *this;
}