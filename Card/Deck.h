#pragma once
#include <unordered_map>
#include <cassert>
#include "TYPES_CARD.h"
#include "SUITS.h"
#include "Card.h"
#include "MenuCreatCard.h"

class Deck
{
private:

	const std::unordered_map<TYPES_CARD, std::string> baseTypesCards;
	const SUITS globalTrump;
	std::vector<Card*> generalDeck;

	static Deck* deckElement;

	void fillDeck();
	void changeCardOrder();

	Deck(std::unordered_map<TYPES_CARD, std::string>&& _baseTypesCards);


public:

	~Deck();

	static Deck* creatDeckElement(std::unordered_map<TYPES_CARD, std::string>&& _baseTypesCards);

	static const Deck* getDeckElement();

	Card* getCard(const int index) const;

	const SUITS getTrump() const;

	int getSize() const;

	short getFullAmountCard() const;

	Card* getBeginCard() const;

	void deleteBeginCard();

	void outDeck();

	Deck(Deck& deck) = delete;
	void operator=(const Deck&) = delete;
};

