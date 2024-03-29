#pragma once
#include <iostream>
#include <string>

#include "Sign.h"
#include "Board.h"
#include "IPlayer.h"

class Player: public IPlayer
{
public:
	Player() = default;
	std::string GetPlayerName() const;
	void SetPlayerName(const std::string& name);
	void SetSign(const Sign::sign& sign);
	Sign::sign GetSign() const;
private:
	Sign::sign m_sign;
	std::string m_playerName;
};

