#include "raylib.h"
#include "Card.hpp"
#include "Token.hpp"
#include <vector>

void Draw(std::vector<Card> &cards)
{
	BeginDrawing();
	ClearBackground(BLACK);

	for (Card& card : cards)
	{
		card.Draw();
	}

	EndDrawing();
}

int main()
{
	InitWindow(800, 600, "Splendor");

	Texture2D cardTexture = LoadTexture("./Assets/Card1.png");
	std::vector<Card> cards = 
	{
		Card(cardTexture, {White, Blue, Blue, Blue, Blue, Green, Green}, {100, 100})
	};

	while (!WindowShouldClose())
	{
		// logic

		Draw(cards);
	}

	UnloadTexture(cardTexture);
	CloseWindow();

	return 0;
}