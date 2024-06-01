#pragma once
#include <iostream>
#include <vector>
#include "Array.h"
#include "Menu.h"
#include "Player.h"
#include "Deck.h"

template<typename T>
class ChoicingElement
{
private:

	Menu<T> menu;
	std::vector<ItemMenu<T>> setItemsMenu(const Array<T>* elements, const std::string& lastTextChoice);

public:

	ChoicingElement(const std::string& _nameMenu,
		const std::string& _textQuestion,
		const std::string& lastTextChoice,
		const Array<T>* elements, std::vector<pointStrigFun> _additionalText = std::vector<pointStrigFun>{});

	T setElement();
};