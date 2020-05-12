#include"TestsDomain.h"

void test_Domain() {
	test_Drone();
	test_Phone();
	test_User();
}

void test_Drone() {
	Drone* s1 = new Drone();
	assert((*s1).getProducerName() == NULL);
	assert((*s1).getModelName() == NULL);
	assert((*s1).getUnits() == 0);
	assert((*s1).getRotorsNumber() == 0);
	Drone* s2 = new Drone("Producer2", "Model2", 200, 20);
	assert(strcmp((*s2).getProducerName(), "Producer2") == 0);
	assert((*s2).getRotorsNumber() == 20);
	Drone* s3 = new Drone(*s2);
	assert(strcmp((*s3).getModelName(), "Model2") == 0);
	assert((*s2) == (*s3));
	(*s3).setProducerName("Producer3");
	(*s3).setModelName("Model3");
	(*s3).setUnits(300);
	(*s3).setRontorsNumber(30);
	assert(strcmp((*s3).getModelName(), "Model3") == 0);
	assert((*s3).getUnits() == 300);
	assert((*s2) < (*s3) == true);
	string s = "Producer3 Model3 300 30";
	assert((*s3).toString().compare(s)==0);
	assert((*s3).toStringDelimiter(' ').compare(s)==0);
	Drone* s4 = new Drone("Producer2 Model2 200 20",' ');
	assert((*s2) == (*s4));
	delete s1;
	delete s2;
	delete s3;
	delete s4;
}

void test_Phone() {
	vector<string> op = {};
	Phone* s1 = new Phone();
	assert((*s1).getProducerName() == NULL);
	assert((*s1).getModelName() == NULL);
	assert((*s1).getUnits() == 0);
	assert((*s1).getOperators() == op);
	assert((*s1).getOperators().empty());
	op.push_back("operator1");
	op.push_back("operator2");
	Phone* s2 = new Phone("Producer2", "Model2", 200, op);
	assert(strcmp((*s2).getProducerName(), "Producer2") == 0);
	vector <string> v = { "operator1","operator2"};
	assert((*s2).getOperators().size() == 2);
	assert((*s2).getOperators() == v);
	Phone* s3 = new Phone(*s2);
	assert(strcmp((*s3).getModelName(), "Model2") == 0);
	assert((*s2) == (*s3));
	(*s3).setProducerName("Producer3");
	(*s3).setModelName("Model3");
	(*s3).setUnits(300);
	(*s3).addOperator("operator3");
	assert(strcmp((*s3).getModelName(), "Model3") == 0);
	assert((*s3).getUnits() == 300);
	assert((*s2) < (*s3) == true);
	string s = "Producer3 Model3 300 operator1-operator2-operator3";
	assert((*s3).toString().compare(s) == 0);
	assert((*s3).toStringDelimiter(' ').compare(s) == 0);
	Phone* s4 = new Phone("Producer2 Model2 200 operator1-operator2", ' ');
	assert((*s2) == (*s4));
	delete s1;
	delete s2;
	delete s3;
	delete s4;
}

void test_User() {
	User* u1 = new User("username1", "pass1");
	assert((*u1).getUsername().compare("username1")==0);
	assert((*u1).getPassword().compare("pass1")==0);
	User* u2 = new User("username2/pass2", '/');
	assert((*u2).getUsername().compare("username2") == 0);
	assert((*u2).getPassword().compare("pass2") == 0);
	User* u3 = new User();
	(*u3).setUsername("username3");
	(*u3).setPassword("pass3");
	assert((*u3).getUsername().compare("username3") == 0);
	assert((*u3).getPassword().compare("pass3") == 0);
	assert((*u1).toString().compare("username1 pass1") == 0);
	assert((*u1).toStringDelimiter(' ').compare("username1 pass1") == 0);
}