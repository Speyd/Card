#include "DefendInitialization.h"

bool DefendInitialization::CheckCardSuits(const Card* firstCard, const Card* secondCard)
{
	if (firstCard->getSuit() == secondCard->getSuit())
	{
		return true;
	}
	else if (firstCard->getTrump() == true || secondCard->getTrump() == true)
	{
		return true;
	}
	else return false;
}

const Card* DefendInitialization::ComparisonCardTypes(const Card* firstCard, const Card* secondCard)
{
	if (firstCard->getTrump() == true && secondCard->getTrump() == false)
	{
		return firstCard;
	}
	else if (secondCard->getTrump() == true && firstCard->getTrump() == false)
	{
		return secondCard;
	}
	else if (firstCard->getTypeCard() > secondCard->getTypeCard())
	{
		return firstCard;
	}
	else if (secondCard->getTypeCard() > firstCard->getTypeCard())
	{
		return secondCard;
	}
}

RESULT_ATTACK DefendInitialization::AttackCards(Card* defendingCard, const Card* attackingCard)
{

	if (defendingCard == nullptr) return RESULT_ATTACK::SUCCESSFUL_ATTACK;

	if (CheckCardSuits(defendingCard, attackingCard) == true)
	{
		if (defendingCard == ComparisonCardTypes(defendingCard, attackingCard))
		{
			return RESULT_ATTACK::UNSUCCESSFUL_ATTACK;
		}
		else
		{
			return RESULT_ATTACK::SUCCESSFUL_ATTACK;
		}
	}
	else
	{
		return RESULT_ATTACK::UNSUCCESSFUL_ATTACK;
	}
}