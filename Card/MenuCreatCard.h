#pragma once
#include <iostream>
#include "Creator.h"
#include "DiamondsCreator.h"
#include "ClubsCreator.h"
#include "HeartsCreator.h"
#include "SpadesCreator.h"

class MenuCreatCard
{
private:

	static Creator* creator;

public:

	~MenuCreatCard();

	static Card* setCard(const SUITS suit, const SUITS trump, TYPES_CARD typeCard, const std::string& nameType);

};
