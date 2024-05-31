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
#include "ChoicingElement.h"
#include "Move.h"
#include "GameManager.h"



int main()
{
	GameManager game
	{
		6,
		2,
		{ { TYPES_CARD::SIX, "Six"} }
	};
	
	game.startGame();

	return 0;
}