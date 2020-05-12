#pragma once
#include "RepositoryTemplate.h"
#include<string>
using namespace std;
template <class T> class RepositoryFile :
	public RepositoryTemplate<T>{
protected:
	const char* fileName;
public:
	RepositoryFile();
	RepositoryFile(const char*);
	virtual int addElem(T);
	virtual int delElem(T);
	virtual void updateElem(T ent, T newEnt);
	virtual void loadFromFile(const char*) = 0;
	virtual void saveToFile() = 0;
	~RepositoryFile();
};

template<class T>RepositoryFile<T>::RepositoryFile() :RepositoryTemplate<T>() {
	fileName = "";
}

template<class T>RepositoryFile<T>::RepositoryFile(const char* file) : RepositoryTemplate<T>() {
	fileName = file;
}

template<class T> int RepositoryFile<T>::addElem(T ent) {
	int r = RepositoryTemplate<T>::addElem(ent);
	return r;
}

template<class T> int RepositoryFile<T>::delElem(T ent) {
	int r = RepositoryTemplate<T>::delElem(ent);
	return r;
}

template<class T> void RepositoryFile<T>::updateElem(T ent, T newEnt) {
	RepositoryTemplate<T>::updateElem(ent, newEnt);
}

template<class T>RepositoryFile<T>::~RepositoryFile(){}

