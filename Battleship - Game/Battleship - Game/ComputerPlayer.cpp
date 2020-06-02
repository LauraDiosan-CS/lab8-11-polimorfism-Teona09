#include "ComputerPlayer.h"

void ComputerPlayer::placePlanes() {
	cout << "\ncomputerul aseaza piesele\n";
	int x, y, poz;
	bool horz;
	Airplane plane = Airplane();
	for (int i = 1; i <= numberOfPlanes; i++) {
		x = int(rand() % 10);
		y = int(rand() % 10);
		poz = int(rand() % 2);
		if (poz == 1) horz = true;
		else horz = false;
		plane = Airplane(Square(x, y), horz);
		cout << playerFleet.checkPositionForAirplane(plane);
		while (playerFleet.checkPositionForAirplane(plane) == false) {
			x = int(rand() % 10);
			y = int(rand() % 10);
			poz = int(rand() % 2);
			if (poz == 1) horz = true;
			else horz = false;
			plane = Airplane(Square(x, y), horz);
		}
		playerFleet.addAirplane(plane);
		cout << "\ncomputer table\n";
		printPlayerTable();
	}
}

Square ComputerPlayer::makeGuess() {
	int x, y;
	x = rand() % 10;
	y = rand() % 10;
	return Square(x, y);
}

void ComputerPlayer::receiveGuess(Square& guess) {
	char state = playerFleet.fire(guess);
	if (state == 'M')
		cout << "miss\n";
	else if (state == 'H')
		cout << "hit\n";
	else if (state == 'D')
		cout << "distrus\n";
	cout << "\n computer Table\n";
	printBattleTable();
}