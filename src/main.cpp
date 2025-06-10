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
	int screenWidth = GetMonitorWidth(0);
	int screenHeight = GetMonitorHeight(0);

	InitWindow(screenWidth, screenHeight, "Splendor");

	ToggleFullscreen();

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