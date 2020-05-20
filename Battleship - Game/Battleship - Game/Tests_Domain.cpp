#include "Tests_Domain.h"

void test_Domain() {
	test_Square();
	test_Ship();
	test_Fleet();
}

void test_Square() {
	Square sq1(2, 1);
	assert(sq1.getX() == 2);
	assert(sq1.getY() == 1);
	
	Square sq2 = Square::makeSquare(4, 4);
	assert(sq2.getX() == 4);
	assert(sq2.getY() == 4);
	
	sq2.setX(9);
	sq2.setY(9);
	assert(sq2.getX() == 9);
	assert(sq2.getY() == 9);
	
	Square sq3 = sq1;
	
	assert(sq1 == sq3);
	assert(sq1 != sq2);
	assert(sq3 != sq2);
}

void test_Ship() {
	Square sq(0, 0);
	Ship ship1(sq, true);
	vector<Square> squares1 = { Square(0,0),Square(1,0),Square(2,0),
		Square(3,0),Square(1,1),Square(1,2),
		Square(1,-1),Square(1,-2),Square(3,1),Square(3,-1) };
	vector<Square> ship1Squares = ship1.getSquares();
	for (int i = 0; i < squares1.size(); i++) {
		bool ok = false;
		for (int j = 0; j < ship1Squares.size(); j++)
			if (squares1[i] == ship1Squares[j])
				ok = true;
		assert(ok == true);
	}

	//for (int i = 0; i < squares1.size(); i++) {
	//	vector<int>::iterator it;
	//	it = find(ship1Squares.begin(), ship1Squares.end(), squares1[i]);
	//	//assert(it != ship1Squares.end());
	//}
	assert(ship1.getStartSquare() == sq);
	assert(ship1.isHorizontal() == true);
	assert(ship1.isSunk() == false);
	ship1.setHealth(1);
	assert(ship1.getHealth() == 1);
	ship1.setHealth(0);
	assert(ship1.isSunk() == true);
}

void test_Fleet() {
	Fleet fleet;
	Ship sh1(Square(1, 3), true);
	Ship sh3(Square(4, 5), true);
	fleet.addShip(sh1);
	fleet.addShip(sh3);
	vector<Square> fleetShipSquares = fleet.getShips()[1].getSquares();
	vector<Square> ship3Squares = sh3.getSquares();
	for (int i = 0; i < fleetShipSquares.size(); i++) {
		bool ok = false;
		for (int j = 0; j < ship3Squares.size(); j++)
			if (fleetShipSquares[i] == ship3Squares[j])
				ok = true;
		assert(ok == true);
	}
	assert(fleet.getHealth() == 20);
	assert(fleet.findShipIndex(Square(2, 3)) == 0);
	assert(fleet.findShipIndex(Square(1, 1)) == -1);
}