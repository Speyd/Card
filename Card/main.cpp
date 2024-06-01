#include <iostream>
#include <Windows.h>
#include "GameManager.h"

using namespace std::string_literals;

short inputAmountPlayer()
{
	system("cls");
	short amountPlayer{ 0 };

	std::cout << "Enter the number of players who will take part in the game: ";
	std::cin >> amountPlayer;

	return amountPlayer >= 0 ? amountPlayer : amountPlayer * -1;
}

short inputAmountCard()
{
	system("cls");
	short amountCard{ 0 };

	std::cout << "Enter the number of cards in the game: ";
	std::cin >> amountCard;

	return amountCard > 0 ? amountCard : 1;
}

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	setlocale(LC_ALL, ".UTF8");

	GameManager* game = new GameManager
	{
		inputAmountPlayer(),
		inputAmountCard(),
		{ 
			{ TYPES_CARD::SIX, "Six"},
			{ TYPES_CARD::SEVEN, "Seven"},
			{ TYPES_CARD::EIGHT, "Eight"},
			{ TYPES_CARD::NINE, "Nine"},
			{ TYPES_CARD::TEN, "Ten"},
			{ TYPES_CARD::JACK, "Jck"},
			{ TYPES_CARD::QUEEN, "Queen"},
			{ TYPES_CARD::KING, "Kig"},
			{ TYPES_CARD::ACE, "Ace"},
		}
	};
	
	game->startGame();


	delete game;

	return 0;
}