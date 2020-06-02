#include "HumanPlayer.h"

void HumanPlayer::placePlanes() {
	int x, y;
	char poz;
	bool horz;
	Airplane plane = Airplane();
	cout << "introduceti pozitiile de start pentru cele 3 avioane\n";
	for (int i = 1; i <= numberOfPlanes; i++) {
		cout << "introduceti pozitia pentru avionul " << i << endl;
		cout << "introduceti linia: ";
		cin >> x;
		cout << "introduceti coloana: ";
		cin >> y;
		cout << "asezati orizontal?(d/n)";
		cin >> poz;
		if (poz == 'd') horz = true;
		else horz = false;
		plane = Airplane(Square(x, y), horz);
		while (playerFleet.checkPositionForAirplane(plane) == false) {
			cout << "pozitionare incorecta; incercati din nou\n";
			cout << "introduceti pozitia pentru avionul " << i << endl;
			cout << "introduceti linia: ";
			cin >> x;
			cout << "introduceti coloana: ";
			cin >> y;
			cout << "asezati orizontal?(d/n)";
			cin >> poz;
			if (poz == 'd') horz = true;
			else horz = false;
			plane = Airplane(Square(x, y), horz);
		}
		playerFleet.addAirplane(plane);
		printPlayerTable();
	}
	cout << "finalizare aseazare\n";
}

Square HumanPlayer::makeGuess() {
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

void HumanPlayer::receiveGuess(Square& guess) {
	char state = playerFleet.fire(guess);
	if (state == 'M')
		cout << "miss\n";
	else if (state == 'H')
		cout << "hit\n";
	else if (state == 'D')
		cout << "distrus\n";
	cout << "\n human Table\n";
	printBattleTable();
}