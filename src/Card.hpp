#include "raylib.h"
#include "Token.hpp"
#include <vector>

#ifndef CARD
#define CARD

class Card
{
	private:
		Texture2D texture;
		std::vector<Token> cost;

	public:
		Card(const Texture2D& texture, std::vector<Token> cost, int tier);
		~Card();

		void Draw(Vector2 position);

		int tier;
};

#endif