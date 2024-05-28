#pragma once
#include "Card.h"

class Creator
{
public:

	virtual Card* createCard(const SUITS suit, const TYPES_CARD typeCard, const std::string& nameType) = 0;

};