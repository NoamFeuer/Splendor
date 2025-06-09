#include "Card.hpp"
#include "raylib.h"
#include <iostream>

Card::Card(const std::string& cardName, Vector2 cardPosition)
	: name(cardName), position(cardPosition)
{
	std::cout << "Card created: " << name << std::endl;
}

Card::~Card()
{
	std::cout << "Card destroyed: " << name << std::endl;
}

void Card::Draw()
{
	DrawRectangle((int)position.x, (int)position.y, 100, 150, LIGHTGRAY);
	DrawText(name.c_str(), (int)position.x + 10, (int)position.y + 10, 20, BLACK);
}