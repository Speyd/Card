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



int main()
{
	Array<Card*> array;
	for (int i{ 0 }; i < 3; i++)
	{
		Card* card( new Clubs{ SUITS::DIAMONDS, TYPES_CARD(TYPES_CARD::SIX + i), "six" + std::to_string(i) });
		array.addElement(&card);
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



	return 0;
}