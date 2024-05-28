#pragma once
#include "Creator.h"
#include "Clubs.h"

class ClubsCreator : public Creator
{
	virtual Card* createCard(const SUITS suit, const TYPES_CARD typeCard, const std::string& nameType) override
	{
		return new Clubs{ suit, typeCard, nameType };
	}
};