#include "Piece.h"

Piece::Piece(Color color, Type type) : m_color(color), m_type(type) {}

Piece::~Piece() {}

bool Piece::IsValidMove(int rank, int file, int toRank, int toFile) {
	// Check if the move is within the bounds of the chessboard (usually 8x8).
	return (toRank >= 0 && toRank < 8 && toFile >= 0 && toFile < 8);
}

bool Piece::IsValidCapture(int rank, int file, int toRank, int toFile) {
	// Check if the move is within the bounds of the chessboard (usually 8x8).
	return (toRank >= 0 && toRank < 8 && toFile >= 0 && toFile < 8);
}

std::wstring ToString(Color color) {
	const std::map<Color, std::wstring> colorMap = {{WHITE, L"White"}, {BLACK, L"Black"}};

	for(auto pair : colorMap) {
		if(pair.first == color) { return pair.second; }
	}

	return nullptr;
}

std::wstring ToString(Type type) {
	const std::map<Type, std::wstring> typeMap = {{PAWN, L"Pawn"}, {KNIGHT, L"Knight"}, {BISHOP, L"Bishop"},
												  {ROOK, L"Rook"}, {QUEEN, L"Queen"},	{KING, L"King"}};

	for(auto pair : typeMap) {
		if(pair.first == type) { return pair.second; }
	}

	return nullptr;
}

std::wostream& operator<<(std::wostream& out, const Piece& piece) {
	const std::map<std::pair<Color, Type>, std::wstring> pieceMap = {
		{{WHITE, PAWN}, L"\u2659"},	  // ♙
		{{WHITE, KNIGHT}, L"\u2658"}, // ♘
		{{WHITE, BISHOP}, L"\u2657"}, // ♗
		{{WHITE, ROOK}, L"\u2656"},	  // ♖
		{{WHITE, QUEEN}, L"\u2655"},  // ♕
		{{WHITE, KING}, L"\u2654"},	  // ♔
		{{BLACK, PAWN}, L"\u265F"},	  // ♟
		{{BLACK, KNIGHT}, L"\u265E"}, // ♞
		{{BLACK, BISHOP}, L"\u265D"}, // ♝
		{{BLACK, ROOK}, L"\u265C"},	  // ♜
		{{BLACK, QUEEN}, L"\u265B"},  // ♛
		{{BLACK, KING}, L"\u265A"}	  // ♚
	};

	return (out << pieceMap.find({piece.GetColor(), piece.GetType()})->second);
}