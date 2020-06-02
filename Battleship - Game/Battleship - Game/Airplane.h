#pragma once
#include"Square.h"
#include<vector>
#include<utility>
using namespace std;
class Airplane
{
private:
	vector<Square>squares;
	int health;
	bool horizontal;
public:
	Airplane(){}
	Airplane(Square startSquare, bool horizontal);
	Square getStartSquare()const;
	bool isHorizontal() const;
	int getHealth() const;
	void setHealth(int health);
	bool isDown()const;
	vector<Square> getSquares()const;
	~Airplane() {}
};

