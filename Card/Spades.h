#pragma once
#include "Card.h"

class Spades : public Card
{
private:

	const SUITS suit{ SUITS::SPADES };
	const std::string name{ u8"♠ Spades" };

public:

	Spades(SUITS _suit, TYPES_CARD typeCard, std::string nameType) :
		Card(typeCard, nameType, SUITS::SPADES == _suit) //TODO: вынужненный хардко из за того, что поле "suit" не успевает инициализироваться
	{}

	virtual  ~Spades() override
	{}

	virtual std::string getSuitName() const
	{
		return this->name;
	}

	virtual SUITS getSuit() const
	{
		return this->suit;
	}
};

