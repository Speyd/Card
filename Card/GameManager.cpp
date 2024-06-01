#include "GameManager.h"
#include "GiverCards.h"
#include "GlobalMove.h"
#include "Move.h"
#include "Player.h"


short GameManager::maxAmountCard{ 0 };
short GameManager::maxAmountPlayer{ 0 };

void GameManager::setPlayers()
{
	GiverCards tempGiverCards{ generalDeck };
	for (int i{ 0 }; i < maxAmountPlayer; i++)
	{
		players.push_back(Player::setPlayer(GameHelper::setNamePlayer(players, i + 1)));
		tempGiverCards.firstDistributionCardsPlayers(players[i]);
	}
}

GameManager::GameManager(const short _maxAmountCard, const short _maxAmountPlayer, std::unordered_map<TYPES_CARD, std::string>&& _baseTypesCards) :
	generalDeck{ Deck::creatDeckElement(std::move(_baseTypesCards)) }
{
	GameManager::maxAmountCard = _maxAmountCard;
	GameManager::maxAmountPlayer = _maxAmountPlayer;

	setPlayers();
	globalMove = new GlobalMove{ players, generalDeck };
}

const short GameManager::getMaxAmountCard()
{
	return maxAmountCard;
}

const short GameManager::getMaxAmountPlayer()
{
	return maxAmountPlayer;
}

void GameManager::startGame()
{
	if (maxAmountPlayer >= 2)
		this->globalMove->makeMove();
	else
		std::cout << "Sorry, but the game can't start, the number of players is small (must be 2 or more)" << std::endl;
}