#include "Board.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

void Initialize(std::vector<Token>& boardTokens)
{
	std::srand(static_cast<unsigned>(std::time(nullptr)));

	for (int i = 0; i < 25; ++i)
	{
		int randomIndex = std::rand() % 8;
		Token randomToken = static_cast<Token>(randomIndex);
		boardTokens.push_back(randomToken);

		std::cout << randomToken << std::endl;
	}
}

Board::Board()
{
	std::cout << "Board created" << std::endl;

	Initialize(tokens);
}

Board::~Board()
{
	std::cout << "Board destroyed" << std::endl;
}