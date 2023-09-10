#include "PiecePosition.h"
#include <stdexcept>

PiecePosition::PiecePosition(const std::string& algebraicNotation) {
	if(algebraicNotation.length() != 2) { throw std::invalid_argument("Invalid algebraic notation. It must be exactly 2 characters long."); }

	char fileChar = algebraicNotation[0];
	char rankChar = algebraicNotation[1];

	// Check if the file character is within 'a' to 'h'
	if(fileChar < 'a' || fileChar > 'h') { throw std::invalid_argument("Invalid file character in algebraic notation."); }

	// Check if the rank character is within '1' to '8'
	if(rankChar < '1' || rankChar > '8') { throw std::invalid_argument("Invalid rank character in algebraic notation."); }

	// Convert file character to file (column) index
	m_file = fileChar - 'a';

	// Convert rank character to rank (row) index
	m_rank = '8' - rankChar;
}

PiecePosition::PiecePosition(const char* algebraicNotation) : PiecePosition(std::string(algebraicNotation)) {}