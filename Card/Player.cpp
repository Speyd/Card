#include "Player.h"

short Player::amountPlayer{ 0 };

Player::Player(const std::string& _name) :
	name{ _name },
	playerCondition{ PASS_PLAYER::PASS_NOT },
	deck{ new Array<Card*> }
{
	amountPlayer++;
}


Player::~Player()
{
	amountPlayer--;
}

Player* Player::setPlayer(const std::string& _name)
{
	if (amountPlayer < 1)				//TODO: GameManager::getMaxAmountPlayer() גלוסעמ 1
		return new Player{ _name };
	else
	{
		std::cout << "The number of allowed created players has reached the maximum!" << std::endl;
		return nullptr;
	}
}

const int Player::getSizeDeck() const
{
	return deck != nullptr ? this->deck->getSize() : 0;
}

const Array<Card*>* Player::getDeck() const
{
	return this->deck;
}

Array<Card*>& Player::setDeck()
{
	return *(this->deck);
}

const std::string& Player::getName() const
{
	return this->name;
}

Card* Player::getCard(const short index) const
{
	assert(index >= 0 && index < this->deck->getSize());
	return (*(this->deck))[index];
}

void Player::setPlayerCondition(const PASS_PLAYER newPlayerCondition)
{
	this->playerCondition = newPlayerCondition;
}

std::string Player::getCardName(const short index) const
{
	return getCard(index) != nullptr ? getCard(index)->getTypeName() : "ERROR_CARD";
}

const PASS_PLAYER Player::getPlayerCondition() const
{
	return this->playerCondition;
}