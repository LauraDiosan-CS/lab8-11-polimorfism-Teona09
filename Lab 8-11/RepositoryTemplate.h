#pragma once
#include<list>
#include<algorithm>
using namespace std;

template <class T> class RepositoryTemplate{
protected:
	list<T> elem;
public:
	RepositoryTemplate();
	virtual int addElem(T);
	virtual int delElem(T);
	virtual bool findElem(T);
	int getSize();
	virtual void updateElem(T ent, T newEnt);
	list<T> getAll();
	T getItemFromPos(int);
	void clear();
	~RepositoryTemplate();
};

template<class T>RepositoryTemplate<T>::RepositoryTemplate(){}

template<class T>int RepositoryTemplate<T>::addElem(T ent) {
	elem.push_back(ent);
	return 0;
}

template<class T>int RepositoryTemplate<T>::delElem(T ent) {
	typename list<T>::iterator it;
	it = find(elem.begin(), elem.end(), ent);
	if (it != elem.end()) {
		elem.erase(it);
		return 0;
	}
	return -1;
}

template <class T> bool RepositoryTemplate<T>::findElem(T ent) {
	typename list<T>::iterator it;
	it = find(elem.begin(), elem.end(), ent);
	if (it != elem.end())
		return true;
	return false;
}

template <class T> int RepositoryTemplate<T>::getSize() {
	return elem.size();
}

template<class T>void RepositoryTemplate<T>::updateElem(T ent, T newEnt) {
	replace(elem.begin(), elem.end(), ent, newEnt);
}

template<class T> list<T> RepositoryTemplate<T>::getAll() {
	return elem;
}

template<class T> T RepositoryTemplate<T>::getItemFromPos(int pos) {
	typename list<T>::iterator it;
	int k = 0;
	for (it = elem.begin(); it != elem.end(); it++) {
		if (k == pos)
			return (*it);
		k++;
	}
	return T();
}

template<class T>void RepositoryTemplate<T>::clear() {
	elem.clear();
}

template<class T> RepositoryTemplate<T>::~RepositoryTemplate(){}