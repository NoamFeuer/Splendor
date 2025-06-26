#include "raylib.h"
#include "Token.hpp"
#include <vector>

#ifndef BOARD_HPP
#define BOARD_HPP

class Board
{
	private:
		std::vector<Token> tokens;
	
	public:
		Board();
		~Board();

		void Draw();
};

#endif