#include "MenuCreatCard.h"

Creator* MenuCreatCard::creator = nullptr;

MenuCreatCard::~MenuCreatCard()
{
	if (creator != nullptr) delete creator;
}

Card* MenuCreatCard::setCard(const SUITS trump, const SUITS suit, TYPES_CARD typeCard, const std::string& nameType)
{
	switch (suit)
	{
	case SUITS::DIAMONDS:
		creator = new DiamondsCreator{};
		break;
	case SUITS::HEARTS:
		creator = new HeartsCreator{};
		break;
	case SUITS::CLUBS:
		creator = new ClubsCreator{};
		break;
	case SUITS::SPADES:
		creator = new SpadesCreator{};
		break;
	default:
		std::cout << "ERROR TYPE" << std::endl;
		creator = nullptr;
		break;
	}

	return creator->createCard(trump, typeCard, nameType);
}