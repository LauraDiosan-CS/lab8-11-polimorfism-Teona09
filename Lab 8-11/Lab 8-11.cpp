#include<iostream>
#include"TestsDomain.h"
#include"TestsRepository.h"
#include"TestsService.h"
#include"UI.h"
using namespace std;

int main() {
	cout << "testing..."<<'\n';
	test_Domain();
	test_Repository();
	test_Service();
	cout << "everything looks fine" << '\n' << '\n';
	cout << "Choose your files type: \n";
	cout << "1.csv \t 2.txt \n";
	short op;
	cin >> op;
	RepositoryFile<Series*>* repositorySeries = new RepositoryFileCSV<Series*>;
	SerializerSeries* s = new SerializerSeries;
	SerializerWithoutP<User>* sr = new SerializerWithoutP<User>;
	RepositoryFile<User>* repositoryUsers = new RepositoryFileCSV<User>;
	if (op == 1) {
		repositorySeries = new RepositoryFileCSV<Series*>("series.csv", s);
		repositoryUsers = new RepositoryFileCSV<User>("users.csv", sr);
	}
	else {
		repositorySeries = new RepositoryFileCustom<Series*>("series.txt", s);
		repositoryUsers = new RepositoryFileCustom<User>("users.txt", sr);
	}
	Service serv(repositorySeries, repositoryUsers);
	UI ui(serv);
	ui.console();
}
