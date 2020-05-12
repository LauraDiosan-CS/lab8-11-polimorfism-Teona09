#include "TestsRepository.h"

void test_Repository() {
	test_RepositoryTemplate();
	//test_RepositoryFileCSV();
	test_RepositoryFileCustom();
}

void test_RepositoryTemplate() {
	RepositoryTemplate<Drone> repository;
	Drone d1("producer1", "model1", 100, 1);
	Drone d2("producer2", "model2", 200, 2);
	Drone d3("producer3", "model3", 300, 3);
	Drone d4("producer4", "model4", 400, 4);
	Drone drones[] = { d1,d2,d3,d4 };
	repository.addElem(d1);
	repository.addElem(d2);
	repository.addElem(d3);
	repository.addElem(d4);
	list<Drone> listDrones = repository.getAll();
	assert(repository.getSize() == 4);
	int i = 0;
	list<Drone>::iterator it;
	for (it = listDrones.begin(); it != listDrones.end(); it++) {
		assert(*it == drones[i]);
		i++;
	}
	repository.delElem(d3);
	assert(repository.getSize() == 3);
	assert(repository.findElem(d3) == false);
	assert(repository.getItemFromPos(2) == d4);
	Drone d5("producer5", "model5", 500, 5);
	repository.updateElem(d4, d5);
	assert(repository.findElem(d4) == false);
	assert(repository.findElem(d5) == true);
	assert(repository.getItemFromPos(2)==d5);
}

void test_RepositoryFileCSV() {
	SerializerSeries* s = new SerializerSeries;
	RepositoryFileCSV<Series*> repository("test.csv",s);
	assert(repository.getSize() == 2);
	vector<string> operators;
	operators.push_back("operator1");
	operators.push_back("operator2");
	Series* s1 = new Drone("producer1", "model1", 101, 1);
	Series* s2 = new Phone("producer1", "model1", 111, operators);
	Series* s3 = new Drone("producer2", "model21", 200, 2);
	Series* s4 = new Phone("producer2", "model22", 222, operators);
	Series* s5 = new Drone("producer3", "model3", 300, 3);
	assert(repository.getItemFromPos(0)->toString().compare(s1->toString())==0);
	Series* series[] = { s1,s2,s3,s4,s5 };
	repository.addElem(s3);
	repository.addElem(s4);
	repository.addElem(s5);
	list<Series*>seriesList = repository.getAll();
	assert(repository.getSize() == 5);
	int i = 0;
	for (list<Series*>::iterator it = seriesList.begin(); it != seriesList.end(); it++)
	{
		assert((*it)->toString() == series[i]->toString());
		i++;
	}
	repository.delElem(s5);
	assert(repository.findElem(s5) == false);
	assert(repository.getSize() == 4);
	Series* s6 = new Drone("producer4", "model4", 400, 4);
	repository.updateElem(s3, s6);
	assert(repository.findElem(s3) == false);
	assert(repository.findElem(s6) == true);
	assert(repository.getItemFromPos(2)->toString() == s6->toString());
	
	repository.clear();
	repository.addElem(s1);
	repository.addElem(s2);
	delete s1, s2, s3, s4, s5;
}

void test_RepositoryFileCustom() {
	SerializerSeries* s = new SerializerSeries;
	RepositoryFileCustom<Series*> repository("test.txt", s);
	assert(repository.getSize() == 2);
	vector<string> operators;
	operators.push_back("operator1");
	operators.push_back("operator2");
	Series* s1 = new Drone("producer1", "model1", 101, 1);
	Series* s2 = new Phone("producer1", "model1", 111, operators);
	Series* s3 = new Drone("producer2", "model21", 200, 2);
	Series* s4 = new Phone("producer2", "model22", 222, operators);
	Series* s5 = new Drone("producer3", "model3", 300, 3);
	assert(repository.getItemFromPos(0)->toString().compare(s1->toString()) == 0);
	Series* series[] = { s1,s2,s3,s4,s5 };
	repository.addElem(s3);
	repository.addElem(s4);
	repository.addElem(s5);
	list<Series*>seriesList = repository.getAll();
	assert(repository.getSize() == 5);
	int i = 0;
	for (list<Series*>::iterator it = seriesList.begin(); it != seriesList.end(); it++)
	{
		assert((*it)->toString() == series[i]->toString());
		i++;
	}
	repository.delElem(s5);
	assert(repository.findElem(s5) == false);
	assert(repository.getSize() == 4);
	Series* s6 = new Drone("producer4", "model4", 400, 4);
	repository.updateElem(s3, s6);
	assert(repository.findElem(s3) == false);
	assert(repository.findElem(s6) == true);
	assert(repository.getItemFromPos(2)->toString() == s6->toString());

	repository.clear();
	repository.addElem(s1);
	repository.addElem(s2);
	delete s1, s2, s3, s4, s5;
}