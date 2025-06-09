#include <string>
#include "raylib.h"

#ifndef CARD
#define CARD

class Card
{
	private:
		std::string name;
		Vector2 position;

	public:
		Card(const std::string& cardName, Vector2 position);
		~Card();
		void Draw();
};

#endif