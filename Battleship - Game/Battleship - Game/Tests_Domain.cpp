#include "Tests_Domain.h"

void test_Domain() {
	test_Square();
	test_Airplane();
	test_Fleet();
}

void test_Square() {
	Square sq1(2, 1);
	assert(sq1.getX() == 2);
	assert(sq1.getY() == 1);
	assert(sq1.getState() == 'O');
	assert(sq1.getOccupied() == 'C');

	Square sq2 = Square::makeSquare(4, 4);
	assert(sq2.getX() == 4);
	assert(sq2.getY() == 4);

	sq2.setX(9);
	sq2.setY(9);
	sq2.setState('D');
	assert(sq2.getX() == 9);
	assert(sq2.getY() == 9);
	assert(sq2.getState() == 'D');

	Square sq3 = sq1;

	assert(sq1 == sq3);
	assert(sq1 != sq2);
	assert(sq3 != sq2);
}

void test_Airplane() {
	Square sq(0, 0);
	Airplane Airplane1(sq, false);
	vector<Square> squares1 = { Square(0,0),Square(1,0),Square(2,0),
		Square(3,0),Square(1,1),Square(1,2),
		Square(1,-1),Square(1,-2),Square(3,1),Square(3,-1) };
	vector<Square> Airplane1Squares = Airplane1.getSquares();
	for (int i = 0; i < squares1.size(); i++) {
		bool ok = false;
		for (int j = 0; j < Airplane1Squares.size(); j++)
			if (squares1[i] == Airplane1Squares[j])
				ok = true;
		assert(ok == true);
	}
	assert(Airplane1.getStartSquare() == sq);

	assert(Airplane1.isHorizontal() == false);
	assert(Airplane1.isDown() == false);
	Airplane1.setHealth(1);
	assert(Airplane1.getHealth() == 1);
	Airplane1.setHealth(0);
	assert(Airplane1.isDown() == true);
}

void test_Fleet() {
	Fleet fleet;
	Airplane sh1(Square(1, 3), true);
	Airplane sh3(Square(4, 5), true);
	fleet.addAirplane(sh1);
	fleet.addAirplane(sh3);

	//vector<Airplane> fleetAirplanes = fleet.getAirplanes();
	//vector<Square> fleetAirplaneSquares = fleetAirplanes[0].getSquares();
	//vector<Square> Airplane1Squares = sh1.getSquares();
	//for (int i = 0; i < fleetAirplaneSquares.size(); i++) {
	//	bool ok = false;
	//	for (int j = 0; j < Airplane1Squares.size(); j++)
	//		if (fleetAirplaneSquares[i] == Airplane1Squares[j])
	//			ok = true;
	//	assert(ok == true);
	//}

	assert(fleet.getHealth() == 20);
	assert(fleet.findAirplaneIndex(Square(1, 4)) == 0);
	assert(fleet.findAirplaneIndex(Square(1, 1)) == -1);
	return;
}