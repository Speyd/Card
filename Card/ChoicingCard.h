#pragma once
#include <iostream>
#include <vector>
#include "Array.h"
#include "Menu.h"
#include "Deck.h"

class ChoicingCard
{
private:

	Menu<Card*> menu;
	std::vector<ItemMenu<Card*>> setItemsMenu(const Array<Card*>* player, const std::string& lastTextChoice);

public:

	ChoicingCard(const std::string& _nameMenu,
		const std::string& _textQuestion,
		const std::string& lastTextChoice,
		const Array<Card*>* player, std::vector<pointStrigFun> _additionalText = std::vector<pointStrigFun>{});

	Card* setCard();
};