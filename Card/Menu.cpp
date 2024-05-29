#include "Menu.h"

template<typename T>
std::vector<std::string> Menu<T>::textError;

template<typename T>
Menu<T>::Menu(const std::string& _nameMenu,
	const std::string& _textQuestion,
	std::vector<ItemMenu<T&>>&& _itemsMenu,
	std::vector<pointStrigFun> _additionalText) :

	choice{ 1 },
	nameMenu{ _nameMenu },
	textQuestion{ _textQuestion },
	additionalText{ _additionalText }
{
	for(auto item : _itemsMenu)
	{
		itemsMenu.push_back({ item.textSelection, &item.object });
	}
}

template<typename T>
Menu<T>::Menu(const std::string& _nameMenu,
	const std::string& _textQuestion,
	std::vector<ItemMenu<T*>>&& _itemsMenu,
	std::vector<pointStrigFun> _additionalText) :

	choice{ 1 },
	nameMenu{ _nameMenu },
	textQuestion{ _textQuestion },
	itemsMenu{ _itemsMenu },
	additionalText{ _additionalText }
{}

template<typename T>
void Menu<T>::inputItemMenu()
{
	size_t size{ this->itemsMenu.size() };

	std::cout << "\t\t\t" << this->nameMenu << std::endl;

	//TODO: дополнительная информация
	for (int i{ 0 }; i < this->additionalText.size(); i++)
	{
		//if (this->additionalText[i] != nullptr)
			//std::cout << this->additionalText[i](Deck::getDeck());
	}


	//TODO: варианты выбора
	for (size_t i{}; i < size; i++)
	{
		std::cout << i + 1 << ". " << this->itemsMenu[i].textSelection << std::endl;
	}


	//TODO: ошибки
	for (size_t i{ 0 }; i < this->textError.size(); i++)
	{
		std::cout << this->textError[i] << std::endl;
	}



	if (this->choice < 1 || this->choice > this->itemsMenu.size())
	{
		std::cout << "There is no such choice '" << this->choice << "'!" << std::endl;
	}
}

template<typename T>
const short Menu<T>::setChoicePlayer()
{
	if (this->itemsMenu.size() == 0) return -1;
	choice = 1;

	do
	{
		//system("cls");
		inputItemMenu();
		std::cout << textQuestion << ": "; std::cin >> this->choice;
	} while (this->choice < 1 || this->choice > this->itemsMenu.size());

	textError.clear();

	return --(this->choice);
}

template<typename T>
void Menu<T>::addErrorText(std::string _textError)
{
	textError.push_back(_textError);
}

template<typename T>
T& Menu<T>::operator[](const short _choice)					//TODO: With nullptr checker
{

	assert(_choice >= 0 && choice < this->itemsMenu.size());
	if constexpr (std::is_pointer<T>::value)
		assert(this->itemsMenu[_choice].object != nullptr);

	return *(this->itemsMenu[_choice].object);
}