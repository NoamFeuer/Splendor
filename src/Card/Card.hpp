#include "raylib.h"
#include "../Token.hpp"
#include <vector>

#ifndef CARD_HPP
#define CARD_HPP

class Card
{
	private:
		const Texture2D texture;

	public:
		std::vector<Token> cost;
		Vector2 position;
		Rectangle rect;
		const int tier;

		Card(const Texture2D& texture, std::vector<Token> cost, const int tier);
		~Card();

		void Draw();
		void UpdateRect();
};

#endif