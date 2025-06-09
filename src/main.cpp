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
	std::vector<Card> cards = 
	{
		Card("Ring", {100, 100}),
		Card("Neclace", {250, 100}),
		Card("Earring", {400, 100}),
		Card("Ultimate Cat Card", {550, 100})
	};

	InitWindow(800, 600, "Splendor");

	while (!WindowShouldClose())
	{
		// logic here

		Draw(cards);
	}

	CloseWindow();

	return 0;
}