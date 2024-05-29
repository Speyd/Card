#pragma once

#include "InfoTypeCard.h"
#include "SUITS.h"
#include "CARD_CONDITION.h"

class Card
{
private:

	const InfoTypeCard* infoType;
	const bool isTrump;
	CARD_CONDITION condition;
public:

	Card(TYPES_CARD typeCard, std::string nameType,
		bool _trumpCard, CARD_CONDITION _condition = CARD_CONDITION::UNTOUCHED);

	Card(Card&& card) noexcept;

	virtual ~Card();



	virtual std::string getSuitName() const = 0;

	virtual SUITS getSuit() const = 0;

	bool getTrump() const;

	const CARD_CONDITION getCondition() const;

	void setCondition(const CARD_CONDITION newCondition);

	TYPES_CARD getTypeCard() const;

	std::string getTypeName() const;

	std::string getName() const;

};

