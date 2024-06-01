#include "GameHelper.h"

std::string GameHelper::setNamePlayer(std::vector<Player*>& players, const int numberPlayer)
{
	std::string name{};
	bool uniqueName{ true };
	do
	{
		if (uniqueName == true)
			std::cout << "Enter name new Player\"" << numberPlayer << "\": ";
		else
			std::cout << "You entered an already existing name!\nEnter name new Player again: ";

		std::cin >> name;

		uniqueName = true;
		for (int i{ 0 }; i < players.size(); i++)
		{
			if (name == players[i]->getName())
			{
				uniqueName = false;
				break;
			}
		}

	} while (uniqueName != true);

	return name;
}

Card* GameHelper::checkMinSuitCard(Player* player)
{
	Card* minCard{ nullptr };
	int size = player->getDeck()->getSize();

	for (int i{ 0 }; i < size; i++)
	{
		if (minCard == nullptr && player->getCard(i)->getTrump() == true)
			minCard = player->getCard(i);
		if (minCard != nullptr && player->getCard(i)->getTrump() == true && player->getCard(i)->getTypeCard() < minCard->getTypeCard())
			minCard = player->getCard(i);
	}

	return minCard;
}

std::string GameHelper::getSuitGame()
{
	std::stringstream tempText;

	tempText << "Trump card: ";

	switch (Deck::getDeckElement()->getTrump())
	{
	case SUITS::CLUBS:
		tempText << "Clubs";
		break;
	case SUITS::DIAMONDS:
		tempText << "Diamonds";
		break;
	case SUITS::HEARTS:
		tempText << "Hearts";
		break;
	case SUITS::SPADES:
		tempText << "Spades";
		break;
	default:
		tempText << "ERROR TYPE";
		break;
	}

	tempText << "\n\n";
	return tempText.str();
}

std::string GameHelper::getAmountCardsGeneralDeck()
{
	return "Left in the general deck " + std::to_string(Deck::getDeckElement()->getSize()) + " card(-s)!\n\n";
}

std::string GameHelper::getTextForAttackPlayer(Array<Card*>* allCardPlayer, const std::string& textFeedingCards)
{
	std::stringstream textAttackCards;
	if (allCardPlayer->getSize() != 0)
		textAttackCards << textFeedingCards << ": ";

	for (int i{ 0 }; i < allCardPlayer->getSize(); i++)
	{
		if ((*allCardPlayer)[i] != nullptr)
			textAttackCards << (*allCardPlayer)[i]->getName() << " | ";
		else
			textAttackCards << "NONE | ";
	}

	return textAttackCards.str();
}

std::string GameHelper::getTextForDefendPlayer(std::vector<Card*>* allAttackCardPlayer, Card* attackCard, const std::string& textFeedingCards)
{
	std::stringstream textAttackCards;
	if (allAttackCardPlayer->size() != 0)
		textAttackCards << textFeedingCards << ": ";

	for (auto card : *allAttackCardPlayer)
	{
		if (card == attackCard)
			textAttackCards << "\033[1m YOUR DEFF ";

		textAttackCards << card->getName();
		if (card->getCondition() == CARD_CONDITION::BROKEN)
			textAttackCards << "(broken card)";
		else if (card->getCondition() == CARD_CONDITION::TAKEN)
			textAttackCards << "(taken card)";

		textAttackCards << "\033[0m" << " | ";
	}

	return textAttackCards.str();
}

bool GameHelper::boolMenu(const std::string& nameMenu, const std::string& textQueation, std::vector<ItemMenu<bool>> items)
{
	Menu<bool> menuConfirmationChoice
	{
		nameMenu,
		textQueation,
		move(items)
	};

	return menuConfirmationChoice[menuConfirmationChoice.setChoicePlayer()];
}

RESULT_MOVE GameHelper::checkConditionCard(std::vector<Card*>* allAttackCardPlayer, Player* player, CARD_CONDITION cardCondition)
{
	for (auto& element : *allAttackCardPlayer)
	{
		if (element->getCondition() == cardCondition)		//TODO: Если текущий атакующий пропустил ход но до этого кинул карту(-ты)
		{
			player->setPlayerCondition(PASS_PLAYER::PASS_NOT);
			return RESULT_MOVE::SUCCESSFULLY;
		}
	}
	//TODO: Если текущий атакующий пропустил ход но до этого не кинул ни одной карты но на столе больще 0 атакующтх карт 
	player->setPlayerCondition(PASS_PLAYER::PASS);
	return RESULT_MOVE::UNSUCCESSFUL;
}

int GameHelper::getAmountPassAttaker(std::vector<Player*> players)
{
	int amountPassAttaker{ 0 };
	for (Player* player : players)
	{
		if (player->getPlayerCondition() == PASS_PLAYER::PASS)
			amountPassAttaker++;
	}

	return amountPassAttaker;
}

std::vector<ItemMenu<Card*>> GameHelper::getItemMenuCard(const Array<Card*>* deck, const std::string& lastTextChoice)
{
	std::vector<ItemMenu<Card*>> tempItemMenu;

	int size = deck->getSize();

	for (int i{ 0 }; i < size; i++)
		tempItemMenu.push_back({ (*deck)[i]->getName(), std::make_shared<Card*>((*deck)[i]) });

	if(lastTextChoice.empty() == false)
		tempItemMenu.push_back({ lastTextChoice, std::make_shared<Card*>(nullptr) });
}

std::vector<ItemMenu<Player*>> GameHelper::getItemMenuPlayer(const Array<Player*>* players, const std::string& lastTextChoice)
{
	std::vector<ItemMenu<Card*>> tempItemMenu;

	int size = players->getSize();

	for (int i{ 0 }; i < size; i++)
		tempItemMenu.push_back({ (*players)[i]->getName(), std::make_shared<Card*>((*players)[i]) });

	if (lastTextChoice.empty() == false)
		tempItemMenu.push_back({ lastTextChoice, std::make_shared<Card*>(nullptr) });
}