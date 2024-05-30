#include "Card.h"


Card::Card(TYPES_CARD typeCard, std::string nameType, bool _trumpCard, CARD_CONDITION _condition) :
	infoType{ new InfoTypeCard{ typeCard, nameType } },
	isTrump{ _trumpCard },
	condition{ _condition }
{}

Card::Card(Card&& card) noexcept:
	Card{ card.infoType->type, card.infoType->nameType, card.isTrump, card.condition}
{}

Card::~Card()
{
	if (this->infoType != nullptr)
		delete this->infoType;
}


bool Card::getTrump() const
{
	return this->isTrump;
}

const CARD_CONDITION Card::getCondition() const
{
	return this->condition;
}
void Card::setCondition(const CARD_CONDITION newCondition)
{
	this->condition = newCondition;
}

TYPES_CARD Card::getTypeCard() const
{
	return this->infoType->type;
}
std::string Card::getName() const
{
	return this->getSuitName() + " " + this->infoType->nameType;
}

std::string Card::getTypeName() const
{
	return this->infoType->nameType;
}