#pragma once
#include"Square.h"
#include<vector>
#include<utility>
using namespace std;
class Ship
{
private:
	vector<Square>squares;
	int health;
public:
	Ship(Square startSquare, bool horizontal);
	Square getStartSquare()const;
	bool isHorizontal() const;
	int getHealth() const;
	void setHealth(int health);
	bool isSunk()const;
	vector<Square> getSquares()const;
	~Ship() {}
};

