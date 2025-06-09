#include <string>
#include "raylib.h"

#ifndef CARD
#define CARD

class Card
{
	private:
		Texture2D texture;
		Vector2 position;

	public:
		Card(const Texture2D texture, Vector2 position);
		~Card();
		void Draw();
};

#endif