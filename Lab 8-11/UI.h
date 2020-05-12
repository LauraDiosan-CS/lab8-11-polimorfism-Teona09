#pragma once
#include<iostream>
#include"Service.h"
#include"Series.h"
#include"Drone.h"
#include"Phone.h"
using namespace std;

class UI
{
private:
	Service service;
	void menu();
	void logIn();
	void logOut();
	void menuOperations();
	void operations();
	void add();
	void showAll();
	void searchProducer();
public:
	UI(Service& s) : service(s) {};
	void console();
	~UI() {}
};

