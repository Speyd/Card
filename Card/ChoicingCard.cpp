#include "ChoicingCard.h"

ChoicingCard::ChoicingCard(const std::string& _nameMenu,
	const std::string& _textQuestion,
	const std::string& lastTextChoice,
	const Array<Card*>* player,
	std::vector<pointStrigFun> _additionalText) :

	menu{ _nameMenu, _textQuestion, setItemsMenu(player, lastTextChoice), _additionalText }
{}


std::vector<ItemMenu<Card*>> ChoicingCard::setItemsMenu(const Array<Card*>* player, const std::string& lastTextChoice)			//TODO: вынужденные костыли
{
	std::vector<ItemMenu<Card*>> tempItemMenu;
	int size = player->getSize();

	for (int i{ 0 }; i < size; i++)
	{
		tempItemMenu.push_back({ (*player)[i]->getName(), std::make_shared<Card*>((*player)[i]) });
	}

	tempItemMenu.push_back({ lastTextChoice, nullptr });

	return tempItemMenu;
}

Card* ChoicingCard::setCard()
{
	return menu[menu.setChoicePlayer()];
}