#include "raylib.h"
#include "Token.hpp"
#include <vector>

#ifndef CARD
#define CARD

class Card
{
	private:
		Texture2D texture;
		Vector2 position;
		std::vector<Token> cost;

	public:
		Card(const Texture2D& texture, std::vector<Token> cost, Vector2 position);

		~Card();

		void Draw();
};

#endif