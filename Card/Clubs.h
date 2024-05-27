#pragma once
#include "Card.h"

class Clubs : public Card
{
private:

	const SUITS suit{ SUITS::CLUBS };
	const std::string name{ "Clubs" };

public:

	Clubs(SUITS _suit, TYPES_CARD typeCard, std::string nameType) :
		Card(typeCard, nameType, SUITS::CLUBS == _suit) //TODO: вынужненный хардко из за того, что поле "suit" не успевает инициализироваться
	{}

	virtual ~Clubs() override
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


