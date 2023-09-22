#include "PiecePosition.h"
#include <iostream>

PiecePosition::PiecePosition(int rank, int file) : m_rank(rank), m_file(file) {}

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

bool		   operator==(const PiecePosition& lhs, const PiecePosition& rhs) { return (lhs.m_rank == rhs.m_file && lhs.m_file == rhs.m_file); }

std::wostream& operator<<(std::wostream& out, const PiecePosition& piecePosition) {
	// Convert file (column) index to wide character
	wchar_t fileChar(static_cast<wchar_t>(L'a' + piecePosition.m_file));

	// Convert rank (row) index to wide character
	wchar_t rankChar(static_cast<wchar_t>(L'8' - piecePosition.m_rank));

	// Output the wide characters to the wcout stream
	out << fileChar << rankChar;

	return out;
}