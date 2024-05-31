#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include "Deck.h"
#include "ItemMenu.h"

typedef std::string(*pointStrigFun)();

template<typename T>
class Menu
{
private:

	short choice;
	std::vector<ItemMenu<T>> itemsMenu;
	const std::string nameMenu;
	const std::string textQuestion;
	std::vector<pointStrigFun> additionalText;

public:
	static std::vector<std::string> textError;

	Menu(const std::string& _nameMenu, const std::string& _textQuestion,
		std::vector<ItemMenu<T>>&& _itemsMenu,
		std::vector<pointStrigFun> _additionalText = std::vector<pointStrigFun>{});

	Menu(const std::string& _nameMenu, const std::string& _textQuestion,
		std::vector<ItemMenu<T>>& _itemsMenu,
		std::vector<pointStrigFun> _additionalText = std::vector<pointStrigFun>{});


	void inputItemMenu();

	const short setChoicePlayer();

	static void addErrorText(std::string _textError);


	T& operator[](const short _choice);
};

