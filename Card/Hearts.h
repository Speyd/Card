#pragma once
#include "Card.h"

class Hearts : public Card
{
private:

	const SUITS suit{ SUITS::HEARTS };
	const std::string name{ u8"?Hearts" };

public:

	Hearts(SUITS _suit, TYPES_CARD typeCard, std::string nameType) :
		Card(typeCard, nameType, SUITS::HEARTS == _suit) //TODO: вынужненный хардко из за того, что поле "suit" не успевает инициализироваться
	{}

	virtual ~Hearts() override
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

