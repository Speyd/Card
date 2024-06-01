#include "Move.h"
#include "GameManager.h"


Array<Card*>* Move::allDefendCardPlayer = nullptr;
std::vector<Card*>* Move::allAttackCardPlayer = nullptr;

bool Move::checkTrueCardAttack(Card* card, Array<Card*>& allAttackCardPlayer)
{
	if (allAttackCardPlayer.getSize() == 0)
		return true;

	for (int i{ 0 }; i < allAttackCardPlayer.getSize(); i++)
	{
		if (allAttackCardPlayer[i]->getSuit() == card->getSuit())
			return true;
	}

	return false;
}


bool Move::checkTookCards(Array<Card*>* defendDeck)
{
	bool chackTrueCompare{ false };
	for (auto& card : *allAttackCardPlayer)
	{
		if (card->getCondition() == CARD_CONDITION::TAKEN)
		{
			chackTrueCompare = true;
			break;
		}
	}

	if (chackTrueCompare == false)
		return chackTrueCompare;

	for (auto& card : *allAttackCardPlayer)
	{
		if (card->getCondition() != CARD_CONDITION::TAKEN)
		{
			card->setCondition(CARD_CONDITION::TAKEN);
			defendDeck->addUniqueElement(card);
		}
	}
	return chackTrueCompare;
}

void Move::changeConditionAttackCards(CARD_CONDITION changeType)
{
	for (auto& card : *allAttackCardPlayer)
		card->setCondition(changeType);
}

SELECTING_ADDITIONAL_CARD Move::suspicionThrow(const std::string& nameMenu, const std::string& textQueation,
	const std::string& textErrorChoice, std::vector<ItemMenu<bool>> items)
{

	bool resultMenu = GameHelper::boolMenu(nameMenu, textQueation, items, false);

	if (resultMenu == false && allAttackCardPlayer->size() == 0)
		Menu<Card*>::textError.push_back(textErrorChoice);
	else if (resultMenu == false && allAttackCardPlayer->size() > 0)
		return SELECTING_ADDITIONAL_CARD::EXIT;

	return SELECTING_ADDITIONAL_CARD::CONTINUE;
}


RESULT_CHECK_SELECTED Move::checkSelectedCard(Card* selectedCard, Array<Card*>* allCards, Player* attackPlayer)
{
	if (selectedCard != nullptr)		//TODO: Если атакующий бросил карту
	{
		if (GameHelper::boolMenu(
			"Your choice",
			"Do you really want to attack with this card?",
			{ { "Yes", std::make_shared<bool>(true) }, { "No", std::make_shared<bool>(false) } }, false)
			== true)
		{
			if (checkTrueCardAttack(selectedCard, *allCards) == true)
				successfulAttack(attackPlayer, selectedCard);
			else
				Menu<bool>::textError.push_back("The card you threw does not match the data!");
		}
		return RESULT_CHECK_SELECTED::NEW_SELECTION;
	}
	else if (selectedCard == nullptr && allAttackCardPlayer->size() > 0)				//TODO: Если атакующий захотел пропустить ход и количество атакующих карт на столе больше 0
	{
		allCards->clear();
		return RESULT_CHECK_SELECTED::FINISH_SELECTION;
	}
	else if (selectedCard == nullptr && allAttackCardPlayer->size() == 0)		//TODO: Если текущий атакующий пропустил ход но количество атакующих карт на столе равно 0
	{
		Menu<Card*>::textError.push_back("You need to attack with at least one card to exit!");
		return RESULT_CHECK_SELECTED::PAVE_SELECTION;
	}

	return RESULT_CHECK_SELECTED::NEW_SELECTION;
}

void Move::successfulAttack(Player* attackPlayer, Card* selectedCard)
{
	selectedCard->setCondition(CARD_CONDITION::UNTOUCHED);
	attackPlayer->setDeck().discardElement(selectedCard);
	attackPlayer->setPlayerCondition(PASS_PLAYER::PASS_NOT);
	allAttackCardPlayer->push_back(selectedCard);
}


RESULT_MOVE Move::setChoiceAttackCard(Player* attackPlayer, const int amountCardDefendPlayer,
	const std::string& nameAttacker, const std::string& nameDefender)
{
	if (amountCardDefendPlayer == 0 || allAttackCardPlayer->size() >= amountCardDefendPlayer ||
		allAttackCardPlayer->size() > GameManager::getMaxAmountCard() || attackPlayer->getSizeDeck() == 0)
	{
		attackPlayer->setPlayerCondition(PASS_PLAYER::PASS);
		return RESULT_MOVE::UNSUCCESSFUL;
	}

	Array<Card*>* allCards = new Array<Card*>;
	const size_t startAmountAttackCard{ allAttackCardPlayer->size() };
	do
	{
		allCards->addArrayElement(*allAttackCardPlayer);
		allCards->addArrayElement(allDefendCardPlayer);


		Menu<Card*>::textError.push_back(GameHelper::getTextForAttackPlayer(allCards, "Cards that have already been thrown by both sides"));
		Menu<Card*> choicingAttackCard
		{
			"Attack card",
			"Attacker \033[1m\"" + nameAttacker + "\"\033[0m attacks Defender \"" + nameDefender + "\"\nWhich card do you want to attack with?",
			GameHelper::getItemMenuCard(attackPlayer->getDeck(), "Pass the move"),
			std::vector<pointStrigFun>{ &GameHelper::getSuitGame,& GameHelper::getAmountCardsGeneralDeck}
		};
		Card* selectedCard = choicingAttackCard[choicingAttackCard.setChoicePlayer()];




		switch (checkSelectedCard(selectedCard, allCards, attackPlayer))
		{
		case RESULT_CHECK_SELECTED::PAVE_SELECTION:
			continue;
			break;
		case RESULT_CHECK_SELECTED::FINISH_SELECTION:
			return GameHelper::checkConditionCard(allAttackCardPlayer, attackPlayer, CARD_CONDITION::UNTOUCHED);
			break;
		}



		if (suspicionThrow(
			"Your choice",
			"Do you want to throw another card?",
			"You need to attack with at least one card to exit!",
			{ {"Yes", std::make_shared<bool>(true)}, {"No", std::make_shared<bool>(false)} }) == SELECTING_ADDITIONAL_CARD::EXIT)
		{
			break;
		}

		allCards->clear();

	} while (allAttackCardPlayer->size() < amountCardDefendPlayer && allAttackCardPlayer->size() <= 6 && attackPlayer->getSizeDeck() != 0);


	allCards->clear();
	if (attackPlayer->getSizeDeck() == 0 || startAmountAttackCard == allAttackCardPlayer->size())
		attackPlayer->setPlayerCondition(PASS_PLAYER::PASS);
	else
		attackPlayer->setPlayerCondition(PASS_PLAYER::PASS_NOT);

	return RESULT_MOVE::SUCCESSFULLY;
}



void Move::successfulDefense(Card* attackCard, Card* defendCard, Array<Card*>* defendDeck)
{
	attackCard->setCondition(CARD_CONDITION::BROKEN);
	allDefendCardPlayer->addElement(defendCard);
	defendDeck->discardElement(defendCard);
	attackCard++;
}

void Move::unseccessfulDefense(Array<Card*>* defendDeck)
{
	changeConditionAttackCards(CARD_CONDITION::TAKEN);
	defendDeck->addArrayElement(*allAttackCardPlayer);
	defendDeck->addArrayElement(allDefendCardPlayer);
}

RESULT_MOVE Move::setChoiceDefendCard(Array<Card*>* defendDeck, const std::string& defenderName, const std::string& nameAttaker)
{
	if (checkTookCards(defendDeck) == true)   //TODO:если защитник до того забрал карты и другой атакуйщий подкинул новые
		return RESULT_MOVE::UNSUCCESSFUL;

	for (auto& attackCard : *allAttackCardPlayer)
	{
		if (attackCard->getCondition() == CARD_CONDITION::BROKEN)			//TODO: пропуск побитых карт
		{
			attackCard++;
			continue;
		}


		Card* defendCard{ nullptr };
		Menu<Card*> choicingDefendCard
		{
			"Defend card",
			"Defender \033[1m\"" + defenderName + "\"\033[0m \nWhich card do you want to use for defend against card \033[1m"
			+ attackCard->getName() + "\033[0m?",
			GameHelper::getItemMenuCard(defendDeck, "Take card(-s)"),
			std::vector<pointStrigFun>{ &GameHelper::getSuitGame,& GameHelper::getAmountCardsGeneralDeck}
		};


		do
		{
			Menu<Card*>::textError.push_back(GameHelper::getTextForDefendPlayer
			(
				allAttackCardPlayer,
				attackCard, 
				"\033[1m" + nameAttaker + "\033[0m threw cards that need to be defended against")
			);

			defendCard = choicingDefendCard[choicingDefendCard.setChoicePlayer()];

		} while (defendCard != nullptr && GameHelper::boolMenu(
				"Your choice", 
				"Do you really want to defend with this card?", 
				{ {"Yes", std::make_shared<bool>(true)}, {"No", std::make_shared<bool>(false)} }, false
		) == false);



		if (DefendInitialization::AttackCards(defendCard, attackCard) == RESULT_ATTACK::UNSUCCESSFUL_ATTACK)
			successfulDefense(attackCard, defendCard, defendDeck);
		else
		{
			if (attackCard != *allAttackCardPlayer->begin())attackCard--;

			if (defendCard == nullptr &&
				GameHelper::boolMenu
				(
					"Your choice",
					"Do you want to take the card (You may not be able to beat the attacker)?",
					{ {"Yes", std::make_shared<bool>(true)}, {"No", std::make_shared<bool>(false)}}, false
				)== true)
			{
				unseccessfulDefense(defendDeck);
				return RESULT_MOVE::UNSUCCESSFUL;
			}
			else if (defendCard != nullptr)
				Menu<Card*>::textError.push_back("The card you tried to defend with is not suitable, try defending with another card!");
		}

	}

	return RESULT_MOVE::SUCCESSFULLY;

}



void Move::MoveInitialization(Player* attackPlayer, Player* defendPlayer, int startAmountDefenderCard)
{
	if (allAttackCardPlayer == nullptr)
		allAttackCardPlayer = new std::vector<Card*>;
	if (allDefendCardPlayer == nullptr)
		allDefendCardPlayer = new Array<Card*>;


	RESULT_MOVE checkTrueDefend{ RESULT_MOVE::SUCCESSFULLY };
	do
	{
		checkTrueDefend = setChoiceAttackCard(attackPlayer, startAmountDefenderCard, attackPlayer->getName(), defendPlayer->getName());
		if (checkTrueDefend == RESULT_MOVE::SUCCESSFULLY)
			checkTrueDefend = setChoiceDefendCard(&defendPlayer->setDeck(), defendPlayer->getName(), attackPlayer->getName());

	} while (checkTrueDefend != RESULT_MOVE::UNSUCCESSFUL);


}



void Move::clearAllDefendCardPlayer()
{
	allDefendCardPlayer->fullClear();
}

void Move::clearAllAttackCardPlayer()
{
	if (allAttackCardPlayer->size() != 0)
		allAttackCardPlayer->clear();
}

const int Move::getAmountAttackCard()
{
	return int(allAttackCardPlayer->size());
}