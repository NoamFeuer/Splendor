#include "raylib.h"
#include "Card.hpp"
#include "Token.hpp"
#include <vector>

void Draw(std::vector<Card> &cards, Texture2D tier1Card, Texture2D tier2Card, Texture2D tier3Card)
{
	BeginDrawing();
	ClearBackground(BLACK);

	std::vector<Card> tier1Cards;
	std::vector<Card> tier2Cards;
	std::vector<Card> tier3Cards; 

	for (Card& card : cards)
	{
		switch (card.tier)
		{
			case 1:
				tier1Cards.push_back(card);
				break;
			case 2:
				tier2Cards.push_back(card);
				break;
			case 3:
				tier3Cards.push_back(card);
				break;
			default:
				tier1Cards.push_back(card);
				break;
		}
	}

	int cardsXOffset = 200;

	for (Card& card : tier3Cards)
	{
		card.Draw({(float)cardsXOffset, 20});
		cardsXOffset += 200;
	}

	cardsXOffset = 200;

	for (Card& card : tier2Cards)
	{
		card.Draw({(float)cardsXOffset, 250});
		cardsXOffset += 200;
	}

	cardsXOffset = 200;

	for (Card& card : tier1Cards)
	{
		card.Draw({(float)cardsXOffset, 480});
		cardsXOffset += 200;
	}

	DrawTextureV(tier3Card, {20, 20}, WHITE);
	DrawTextureV(tier2Card, {20, 250}, WHITE);
	DrawTextureV(tier1Card, {20, 480}, WHITE);

	EndDrawing();
}

int main()
{
	int screenWidth = GetMonitorWidth(0);
	int screenHeight = GetMonitorHeight(0);


	InitWindow(screenWidth, screenHeight, "Splendor ©");

	ToggleFullscreen();

	Texture2D cardTextureRed = LoadTexture("./Assets/Cards/Red.png");
	Texture2D cardTextureGreen = LoadTexture("./Assets/Cards/Green.png");
	Texture2D cardTextureBlue = LoadTexture("./Assets/Cards/Blue.png");
 
	Texture2D tier1Card = LoadTexture("./Assets/Cards/Tier1Card.png");
	Texture2D tier2Card = LoadTexture("./Assets/Cards/Tier2Card.png");
	Texture2D tier3Card = LoadTexture("./Assets/Cards/Tier3Card.png");

	std::vector<Card> cards = 
	{
		Card(cardTextureRed, {White, Blue, Blue, Blue, Blue, Green, Green}, 2),
		Card(cardTextureGreen, {Red, Red, Red}, 1),
		Card(cardTextureBlue, {Blue, Green, Green, Green, Red}, 1)
	};
	

	while (!WindowShouldClose())
	{
		Draw(cards, tier1Card, tier2Card, tier3Card);
	}

	UnloadTexture(cardTextureRed);
	UnloadTexture(cardTextureGreen);
	UnloadTexture(cardTextureBlue);
	UnloadTexture(tier1Card);
	UnloadTexture(tier2Card);
	UnloadTexture(tier3Card);
	CloseWindow();

	return 0;
}