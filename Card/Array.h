#pragma once
#include <vector>
#include <cassert>
#include <memory>

template<typename T>
class Array
{
private:

	T* array;
	int size;

public:

	Array();

	Array(const int _size);

	~Array();

	void changeSize(int newSize);

	void addElement(T element);

	void addElementToNullptr(T element);

	void addUniqueElement(T& element);

	void deleteElement(T& element);

	void discardElement(T& element);

	void addArrayElement(std::vector<T>& addedArray);

	void addArrayElement(Array<T>* addedArray);

	void deleteArrayElement(std::vector<T>& deletedDeck);

	void deleteArrayElement(Array<T>* deletedDeck);

	void discardArrayElement(std::vector<T>& deletedDeck);

	void discardArrayElement(Array<T>* deletedDeck);

	void fullClear();

	void clear();

	bool findElementBool(T& element);

	T findElementValue(T& element);

	T& operator [](const int index);

	const T& operator [](const int index) const;

	const int getSize() const;

};

