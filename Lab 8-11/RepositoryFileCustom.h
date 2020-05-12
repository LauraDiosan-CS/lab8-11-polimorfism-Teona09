#pragma once
#include "RepositoryFile.h"
#include "Serializer.h"
#include <list>
#include<fstream>
#include<iostream>
using namespace std;

template <class T> class RepositoryFileCustom :
	public RepositoryFile<T>
{
private:
	Serializer<T>* s;
public:
	char delimitator = '/';
	RepositoryFileCustom();
	RepositoryFileCustom(const char*, Serializer<T>*);
	int addElem(T);
	int delElem(T);
	void updateElem(T, T);
	bool findElem(T);
	void loadFromFile(const char*);
	void saveToFile();
	~RepositoryFileCustom();
};

template<class T> RepositoryFileCustom<T>::RepositoryFileCustom() :RepositoryFile<T>() {
	RepositoryFile<T>::fileName = "";
}

template<class T> RepositoryFileCustom<T>::RepositoryFileCustom(const char* file, Serializer<T>* sr) : RepositoryFile<T>() {
	RepositoryFile<T>::fileName = "";
	s = sr;
	loadFromFile(file);
}

template<class T> void RepositoryFileCustom<T>::loadFromFile(const char* file) {
	RepositoryFile<T>::fileName = file;
	//this->clear();
	string line;
	ifstream f(RepositoryFile<T>::fileName);
	while (getline(f, line)) {
		RepositoryFile<T>::addElem(s->fromString(line, this->delimitator));
	}
	f.close();
}

template<class T>void RepositoryFileCustom<T>::saveToFile() {
	ofstream f(RepositoryFile<T>::fileName);
	for (T current : RepositoryFile<T>::elem)
		f << s->toString(current, this->delimitator) << '\n';
	f.close();
}

template<class T>int RepositoryFileCustom<T>::addElem(T ent) {
	int rez = RepositoryFile<T>::addElem(s->goodObj(ent));
	saveToFile();
	return rez;
}

template<class T>int RepositoryFileCustom<T>::delElem(T ent) {
	typename list<T>::iterator it;
	for (it = RepositoryFile<T>::elem.begin(); it != RepositoryFile<T>::elem.end(); it++) {
		if (s->isEqual((*it), ent) == true) {
			RepositoryFile<T>::elem.erase(it);
			saveToFile();
			return 0;
		}
	}
	return -1;
}

template<class T> void RepositoryFileCustom<T>::updateElem(T ent, T newEnt) {
	typename list<T>::iterator it;
	for (it = RepositoryFile<T>::elem.begin(); it != RepositoryFile<T>::elem.end(); ++it) {
		if (s->isEqual((*it), ent) == true) {
			replace(RepositoryFile<T>::elem.begin(), RepositoryFile<T>::elem.end(), (*it), newEnt);
		}
	}
	saveToFile();
}

template<class T>bool RepositoryFileCustom<T>::findElem(T ent) {
	typename list<T>::iterator it;
	for (it = RepositoryFile<T>::elem.begin(); it != RepositoryFile<T>::elem.end(); it++) {
		if (s->isEqual(*it, ent) == true)
			return true;
	}
	return false;
}

template<class T>RepositoryFileCustom<T>::~RepositoryFileCustom() {}