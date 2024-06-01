#include "ChoicingElement.h"

template<typename T>
ChoicingElement<T>::ChoicingElement(const std::string& _nameMenu,
	const std::string& _textQuestion,
	const std::string& lastTextChoice,
	const Array<T>* elements,
	std::vector<pointStrigFun> _additionalText) :

	menu{ _nameMenu, _textQuestion, setItemsMenu(elements, lastTextChoice), _additionalText }
{}

template<>

std::vector<ItemMenu<Card*>> ChoicingElement<Card*>::setItemsMenu(const Array<Card*>* elements, const std::string& lastTextChoice)			//TODO: вынужденные костыли
{
	std::vector<ItemMenu<Card*>> tempItemMenu;
	int size = elements->getSize();

	for (int i{ 0 }; i < size; i++)
	{
		tempItemMenu.push_back({ (*elements)[i]->getName(), std::make_shared<Card*>((*elements)[i]) });
	}

	tempItemMenu.push_back({ lastTextChoice, std::make_shared<Card*>(nullptr) });

	return tempItemMenu;
}

template<>
std::vector<ItemMenu<Player*>> ChoicingElement<Player*>::setItemsMenu(const Array<Player*>* elements, const std::string& lastTextChoice)			//TODO: вынужденные костыли
{
	std::vector<ItemMenu<Player*>> tempItemMenu;
	int size = elements->getSize();

	for (int i{ 0 }; i < size; i++)
	{
		tempItemMenu.push_back({ (*elements)[i]->getName(), std::make_shared<Player*>((*elements)[i]) });
	}

	tempItemMenu.push_back({ lastTextChoice, std::make_shared<Player*>(nullptr) });

	return tempItemMenu;
}

template<typename T>
T ChoicingElement<T>::setElement()
{
	return menu[menu.setChoicePlayer()];
}