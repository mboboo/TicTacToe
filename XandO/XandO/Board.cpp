#include "Board.h"

Board::Board()
{
	m_board = {
		Sign::sign::None, Sign::sign::None, Sign::sign::None,
		Sign::sign::None, Sign::sign::None, Sign::sign::None,
		Sign::sign::None, Sign::sign::None, Sign::sign::None
	};
}

void Board::SetSign(const uint16_t& position, const Sign::sign& sign)
{
	if (GetSign(position) == Sign::sign::None)
		m_board[position] = sign;
	else
		return;
}

uint16_t Board::CheckGameState()
{
	if (CheckWin(Sign::sign::O))
		return 0;
	else if (CheckWin(Sign::sign::X))
		return 1;
	else if (CheckTie())
		return 2;
	else return 3;
}

void Board::ClearBoard()
{
	m_board.fill(Sign::sign::None);
}

std::vector<uint16_t> Board::GetEmptyCells() const
{
	std::vector<uint16_t> emptyCells;
	for (size_t position = 0; position < m_board.size(); ++position) {
		if (m_board[position] == Sign::sign::None)
			emptyCells.emplace_back(position);
	}
	return emptyCells;
}

bool Board::CheckTie()
{
	return std::find(m_board.begin(),m_board.end(), Sign::sign::None) == m_board.end();
}

bool Board::CheckWin(Sign::sign sign)
{
	/*bool line = true;
	for (auto index = 0; index < m_board.size(); index++)
	{
		if (m_board[index] != sign)
			line = false;
		if (index % 3 == 0)
			if (line == true)
				return true;
	}*/
	if (
		m_board[0] == sign && m_board[1] == sign && m_board[2] == sign ||
		m_board[3] == sign && m_board[4] == sign && m_board[5] == sign ||
		m_board[6] == sign && m_board[7] == sign && m_board[8] == sign ||

		m_board[0] == sign && m_board[3] == sign && m_board[6] == sign ||
		m_board[1] == sign && m_board[4] == sign && m_board[7] == sign ||
		m_board[2] == sign && m_board[5] == sign && m_board[8] == sign ||

		m_board[0] == sign && m_board[4] == sign && m_board[8] == sign ||
		m_board[2] == sign && m_board[4] == sign && m_board[6] == sign
		) return true;
	return false;
}

Sign::sign Board::GetSign(const uint16_t& position) const
{
	return m_board[position];
}

Sign::sign& Board::operator[](const uint16_t& position)
{
	if (position < 0 || position > 8)
		throw "Board index out of bound.";

	return m_board[position];
}

void Board::PrintBoard()
{
	for (auto index = 0; index < m_board.size(); ++index)
	{
		if (index % 3 == 0)
			std::cout << "\n";
		if (m_board[index] == Sign::sign::X)
			std::cout << "X ";
		else if (m_board[index] == Sign::sign::O)
			std::cout << "O ";
		else std::cout << "_ ";
    }
	std::cout << "\n";
}
