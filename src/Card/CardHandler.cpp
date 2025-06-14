#include "CardHandler.hpp"
#include <iostream>

CardHandler::CardHandler()
	: cards
	{
		Card(LoadTexture("./Assets/Cards/Red.png"), {White, Blue, Blue, Blue, Blue, Green, Green}, 2),
		Card(LoadTexture("./Assets/Cards/Green.png"), {Red, Red, Red}, 1),
		Card(LoadTexture("./Assets/Cards/Blue.png"), {Blue, Green, Green, Green, Red}, 1)
	}
{
	std::cout << "Card handler created" << std::endl;
}


CardHandler::~CardHandler()
{
	std::cout << "Card handler destroyed" << std::endl;
}

void CardHandler::InitializeCards()
{
	std::vector<Card*> tier1Cards;
	std::vector<Card*> tier2Cards;
	std::vector<Card*> tier3Cards;

	for (Card& card : cards)
	{
		switch (card.tier)
		{
			case 1:
				tier1Cards.push_back(&card);
				break;
			case 2:
				tier2Cards.push_back(&card);
				break;
			case 3:
				tier3Cards.push_back(&card);
				break;
			default:
				tier1Cards.push_back(&card);
				break;
		}
	}

	int cardsXOffset = 200;

	for (Card* card : tier3Cards)
	{
		card->position = {(float)cardsXOffset, 20};
		cardsXOffset += 200;
		card->UpdateRect();
	}

	cardsXOffset = 200;

	for (Card* card : tier2Cards)
	{
		card->position = {(float)cardsXOffset, 250};
		cardsXOffset += 200;
		card->UpdateRect();
	}

	cardsXOffset = 200;

	for (Card* card : tier1Cards)
	{
		card->position = {(float)cardsXOffset, 480};
		cardsXOffset += 200;
		card->UpdateRect();
	}
}

void CardHandler::DrawCards()
{
	for (Card& card : cards)
	{
		card.Draw();
	}
}