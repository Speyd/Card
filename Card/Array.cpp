#include "Array.h"
#include "vector"
#include <unordered_map>

template<typename T>
Array<T>::Array() :
	array{ nullptr },
	size{ 0 }
{}
template<typename T>
Array<T>::Array(const int _size) :
	array{ nullptr },
	size{ _size }
{
	if (this->array != nullptr)
		delete[] this->array;

	this->array = new T[_size]{};
}

template<typename T>
Array<T>::~Array()
{
	if (this->array != nullptr)
	{
		delete[] this->array;
	}
}

template<typename T>
void Array<T>::changeSize(int newSize)
{
	assert(newSize >= 0);
	if (newSize == this->size)
		return;

	T* newArray = new T[this->size]{};
	for (int i{ 0 }; i < this->size; i++)
	{
		newArray[i] = this->array[i];
	}
	delete[] this->array;


	int minSize = std::min(this->size, newSize);
	this->array = new T[newSize];

	for (int i{ 0 }; i < minSize; i++)
	{
		this->array[i] = newArray[i];
	}
	delete[] newArray;

	this->size = newSize;
}

template<typename T>
void Array<T>::addElement(T element)
{
	changeSize(this->size + 1);
	this->array[this->size - 1] = element;
}

template<typename T>
void Array<T>::addUniqueElement(T& element)
{
	for (int i{ 0 }; i < this->size; i++)
	{
		if (this->array[i] == element)
			return;
	}

	addElement(element);
}

template<typename T>
void Array<T>::deleteElement(T& element)
{
	for (int i{ 0 }; i < this->size; i++)
	{
		if (this->array[i] == element)
		{
			std::swap(this->array[i], this->array[this->size - 1]);
			delete this->array[this->size - 1];
			changeSize(this->size - 1);
			return;
		}
	}
}

template<typename T>
void Array<T>::discardElement(T& element)
{
	for (int i{ 0 }; i < this->size; i++)
	{
		if (this->array[i] == element)
		{
			std::swap(this->array[i], this->array[this->size - 1]);
			changeSize(this->size - 1);
			return;
		}
	}
}

template<typename T>
void Array<T>::addArrayElement(std::vector<T>& addedArray)
{
	if (addedArray.size() == 0) return;

	changeSize(this->size + int(addedArray.size()));
	for (int indexMainArray{ this->size - int(addedArray.size()) }, indexAddedArray{ 0 };
		indexAddedArray < addedArray.size();
		indexMainArray++, indexAddedArray++)
	{
		array[indexMainArray] = addedArray[indexAddedArray];
	}
}

template<typename T>
void Array<T>::addArrayElement(Array<T>* addedArray)
{
	if (addedArray == nullptr || addedArray->array == nullptr || addedArray->size == 0)return;

	changeSize(this->size + addedArray->getSize());
	for (int indexMainArray{ this->size - addedArray->getSize() }, indexAddedArray{ 0 };
		indexAddedArray < addedArray->size;
		indexMainArray++, indexAddedArray++)
	{
		this->array[indexMainArray] = (*addedArray)[indexAddedArray];
	}
}

template<typename T>
void Array<T>::deleteArrayElement(std::vector<T>& deletedDeck)
{
	for (int i{ 0 }; i < deletedDeck.size(); i++)
	{
		deleteElement(deletedDeck[i]);
	}
}

template<typename T>
void Array<T>::deleteArrayElement(Array<T>* deletedDeck)
{
	if (deletedDeck == nullptr)return;

	for (int i{ 0 }; i < deletedDeck->getSize(); i++)
	{
		deleteElement((*deletedDeck)[i]);
	}
}

template<typename T>
void Array<T>::discardArrayElement(std::vector<T>& deletedDeck)
{
	for (int i{ 0 }; i < deletedDeck.size(); i++)
	{
		discardElement(deletedDeck[i]);
	}
}

template<typename T>
void Array<T>::discardArrayElement(Array<T>* deletedDeck)
{
	if (deletedDeck == nullptr)return;

	for (int i{ 0 }; i < deletedDeck->getSize(); i++)
	{
		discardElement((*deletedDeck)[i]);
	}
}

template<typename T>
void Array<T>::fullClear()
{
	delete[] this->array;
	this->array = nullptr;
	this->size = 0;
}

template<typename T>
void Array<T>::clear()
{
	changeSize(0);
}

template<typename T>
bool Array<T>::findElementBool(T& element)
{
	for (int i{ 0 }; i < this->size; i++)
	{
		if (this->array[i] == element) return true;
	}

	return false;
}

template<typename T>
T Array<T>::findElementValue(T& element)
{
	for (int i{ 0 }; i < this->size; i++)
	{
		if (this->array[i] == element) return this->array[i];
	}

	return T{};
}

template<typename T>
T& Array<T>::operator [](const int index)
{
	assert(index < this->size && index >= 0);

	return this->array[index];
}

template<typename T>
const T& Array<T>::operator [](const int index) const
{
	assert(index < this->size && index >= 0);

	return this->array[index];
}

template<typename T>
const int Array<T>::getSize() const
{
	return this->size;
}