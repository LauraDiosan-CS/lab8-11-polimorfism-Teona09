#include <iostream>
#include"Tests_Domain.h"
#include"Fleet.h"
#include"Airplane.h"
#include"Square.h"
#include"Game.h"
#include"Game2.h"
using namespace std;

int main()
{
	cout << "testing...\n";
	test_Domain();
	cout << "everything is ok :)\n";

	//Game game;
	//game.play();

	Game2 game;
	game.play();
	return 0;
}