#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <cassert>
#include "Card.h"
#include "Clubs.h"
#include "Diamonds.h"
#include "Hearts.h"
#include "Spades.h"
#include "Array.h"
#include "MenuCreatCard.h"
#include "Menu.h"
#include "Deck.h"
#include "Player.h"
#include "GiverCards.h"




int main()
{

	Deck* deck = Deck::creatDeckElement({ { TYPES_CARD::SIX, "Six"},  { TYPES_CARD::SEVEN, "Seven"},  { TYPES_CARD::EIGHT, "Eight"} });
	Player* player = Player::setPlayer("Player1");

	GiverCards giver{ deck };
	giver.firstDistributionCardsPlayers(player);


	std::cout << player->getName() << std::endl;
	for (int i{ 0 }; i < player->getSizeDeck(); i++)
	{
		std::cout << player->getCardName(i) << std::endl;
	}

	std::cout << std::endl << std::endl;

	deck->outDeck();
	Array<Card*> array;
	for (int i{ 0 }; i < 3; i++)
	{
		array.addElement(deck->getBeginCard());
		deck->deleteBeginCard();
	}

	for (int i{ 0 }; i < 3; i++)
	{
		std::cout << i + 1 << " Card: " << std::endl;
		std::cout << array[i]->getSuitName() << std::endl;
		std::cout << array[i]->getTypeName() << std::endl;
		std::cout << array[i]->getTypeCard() << std::endl;
		std::cout << array[i]->getTrump() << std::endl;
		std::cout << array[i]->getCondition() << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl;

	Menu<Card> menu{ "Choicer", "What card do you want to take?:", {{array[0]->getTypeName(), array[0]}, {array[1]->getTypeName(), array[1]}, {array[2]->getTypeName(), array[2]}} };

	Card* card = &menu[menu.setChoicePlayer()];

	std::cout << std::endl;
	std::cout << card->getSuitName() << std::endl;
	std::cout << card->getTypeName() << std::endl;
	std::cout << card->getTypeCard() << std::endl;
	std::cout << card->getTrump() << std::endl;
	std::cout << card->getCondition() << std::endl;
	std::cout << std::endl;


	return 0;
}