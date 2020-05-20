#pragma once
#include<iostream>
#include<vector>
using namespace std;
class GameTable
{
private:
	vector<vector<char>> table;
public:
	GameTable();
	vector<vector<char>> getGameTable();
	~GameTable(){}
};

