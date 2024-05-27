#pragma once
#include "Card.h"

class Spades : public Card
{
private:

	const SUITS suit{ SUITS::SPADES };
	const std::string name{ "Spades" };

public:

	Spades(SUITS _suit, TYPES_CARD typeCard, std::string nameType) :
		Card(typeCard, nameType, SUITS::SPADES == _suit) //TODO: ����������� ������ �� �� ����, ��� ���� "suit" �� �������� ������������������
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

