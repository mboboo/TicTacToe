#pragma once
#include <array>
#include <vector>
#include <iostream>
#include <algorithm>

#include "Sign.h"
#include "GameState.h"

class Board
{

public:
	Board();
	std::array<Sign::sign, 9> GetBoard() const;
	GameState::gameState CheckGameState();
	void ClearBoard();
	std::vector<uint16_t> GetEmptyCells() const ;
	Sign::sign& operator[](uint16_t position);
	void PrintBoard();
	bool CheckTie();
	bool CheckWin(const Sign::sign& sign);

private:
	Sign::sign GetSign(uint16_t position) const;

private:
	std::array<Sign::sign, 9> m_board;
};

