#include "TestsService.h"

void test_Service() {
	vector<string> operators;
	operators.push_back("operator1");
	operators.push_back("operator2");
	Series* s1 = new Drone("producer1", "model1", 101, 1);
	Series* s2 = new Phone("producer1", "model1", 111, operators);
	Series* s3 = new Drone("producer2", "model21", 200, 2);
	Series* s4 = new Phone("producer2", "model22", 222, operators);
	RepositoryTemplate<Series*>* repoSeries = new RepositoryTemplate<Series*>;
	RepositoryTemplate<User>* repoUser = new RepositoryTemplate<User>;
	Service service(repoSeries, repoUser);
	service.addSeries(s1);
	service.addSeries(s2);
	service.addSeries(s3);
	service.addSeries(s4);
	assert(service.getNumberOfSeries() == 4);
	assert(service.getSeriesFromPos(0) == s1);
	assert(service.getSeriesFromPos(1) == s2);
	assert(service.getSeriesFromPos(2) == s3);
	assert(service.findSeries(s4) == true);
	service.delSeries(s4);
	assert(service.findSeries(s4) == false);
	assert(service.getNumberOfSeries() == 3);
	Series* s5 = new Drone("producer3", "model3", 300, 3);
	service.updateSeries(s3, s5);
	assert(service.getSeriesFromPos(2) == s5);
	assert(service.findSeries(s3) == false);
	delete s1, s2, s3, s4, s5;
}