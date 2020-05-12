#include "Service.h"

int Service::addSeries(Series* series) {
	validatorSeries.validate(series);
	return repositorySeries->addElem(series);
}

int Service::delSeries(Series* series) {
	return repositorySeries->delElem(series);
}

int Service::updateSeries(Series*& seriesOld,Series* seriesNew) {
	repositorySeries->updateElem(seriesOld, seriesNew);
	return 0;
}

bool Service::findSeries(Series* series) {
	return repositorySeries->findElem(series);
}

Series* Service::getSeriesFromPos(int pos) {
	return repositorySeries->getItemFromPos(pos);
}

list<Series*> Service::getAllSeries() {
	return repositorySeries->getAll();
}

int Service::getNumberOfSeries() {
	return repositorySeries->getSize();
}

void Service::validatePhone(Phone phone) {
	validatorPhone.validate(phone);
}

bool Service::logIn(const char* u, const char* p) {
	User userToFind(u, p);
	bool found = repositoryUser->findElem(userToFind);
	if (found == true) {
		user.setUsername(u);
		user.setPassword(p);
	}
	return found;
}

void Service::logOut() {
	if (user.getUsername() == "")
		throw MyException("You  are not logged in");
	user = User();
}

bool Service::loggedIn() {
	if (user.getUsername() == "")
		return false;
	return true;
}

list<Series*> Service::getAllSeriesFromProducer(string producer) {
	list<Series*> searchList = repositorySeries->getAll();
	list<Series*> requiredList;
	for (auto it = searchList.begin(); it != searchList.end(); it++)
		if ((*it)->getProducerName() == producer)
			requiredList.push_back(*it);
	return requiredList;
}

Service::~Service(){}