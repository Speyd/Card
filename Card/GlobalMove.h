#pragma once
#include <vector>
#include <sstream>

#include "Move.h"
#include "Player.h"
#include "GiverCards.h"
#include "DEFINITIONS_MOVE.h"

class GameManager;


class GlobalMove
{
private:

	std::vector<Player*> attackPlayers;
	Player* defendPlayer;

	GiverCards* giverCards;
	Array<Player*>* topWinnerPlayers = new Array<Player*>{ 0 };

	Player* definitionDefendPlayer(std::unordered_map<Card*, Player*>& tempArray);

	DEFINITIONS_MOVE definitionMove();

	void definitionAttackingPlayers(std::vector<Player*>& players);

	void changePlayerRole(const short startAmountDefenderCard);

	void definitionTops();

	void actionsAfterMove(const short startAmountDefenderCard);

	bool showDeckWinnerPlayer(Player* choicePlayer);

	void showTopWinnerPlayer();

public:

	GlobalMove(std::vector<Player*>& players, Deck* generalDeck);

	void makeMove();

};

