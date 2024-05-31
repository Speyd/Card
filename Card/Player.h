#pragma once
#include <iostream>
#include <cassert>
#include "Array.h"
#include "Deck.h"
#include "PASS_PLAYER.h"

class GameManager;

class Player
{
private:

	Array<Card*>* deck;

	const std::string name;
	PASS_PLAYER playerCondition;
	static short amountPlayer;

	Player(const std::string& _name);

public:

	~Player();

	static Player* setPlayer(const std::string& _name);

	const int getSizeDeck() const;

	const Array<Card*>* getDeck() const;

	Array<Card*>& setDeck();

	const std::string& getName() const;

	Card* getCard(const short index) const;

	std::string getCardName(const short index) const;

	const PASS_PLAYER getPlayerCondition() const;

	void setPlayerCondition(const PASS_PLAYER newPlayerCondition);

};

