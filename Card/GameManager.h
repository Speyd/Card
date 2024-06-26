#pragma once
#include <iostream>
#include <vector>
#include "Deck.h"

class Player;
class GiverCards;
class GlobalMove;
class Move;

class GameManager
{
private:

	std::vector<Player*> players;

	Deck* generalDeck;

	GlobalMove* globalMove;

	static short maxAmountCard;
	static short maxAmountPlayer;

	void setPlayers();

public:

	GameManager(const short _maxAmountPlayer, const short _maxAmountCard, std::unordered_map<TYPES_CARD, std::string>&& _baseTypesCards);

	static const short getMaxAmountCard();

	static const short getMaxAmountPlayer();

	void startGame();
};



