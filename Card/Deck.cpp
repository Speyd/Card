#include "Deck.h"

Deck* Deck::deckElement = nullptr;

Deck::Deck(std::unordered_map<TYPES_CARD, std::string>&& _baseTypesCards) :
	baseTypesCards{ _baseTypesCards },
	globalTrump{ SUITS(rand() % ((int(SUITS::MAX_VALUE) - 1) - 0 + 1) + 0) }
{
	fillDeck();
}

Deck::~Deck()
{
	for (Card* card : generalDeck)
	{
		if (card != nullptr) delete card;
	}
}

void Deck::fillDeck()
{
	for (int trumpIndex{ 0 }; trumpIndex < SUITS::MAX_VALUE; trumpIndex++)
	{
		for (auto tempTypeCard : this->baseTypesCards)
		{
			this->generalDeck.push_back(MenuCreatCard::setCard(this->globalTrump, SUITS(trumpIndex), tempTypeCard.first, tempTypeCard.second));
		}
	}
}

void Deck::changeCardOrder()
{
	size_t size{ this->generalDeck.size() };

	for (int firstIndex{ 0 }, secondIndex{ 0 }; firstIndex < size; firstIndex++)
	{
		secondIndex = rand() % ((size - 1) - 0) + 1;
		std::swap(this->generalDeck[firstIndex], this->generalDeck[secondIndex]);
	}

}

Deck* Deck::creatDeckElement(std::unordered_map<TYPES_CARD, std::string>&& _baseTypesCards)
{
	if (deckElement == nullptr)
		deckElement = new Deck{ move(_baseTypesCards) };

	return deckElement;
}

const Deck* Deck::getDeckElement()
{
	return deckElement;
}

void Deck::outDeck()
{
	for (auto element : this->generalDeck)
	{
		std::cout << element->getTypeName() << std::endl;
	}

}

Card* Deck::getCard(const int index) const
{
	assert(index < this->generalDeck.size() && index >= 0);
	return this->generalDeck[index];
}

const SUITS Deck::getTrump() const
{
	return this->globalTrump;
}

int Deck::getSize() const
{
	return int(this->generalDeck.size());
}

short Deck::getFullAmountCard() const
{
	return  short(this->baseTypesCards.size() * SUITS::MAX_VALUE);
}

Card* Deck::getBeginCard() const
{
	return this->generalDeck.size() != 0 ? *(this->generalDeck.begin()) : nullptr;
}

void Deck::deleteBeginCard()
{
	if (this->generalDeck.size() != 0)
	{
		this->generalDeck.erase(this->generalDeck.begin());
	}
}