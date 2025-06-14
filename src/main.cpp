#include "raylib.h"
#include "Card/Card.hpp"
#include "Token.hpp"
#include "Player.hpp"
#include "Card/CardHandler.hpp"
#include <vector>

void Draw(CardHandler cardHandler, Texture2D tier1Card, Texture2D tier2Card, Texture2D tier3Card)
{
	BeginDrawing();
	ClearBackground(BLACK);

	DrawTextureV(tier3Card, {20, 20}, WHITE);
	DrawTextureV(tier2Card, {20, 250}, WHITE);
	DrawTextureV(tier1Card, {20, 480}, WHITE);

	cardHandler.DrawCards();

	EndDrawing();
}

int main()
{
	int screenWidth = GetMonitorWidth(0);
	int screenHeight = GetMonitorHeight(0);

	InitWindow(screenWidth, screenHeight, "Splendor ©");
	ToggleFullscreen();

	CardHandler cardHandler = *(new CardHandler());
	cardHandler.InitializeCards();

	Texture2D tier1Card = LoadTexture("./Assets/Cards/Tier1Card.png");
	Texture2D tier2Card = LoadTexture("./Assets/Cards/Tier2Card.png");
	Texture2D tier3Card = LoadTexture("./Assets/Cards/Tier3Card.png");

	Player player({Red, Red, Red});

	while (!WindowShouldClose())
	{
		player.Update(cardHandler.cards);

		Draw(cardHandler, tier1Card, tier2Card, tier3Card);
	}

	UnloadTexture(tier1Card);
	UnloadTexture(tier2Card);
	UnloadTexture(tier3Card);
	CloseWindow();

	return 0;
}
