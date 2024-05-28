#pragma once
#include "Creator.h"
#include "Spades.h"

class SpadesCreator : public Creator
{
	virtual Card* createCard(const SUITS suit, const TYPES_CARD typeCard, const std::string& nameType) override
	{
		return new Spades{ suit, typeCard, nameType };
	}
};