#pragma once
#include"Series.h"
#include"User.h"
#include"RepositoryFile.h"
#include"RepositoryTemplate.h"
#include"ValidatorSeries.h"
#include"ValidatorPhone.h"
#include"MyException.h"

class Service{
private:
	User user;
	RepositoryTemplate<Series*>* repositorySeries;
	RepositoryTemplate<User>* repositoryUser;
	ValidatorSeries validatorSeries;
	ValidatorPhone validatorPhone;

public:
	Service(RepositoryTemplate<Series*>* rs, RepositoryTemplate<User>* ru) {
		repositorySeries = rs;
		repositoryUser = ru;
	};
	int addSeries(Series*);
	int delSeries(Series*);
	int updateSeries(Series*&,Series*);
	bool findSeries(Series*);
	Series* getSeriesFromPos(int);
	list<Series*> getAllSeries();
	int getNumberOfSeries();
	bool logIn(const char*, const char*);
	void logOut();
	bool loggedIn();
	void validatePhone(Phone);
	list<Series*> getAllSeriesFromProducer(string producer);
	~Service();
};

