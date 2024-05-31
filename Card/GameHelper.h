#pragma once
#include <iostream>
#include <sstream>
#include <vector>

#include "Player.h"
#include "Menu.h"

#include "RESULT_MOVE.h"
#include "PASS_PLAYER.h"

class GameHelper
{

public:

	static std::string setNamePlayer(std::vector<Player*>& players);

	static Card* checkMinSuitCard(Player* player);

	static std::string getSuitGame();

	static std::string getAmountCardsGeneralDeck();

	static std::string getTextForAttackPlayer(Array<Card*>* allCardPlayer, const std::string& textFeedingCards);

	static std::string getTextForDefendPlayer(std::vector<Card*>* allAttackCardPlayer, Card* attackCard, const std::string& textFeedingCards);

	static bool boolMenu(const std::string& nameMenu, const std::string& textQueation, std::vector<ItemMenu<bool>> items);

	static RESULT_MOVE checkConditionCard(std::vector<Card*>* allAttackCardPlayer, Player* player, CARD_CONDITION cardCondition);

	static int getAmountPassAttaker(std::vector<Player*> players);
};