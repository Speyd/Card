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



int main()
{
	Card* card = new Clubs{ SUITS::DIAMONDS, TYPES_CARD::ACE, "Ace"};

	std::cout << card->getSuitName() << std::endl;
	std::cout << card->getTypeName() << std::endl;
	std::cout << card->getTrump() << std::endl;
	std::cout << card->getCondition() << std::endl;



	return 0;
}