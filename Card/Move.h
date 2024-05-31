#pragma once
#include <iostream>
#include <sstream>
#include <vector>

#include "GameHelper.h"
#include "Player.h"
#include "Menu.h"
#include "ChoicingCard.h"
#include "DefendInitialization.h"

#include "CARD_CONDITION.h"
#include "PASS_PLAYER.h"
#include "SELECTING_ADDITIONAL_CARD.h"
#include "RESULT_MOVE.h"

class GameManager;

class Move
{
private:

	static Array<Card*>* allDefendCardPlayer;
	static std::vector<Card*>* allAttackCardPlayer;

	static bool checkTrueCardAttack(Card* card, Array<Card*>& allAttackCardPlayer);

	static bool checkTookCards(Array<Card*>* defendDeck);

	static void changeConditionAttackCards(CARD_CONDITION changeType);

	static void successfulAttack(Player* attackPlayer, Card* selectedCard);

	static void successfulDefense(Card* attackCard, Card* defendCard, Array<Card*>* defendDeck);

	static void unseccessfulDefense(Array<Card*>* defendDeck);

	static SELECTING_ADDITIONAL_CARD suspicionThrow(const std::string& nameMenu, const std::string& textQueation,
		const std::string& textErrorChoice, std::vector<ItemMenu<bool>> items);

	static RESULT_MOVE setChoiceAttackCard(Player* attackPlayer, const int amountCardDefendPlayer,
		const std::string& nameAttacker, const std::string& nameDefender);

	static RESULT_MOVE setChoiceDefendCard(Array<Card*>* defendDeck, const std::string& defenderName, const std::string& nameAttaker);



public:

	static void MoveInitialization(Player* attackPlayer, Player* defendPlayer, int startAmountDefenderCard);

	static void clearAllDefendCardPlayer();

	static void clearAllAttackCardPlayer();

	static const int getAmountAttackCard();


};