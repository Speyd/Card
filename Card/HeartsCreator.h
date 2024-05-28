#pragma once
#include "Creator.h"
#include "Hearts.h"

class HeartsCreator : public Creator
{
	virtual Card* createCard(const SUITS suit, const TYPES_CARD typeCard, const std::string& nameType) override
	{
		return new Hearts{ suit, typeCard, nameType };
	}
};