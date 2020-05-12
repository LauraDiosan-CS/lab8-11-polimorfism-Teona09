#pragma once
#include "Serializer.h"
template <class T> class SerializerWithoutP :
	public Serializer<T>{
public:
	SerializerWithoutP(){}
	virtual T fromString(string line, char delim);
	virtual string toString(T, char);
	T goodObj(T);
	bool isEqual(T, T);
	~SerializerWithoutP(){}
};

template<class T> T SerializerWithoutP<T>::fromString(string line, char delim) {
	T object(line, delim);
	return object;
}

template<class T>string SerializerWithoutP<T>::toString(T object, char delim) {
	return object.toStringDelimiter(delim);
}

template<class T> T SerializerWithoutP<T>::goodObj(T object) {
	return object;
}

template<class T> bool SerializerWithoutP<T>::isEqual(T object1, T object2) {
	return object1 == object2;
}

