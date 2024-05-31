#pragma once
#include <iostream>
#include <vector>
#include "Move.h"
#include "Deck.h"
#include "ChoicingCard.h"
#include "GameHelper.h"
#include "GiverCards.h"

class Player;
class GiverCards;
class Move;

class GameManager
{
private:

	std::vector<Player*> players;

	Deck* generalDeck;

	//GlobalMove* globalMove;

	static short maxAmountCard;
	static short maxAmountPlayer;

	void setPlayers();

public:

	GameManager(const short _maxAmountCard, const short _maxAmountPlayer, std::unordered_map<TYPES_CARD, std::string>&& _baseTypesCards);

	static const short getMaxAmountCard();

	static const short getMaxAmountPlayer();

	void getCard(int index);

	void M();
};



