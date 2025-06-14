#include "raylib.h"
#include "Card.hpp"
#include <vector>

#ifndef CARDHANDLER_HPP
#define CARDHANDLER_HPP

class CardHandler
{
	public:
		std::vector<Card> cards;

		CardHandler();
		~CardHandler();

		void InitializeCards();
		void DrawCards();

};

#endif