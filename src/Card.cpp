#include "Card.hpp"
#include "raylib.h"
#include <iostream>

Card::Card(const Texture2D cardTexture, Vector2 cardPosition)
	: texture(cardTexture), position(cardPosition)
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