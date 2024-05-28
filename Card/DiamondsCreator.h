#pragma once
#include "Creator.h"
#include "Diamonds.h"

class DiamondsCreator : public Creator
{
	virtual Card* createCard(const SUITS suit, const TYPES_CARD typeCard, const std::string& nameType) override
	{
		return new Diamonds{ suit, typeCard, nameType };
	}
};