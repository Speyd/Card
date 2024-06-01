#include "GlobalMove.h"
#include "GameManager.h"


Player* GlobalMove::definitionDefendPlayer(std::unordered_map<Card*, Player*>& tempArray)
{
	Card* minCard{ nullptr };
	auto randomCardIt = tempArray.begin();
	std::advance(randomCardIt, rand() % ((tempArray.size() - 1) - 0 + 1) + 0);

	for (auto card : tempArray)
	{
		if (minCard == nullptr)
			minCard = card.first;
		else if (minCard != nullptr && card.first != nullptr && card.first->getTypeCard() < minCard->getTypeCard())
			minCard = card.first;
	}



	if (minCard != nullptr)
		this->attackPlayers.push_back(tempArray[minCard]);
	else
		this->attackPlayers.push_back(randomCardIt->second);


	auto minCardIt = tempArray.find(minCard);
	if (minCardIt != tempArray.end()) {
		++minCardIt;
		if (minCardIt != tempArray.end()) {
			return minCardIt->second;
		}
		else {
			return tempArray.begin()->second;
		}
	}

	return minCard != nullptr ? tempArray[minCard] : randomCardIt->second;
}

DEFINITIONS_MOVE GlobalMove::definitionMove()
{
	if (Move::getAmountAttackCard() >= GameManager::getMaxAmountCard() ||
		this->defendPlayer->getSizeDeck() == 0)
	{
		return DEFINITIONS_MOVE::NEXT_MOVE;
	}

	if (GameHelper::getAmountPassAttaker(attackPlayers) == attackPlayers.size())
		return DEFINITIONS_MOVE::NEXT_MOVE;

	return DEFINITIONS_MOVE::CONTINUE_MOVE;
}

void GlobalMove::definitionAttackingPlayers(std::vector<Player*>& players)
{
	Array<Player*>* tempArray = new Array<Player*>;
	tempArray->addArrayElement(this->attackPlayers);

	for (int i{ 0 }; i < players.size(); i++)
	{
		if (players[i] != this->defendPlayer && tempArray->findElementBool(players[i]) == false)
			this->attackPlayers.push_back(players[i]);
	}
}

void GlobalMove::changePlayerRole(const short startAmountDefenderCard)
{
	Player* tempBeginAttacker = *(this->attackPlayers).begin();
	this->attackPlayers.erase(this->attackPlayers.begin());

	if (this->defendPlayer->getSizeDeck() <= startAmountDefenderCard)
		this->attackPlayers.insert(this->attackPlayers.begin(), this->defendPlayer);
	else
		this->attackPlayers.push_back(this->defendPlayer);

	this->defendPlayer = tempBeginAttacker;

	Move::clearAllAttackCardPlayer();
	Move::clearAllDefendCardPlayer();
}

void GlobalMove::definitionTops()
{
	Array<Player*> tempPlayer;
	tempPlayer.addArrayElement(attackPlayers);
	tempPlayer.addElement(defendPlayer);

	int size = tempPlayer.getSize();
	for (int j{ 0 }; j < 2; j++)				//TODO: это сделано для того, что-бы лишний раз не проходить цикл метода "makeMove"
	{
		for (int i{ 0 }; i < size; i++)
		{
			if (tempPlayer[i]->getSizeDeck() == 0 && topWinnerPlayers->findElementBool(tempPlayer[i]) == false)
				this->topWinnerPlayers->addUniqueElement(tempPlayer[i]);
			else if (this->topWinnerPlayers->getSize() + 1 == GameManager::getMaxAmountPlayer() && tempPlayer[i]->getSizeDeck() > 0)
				this->topWinnerPlayers->addUniqueElement(tempPlayer[i]);
		}
	}
}

void GlobalMove::actionsAfterMove(const short startAmountDefenderCard)
{
	if (Deck::getDeckElement()->getSize() == 0)
		definitionTops();

	this->giverCards->distributingCardsPlayers(this->attackPlayers, this->defendPlayer);

	changePlayerRole(startAmountDefenderCard);
}

GlobalMove::GlobalMove(std::vector<Player*>& players, Deck* generalDeck) :
	giverCards{ new GiverCards{ generalDeck } }
{
	std::unordered_map<Card*, Player*>* tempArray = new std::unordered_map<Card*, Player*>;
	for (int i{ 0 }; i < players.size(); i++)
		(*tempArray)[GameHelper::checkMinSuitCard(players[i])] = players[i];

	defendPlayer = definitionDefendPlayer(*tempArray);

	definitionAttackingPlayers(players);

}

bool GlobalMove::showDeckWinnerPlayer(Player* choicePlayer)
{
	std::stringstream text;
	text << choicePlayer->getName() << "'s cards:" << std::endl;

	if (choicePlayer != nullptr)
	{
		int size = choicePlayer->getSizeDeck();

		if (size == 0)
			text << "No cards" << std::endl;
		else
		{
			for (int i{ 0 }; i < size; i++)
				text << i + 1 << ". " << choicePlayer->getCardName(i) << std::endl;
		}
	}

	Menu<bool> menu
	{
		"Top Winner\n" + text.str(),
		"Do you want to know another player's deck?",
		{{"Yes", std::make_shared<bool>(true)}, {"No" ,std::make_shared<bool>(false)}},
		true
	};

	return menu[menu.setChoicePlayer()];
}

void GlobalMove::showTopWinnerPlayer()
{
	Player* choicePlayer{ nullptr };
	do
	{
		Menu<Player*> menu
		{
			"Top Winner",
			"Which player do you want to select to check his information?",
			GameHelper::getItemMenuPlayer(this->topWinnerPlayers, "End game"),
			true
		};

		choicePlayer = menu[menu.setChoicePlayer()];
		 
	} while (showDeckWinnerPlayer(choicePlayer) != false);
}

void GlobalMove::makeMove()
{
	do {

		int startAmountDefenderCard{ this->defendPlayer->getSizeDeck() };
		do
		{
			for (auto& attacker : this->attackPlayers)
			{
				Move::MoveInitialization(attacker, this->defendPlayer, startAmountDefenderCard);
			}
		} while (definitionMove() != DEFINITIONS_MOVE::NEXT_MOVE);

		actionsAfterMove(startAmountDefenderCard);

	} while (topWinnerPlayers->getSize() < GameManager::getMaxAmountPlayer());

	showTopWinnerPlayer();

}