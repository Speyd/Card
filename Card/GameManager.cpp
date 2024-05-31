#include "GameManager.h"
#include "GiverCards.h"
#include "Move.h"
#include "Player.h"


short GameManager::maxAmountCard{ 0 };
short GameManager::maxAmountPlayer{ 0 };

void GameManager::setPlayers()
{
	GiverCards tempGiverCards{ generalDeck };
	for (int i{ 0 }; i < maxAmountPlayer; i++)
	{
		players.push_back(Player::setPlayer(GameHelper::setNamePlayer(players)));
		tempGiverCards.firstDistributionCardsPlayers(players[i]);
	}
}

GameManager::GameManager(const short _maxAmountCard, const short _maxAmountPlayer, std::unordered_map<TYPES_CARD, std::string>&& _baseTypesCards) :
	generalDeck{ Deck::creatDeckElement(std::move(_baseTypesCards)) }
{
	GameManager::maxAmountCard = _maxAmountCard;
	GameManager::maxAmountPlayer = _maxAmountPlayer;

	//setPlayers();
	//globalMove = new GlobalMove{ players, generalDeck };
}

const short GameManager::getMaxAmountCard()
{
	return maxAmountCard;
}

const short GameManager::getMaxAmountPlayer()
{
	return maxAmountPlayer;
}

void GameManager::getCard(int index)
{
	for (int i = 0; i < players[index]->getSizeDeck(); ++i) {
		if (players[index] != nullptr && players[index]->getCard(i) != nullptr) {
			std::cout << players[index]->getCard(i)->getName() << std::endl;
		}
	}
}

void GameManager::M()
{
	//this->globalMove->makeMove();
}