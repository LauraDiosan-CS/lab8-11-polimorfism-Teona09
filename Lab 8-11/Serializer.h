#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class T> class Serializer{
public:
	Serializer();
	virtual T fromString(string line, char delim)=0;
	virtual string toString(T, char)=0;
	virtual T goodObj(T)=0;
	virtual bool isEqual(T, T)=0;
	~Serializer();
};

template<class T> Serializer<T>::Serializer() {
}


template<class T> Serializer<T>::~Serializer() {
}
