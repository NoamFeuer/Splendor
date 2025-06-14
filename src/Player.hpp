#include "raylib.h"
#include "Token.hpp"
#include "Card/Card.hpp"
#include <vector>

#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player
{
	private:
		std::vector<Token> money;
		void Buy(Card card);

	public:
		Player(std::vector<Token> money);
		~Player();

		void Update(std::vector<Card> &cards);
};

#endif