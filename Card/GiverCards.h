#pragma once
#include <vector>
#include <memory>
#include "Player.h"
#include "Array.h"

class GameManager;

class GiverCards
{
private:

	Deck* generalDeck;

public:

	GiverCards(Deck* _generalDeck);

	void giveCard(Player* player);

	void firstDistributionCardsPlayers(Player* player);

	void distributingCardsPlayers(std::vector<Player*>& attackPlayers, Player* defendPlayer);
};


