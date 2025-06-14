#include "Card.hpp"
#include "raylib.h"
#include <iostream>

Card::Card(const Texture2D& cardTexture, std::vector<Token> cardCost, const int cardTier)
	: texture(cardTexture), cost(cardCost), tier(cardTier)
{
	std::cout << "Card created" << std::endl;
}

Card::~Card()
{
	std::cout << "Card destroyed" << std::endl;
}

void Card::Draw()
{
	DrawTextureV(texture, position, WHITE);
}

void Card::UpdateRect()
{
	rect = {position.x, position.y, (float)texture.width, (float)texture.height};
}