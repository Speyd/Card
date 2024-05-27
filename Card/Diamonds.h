#pragma once
#include "Card.h"


class Diamonds : public Card
{
private:

	const SUITS suit{ SUITS::DIAMONDS };
	const std::string name{ "Diamonds" };

public:

	Diamonds(SUITS _suit, TYPES_CARD typeCard, std::string nameType) :
		Card(typeCard, nameType, SUITS::DIAMONDS == _suit) //TODO: ����������� ������ �� �� ����, ��� ���� "suit" �� �������� ������������������
	{}

	virtual  ~Diamonds() override
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
