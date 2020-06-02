#include "Game.h"

//void Game::turn1(HumanPlayer player1, ComputerPlayer player2) {
//	Square guess = player1.makeGuess();
//	while(player2.verifyGuess(guess)==false)
//		guess = player1.makeGuess();
//	player2.receiveGuess(guess);
//	if (player2.healthLeft() == 0) {
//		cout << "\n---- winner: human ----\n\n";
//		this->winner = true;
//	}
//}
//
//void Game::turn2(ComputerPlayer player1, HumanPlayer player2) {
//	Square guess = player1.makeGuess();
//	while (player2.verifyGuess(guess) == false)
//		guess = player1.makeGuess();
//	player2.receiveGuess(guess);
//	if (player2.healthLeft() == 0) {
//		cout << "\n---- winner: computer ----\n\n";
//		this->winner = true;
//	}
//}

void Game::turn(Player* player1, Player* player2) {
	Square guess = (*player1).makeGuess();
	while ((*player2).verifyGuess(guess) == false)
		guess = (*player1).makeGuess();
	(*player2).receiveGuess(guess);
	if ((*player2).healthLeft() == 0) {

		//cout << "\n---- winner: human ----\n\n";
		this->winner = true;
	}
}

void Game::play() {
	(*Human).placePlanes();
	(*AI).placePlanes();
	while (winner == false) {
		cout << "\n\nHuman Turn\n";
		turn(Human, AI);
		if (winner == true)
			cout << "\n---- winner: human ----\n\n";
		else {
			cout << "\n\nComputer Turn\n";
			turn(AI, Human);
			if (winner == true)
				cout << "\n---- winner: human ----\n\n";
		}
	}
}