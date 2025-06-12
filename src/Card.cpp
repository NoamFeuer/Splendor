#include "Card.hpp"
#include "raylib.h"
#include <iostream>

Card::Card(const Texture2D& cardTexture, std::vector<Token> cardCost, int cardTier)
	: texture(cardTexture), cost(cardCost), tier(cardTier)
{
	std::cout << "Card created" << std::endl;
}

Card::~Card()
{
	std::cout << "Card destroyed" << std::endl;
}

void Card::Draw(Vector2 position)
{
	DrawTextureV(texture, position, WHITE);
}