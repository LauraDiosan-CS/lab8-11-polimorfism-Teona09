#include "Square.h"

Square::Square() {
	this->x = 0;
	this->y = 0;
	this->state = 'O';
	this->occupied = 'C';
}


Square::Square(int x, int y) {
	this->x = x;
	this->y = y;
	this->state = 'O';
	this->occupied = 'C';
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

char Square::getState() const {
	return this->state;
}
char Square::getOccupied() const {
	return this->occupied;
}

void Square::setX(int x) {
	this->x = x;
}

void Square::setY(int y) {
	this->y = y;
}

void Square::setState(char state) {
	this->state = state;
}

void Square::setOccupied() {
	this->occupied = 'A';
}

bool Square::operator==(const Square& square) const {
	return this->x == square.getX() and this->y == square.getY()
		and this->state==square.getState()
		and this->occupied==square.getOccupied();
}

bool Square::operator!=(const Square& square) const {
	return !(this->x == square.getX() and this->y == square.getY()
		and this->state == square.getState()
		and this->occupied==square.getOccupied());
}

Square& Square::operator=(const Square& square) {
	this->x = square.getX();
	this->y = square.getY();
	this->state = square.getState();
	this->occupied = square.getOccupied();
	return *this;
}