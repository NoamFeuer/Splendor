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

	Texture2D cardTextureRed = LoadTexture("./Assets/red.png");
	Texture2D cardTextureGreen = LoadTexture("./Assets/green.png");
	Texture2D cardTextureBlue = LoadTexture("./Assets/blue.png");
	std::vector<Card> cards = 
	{
		Card(cardTextureRed, {White, Blue, Blue, Blue, Blue, Green, Green}, {100, 100}),
		Card(cardTextureGreen, {Red, Red, Red}, {300, 100}),
		Card(cardTextureBlue, {Blue, Green, Green, Green, Red}, {500, 100})
	};
	

	while (!WindowShouldClose())
	{
		// logic

		Draw(cards);
	}

	UnloadTexture(cardTextureRed);
	UnloadTexture(cardTextureGreen);
	UnloadTexture(cardTextureBlue);
	CloseWindow();

	return 0;
}