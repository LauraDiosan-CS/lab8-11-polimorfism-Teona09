#include "UI.h"

void UI::menu() {
	cout << endl;
	cout << '\t' << "Menu:" << endl;
	cout << '\t' << "1.Log in" << endl;
	cout << '\t' << "2.Operating Menu" << endl;
	cout << '\t' << "3.Log out" << endl;
	cout << '\t' << "4.Exit" << endl;
	cout << '\t' << "Your option:" << endl;
}

void UI::logIn() {
	if (service.loggedIn() == true)
		cout << "already logged in\n";
	else {
		char* username = new char[15];
		char* password = new char[15];
		cout << "Username: ";
		cin >> username;
		cout << "Password: ";
		cin >> password;
		if (service.logIn(username, password) == true)
		{
			cout << "logged in\n\n";
			this->showAll();
		}
		else
			cout << "Wrong username or password\nredirect to menu\n";
		delete[] username, password;
	}
}

void UI::logOut() {
	try {
		service.logOut();
		cout << "logged out\n";
	}
	catch (MyException ex) {
		cout << ex.getMessage() << '\n';
	}
}

void UI::menuOperations() {
	cout << endl;
	cout << '\t' << "Operating Menu:" << endl;
	cout << '\t' << "1.Add" << endl;
	cout << '\t' << "2.Show all" << endl;
	cout << '\t' << "3.Search producer" << endl;
	cout << '\t' << "4.Back" << endl;
	cout << '\t' << "Your option:" << endl;
}

void UI::operations() {
	if (service.loggedIn() == true)
	{
		char option;
		bool ok=true;
		while (ok == true) {
			menuOperations();
			cin >> option;
			switch (option) {
			case '1': {
				this->add();
				break;
			}
			case '2': {
				this->showAll();
				break;
			}
			case '3': {
				this->searchProducer();
				break;
			}
			case '4': {
				ok = false;
				break;
			}
			default : {
				cout << "not an option\n";
				break;
			}
			}

		}
	}
	else
		cout << "not logged in\n";
}

void UI::add() {
	cout << '\t' << "Add: " << '\n';
	cout << '\t' << "1.Drone" << '\n';
	cout << '\t' << "2.Phone: " << '\n';
	cout << '\t' << "Your option: ";
	char option;
	cin >> option;
	switch (option) {
	case '1': {
		try {
			Drone d;
			cin >> d;
			Series* s = new Drone(d);
			service.addSeries(s);
		}
		catch (MyExceptionList ex) {
			for (int i = 0; i < ex.getErrors().size(); i++)
				cout << ex.getErrors()[i];
		}
		break;
	}
	case '2': {
		try {
			Phone p;
			cin >> p;
			service.validatePhone(p);
			Series* s = new Phone(p);
			service.addSeries(s);
		}
		catch (MyExceptionList ex) {
			for (int i = 0; i < ex.getErrors().size(); i++)
				cout << ex.getErrors()[i];
		}
		break;
	}
	default : {
		cout << "not an option\n";
		break;
	}
	}
}

void UI::showAll(){
	list<Series*> all = service.getAllSeries();
	for (auto it = all.begin(); it != all.end(); it++)
		cout << (*it)->toString()<<'\n';
}

void UI::searchProducer() {
	string producer;
	cout << "Producer to search: ";
	cin >> producer;
	list<Series*> foundObjects = service.getAllSeriesFromProducer(producer);
	if (foundObjects.empty() == true)
		cout << "no series from this producer\n";
	else
		for (auto it = foundObjects.begin(); it != foundObjects.end(); it++)
			cout << (*it)->toString() << '\n';
}

void UI::console() {
	char option;
	bool ok = true;
	while (ok == true) {
		menu();
		cin >> option;
		switch (option) {
		case '1': {
			this->logIn();
			break;
		}
		case '2': {
			this->operations();
			break;
		}
		case '3': {
			this->logOut();
			break;
		}
		case '4': {
			ok = false;
			cout << "program closed\n";
			break;
		}
		default: {
			cout << "not an option\n";
			break;
		}
		}
	}
}
