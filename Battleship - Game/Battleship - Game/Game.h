#pragma once
#include"Player.h"
#include"ComputerPlayer.h"
#include"HumanPlayer.h"

class Game
{
private:
	Player* Human;
	Player* AI;
	bool winner = false;
public:
	Game() {}
	void turn(Player* player1, Player* player2);

	//void turn1(HumanPlayer player1, ComputerPlayer player2);
	//void turn2(ComputerPlayer player1, HumanPlayer player2);
	void play();
	~Game() {}
};
