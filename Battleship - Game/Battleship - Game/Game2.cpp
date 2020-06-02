#include "Game2.h"

void Game2::humanPlacePlanes() {
	int x, y;
	char poz;
	bool horz;
	Airplane plane = Airplane();
	cout << "introduceti pozitiile de start pentru cele " << this->numberOfShips << " avioane\n";
	for (int i = 1; i <= this->numberOfShips; i++) {
		cout << "introduceti pozitia pentru avionul " << i << endl;
		try {
			cout << "introduceti linia: ";
			cin >> x;
			cout << "introduceti coloana: ";
			cin >> y;
			cout << "asezati orizontal?(d/n)";
			cin >> poz;
		}
		catch (exception ex) {
			cout << "date invalide\n";
		}
		if (poz == 'd') horz = true;
		else horz = false;
		plane = Airplane(Square(x, y), horz);
		while (humanFleet.checkPositionForAirplane(plane) == false) {
			cout << "pozitionare incorecta; incercati din nou\n";
			cout << "introduceti pozitia pentru avionul " << i << endl;
			try {
				cout << "introduceti linia: ";
				cin >> x;
				cout << "introduceti coloana: ";
				cin >> y;
				cout << "asezati orizontal?(d/n)";
				cin >> poz;
			}
			catch (exception ex) {
				cout << "date invalide\n";
			}
			if (poz == 'd') horz = true;
			else horz = false;
			plane = Airplane(Square(x, y), horz);
		}
		humanFleet.addAirplane(plane);
		printInitialTable(humanFleet);
	}
	cout << "finalizare aseazare\n";
}

Square Game2::humanMakeGuess() {
	int x, y;
	cout << "introduceti linia: ";
	cin >> x;
	cout << "introduceti coloana: ";
	cin >> y;
	while (x < 0 or y < 0 or x >= 10 or y >= 10) {
		cout << "pozitie incorecta; incercati din nou\n";
		cout << "introduceti linia: ";
		cin >> x;
		cout << "introduceti coloana: ";
		cin >> y;
	}
	return Square(x, y);
}

void Game2::AIPlacePlanes() {
	cout << "\ncomputerul aseaza piesele\n";
	int x, y, poz;
	bool horz;
	Airplane plane = Airplane();
	for (int i = 1; i <= this->numberOfShips; i++) {
		x = int(rand() % 10);
		y = int(rand() % 10);
		poz = int(rand() % 2);
		if (poz == 1) horz = true;
		else horz = false;
		plane = Airplane(Square(x, y), horz);
		while (AIFleet.checkPositionForAirplane(plane) == false) {
			x = int(rand() % 10);
			y = int(rand() % 10);
			poz = int(rand() % 2);
			if (poz == 1) horz = true;
			else horz = false;
			plane = Airplane(Square(x, y), horz);
		}
		AIFleet.addAirplane(plane);
		cout << "\ncomputer table\n";
		printInitialTable(AIFleet);
	}
}

Square Game2::AIMakeGuess() {
	int x, y;
	x = rand() % 10;
	y = rand() % 10;
	return Square(x, y);
}

void Game2::receiveGuess(Square& guess, Fleet& playerFleet) {
	char state = playerFleet.fire(guess);
	if (state == 'M')
		cout << "miss\n";
	else if (state == 'H')
		cout << "hit\n";
	else if (state == 'D')
		cout << "distrus\n";
	cout << "\n-------Table-------\n";
	printBattleTable(playerFleet);
}

void Game2::humanTurn() {
	Square guess = this->humanMakeGuess();
	while (AIFleet.hasAttacked(guess) == true)
		guess = this->humanMakeGuess();
	this->receiveGuess(guess, AIFleet);
	if (AIFleet.getHealth() == 0) {
		cout << "\n---- winner: human ----\n\n";
		this->winner = true;
	}
}

void Game2::AITurn() {
	Square guess = this->AIMakeGuess();
	while (humanFleet.hasAttacked(guess) == true)
		guess = this->AIMakeGuess();
	this->receiveGuess(guess, humanFleet);
	if (humanFleet.getHealth() == 0) {
		cout << "\n---- winner: computer ----\n\n";
		this->winner = true;
	}
}

void Game2::play() {
	this->humanPlacePlanes();
	this->AIPlacePlanes();
	while (winner == false) {
		cout << "\n\nHuman Turn\n";
		humanTurn();
		if (winner == false) {
			cout << "\n\nComputer Turn\n";
			AITurn();
		}
	}
}