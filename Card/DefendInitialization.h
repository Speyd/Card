#pragma once
#include "RESULT_ATTACK.h"
#include "Card.h"

class DefendInitialization
{
public:

	static bool CheckCardSuits(const Card* firstCard, const Card* secondCard);

	static const Card* ComparisonCardTypes(const Card* firstCard, const Card* secondCard);

	static RESULT_ATTACK AttackCards(Card* defendingCard, const Card* attackingCard);
};