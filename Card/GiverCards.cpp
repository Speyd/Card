#include "GiverCards.h"

GiverCards::GiverCards(Deck* _generalDeck) :
	generalDeck{ _generalDeck }
{}

void GiverCards::giveCard(Player* player)
{

	if (this->generalDeck == nullptr) return;

	for (int amountPlayerCard{ player->getSizeDeck() }, amountDeckCard{ this->generalDeck->getSize() };
		amountPlayerCard < 6 && amountDeckCard > 0;
		amountPlayerCard++, amountDeckCard--)
	{
		player->setDeck().addElement(this->generalDeck->getBeginCard());
		this->generalDeck->deleteBeginCard();
		break;
	}
}

void GiverCards::firstDistributionCardsPlayers(Player* player)
{
	if (this->generalDeck == nullptr) return;

	short averageAmountCard = this->generalDeck->getFullAmountCard() / 1;
	averageAmountCard = averageAmountCard == 0 ? 1 : averageAmountCard;
	averageAmountCard = averageAmountCard < 6 ? averageAmountCard : 6;

	if (this->generalDeck->getSize() != 0)
	{
		for (int i{ 0 }; i < averageAmountCard; i++)
		{
			player->setDeck().addElementToNullptr(this->generalDeck->getBeginCard());
			this->generalDeck->deleteBeginCard();
		}
	}
}

void GiverCards::distributingCardsPlayers(std::vector<Player*>& attackPlayers, Player* defendPlayer)
{

	if (this->generalDeck->getSize() == 0 || this->generalDeck == nullptr)
		return;

	for (Player* attaker : attackPlayers)
	{
		if (attaker == nullptr || attaker->getSizeDeck() >= 6)
			continue;

		giveCard(attaker);
	}

	giveCard(defendPlayer);
}