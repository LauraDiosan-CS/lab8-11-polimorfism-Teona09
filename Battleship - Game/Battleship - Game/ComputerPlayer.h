#pragma once
#include "Fleet.h"
#include "Player.h"
#include<iostream>
using namespace std;
class ComputerPlayer
	: public Player
{
public:
	ComputerPlayer() {};
	void placePlanes();
	Square makeGuess();
	void receiveGuess(Square&);
	~ComputerPlayer() {};
};
