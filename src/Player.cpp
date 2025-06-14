#include "Player.hpp"
#include <map>
#include <iostream>

Player::Player(std::vector<Token> playerMoney)
	: money(playerMoney)
{
	std::cout << "Player created" << std::endl;
}


std::map<Token, int> CountTokens(const std::vector<Token>& tokens)
{
    std::map<Token, int> counts;
    for (Token t : tokens)
    {
        counts[t]++;
    }
    return counts;
}

void Player::Update(std::vector<Card>& cards)
{
	for (Card& card : cards)
	{
		if (IsMouseButtonPressed(0) && CheckCollisionPointRec(GetMousePosition(), card.rect))
		{
			std::cout << "Card clicked" << std::endl;

			std::map<Token, int> playerTokenCount = CountTokens(money);
			std::map<Token, int> cardTokenCost   = CountTokens(card.cost);

			bool canAfford = true;

			for (auto& [tokenType, amountRequired] : cardTokenCost)
			{
				if (playerTokenCount[tokenType] < amountRequired)
				{
					canAfford = false;
					break;
				}
			}

			if (canAfford)
				std::cout << "You can buy the card" << std::endl;
			else
				std::cout << "Not enough tokens" << std::endl;
		}
	}
}

Player::~Player()
{
	std::cout << "Player destroyed" << std::endl;
}