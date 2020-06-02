#pragma once
#include"Player.h"
#include<iostream>
using namespace std;
class HumanPlayer :
	public Player
{
public:
	HumanPlayer() {};
	void placePlanes();
	Square makeGuess();
	void receiveGuess(Square&);
	~HumanPlayer() {};
};
