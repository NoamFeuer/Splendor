#include "raylib.h"
#include "Card.hpp"
#include <vector>

void Draw(std::vector<Card> cards)
{
	BeginDrawing();
	ClearBackground(RAYWHITE);

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
		Card(cardTexture, {100, 100}),
		Card(cardTexture, {400, 100})
	};

	while (!WindowShouldClose())
	{
		// logic here

		Draw(cards);
	}

	UnloadTexture(cardTexture);
	CloseWindow();

	return 0;
}