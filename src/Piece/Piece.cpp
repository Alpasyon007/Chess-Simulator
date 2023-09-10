#include "Piece.h"

Piece::Piece(Color color, Type type) : m_color(color), m_type(type) {}

Piece::~Piece() {}

bool Piece::IsValidMove(int rank, int file, int toRank, int toFile) {
	// Check if the move is within the bounds of the chessboard (usually 8x8).
	if(rank < 0 || rank >= 7 || file < 0 || file >= 7 || toRank < 0 || toRank >= 7 || toFile < 0 || toFile >= 7) { return false; }

	return true;
}

std::string ToString(Color color) {
	const std::map<Color, std::string> colorMap = {{WHITE, "White"}, {BLACK, "Black"}};

	for(auto pair : colorMap) {
		if(pair.first == color) { return pair.second; }
	}

	return nullptr;
}

std::string ToString(Type type) {
	const std::map<Type, std::string> typeMap = {{PAWN, "Pawn"}, {KNIGHT, "Knight"}, {BISHOP, "Bishop"}, {ROOK, "Rook"}, {QUEEN, "Queen"}, {KING, "King"}};

	for(auto pair : typeMap) {
		if(pair.first == type) { return pair.second; }
	}

	return nullptr;
}

std::ostream& operator<<(std::ostream& out, const Piece& piece) {
	const std::map<std::pair<Color, Type>, std::string> pieceMap = {
		{{WHITE, PAWN}, "♙"}, {{WHITE, KNIGHT}, "♘"}, {{WHITE, BISHOP}, "♗"}, {{WHITE, ROOK}, "♖"}, {{WHITE, QUEEN}, "♕"}, {{WHITE, KING}, "♔"},
		{{BLACK, PAWN}, "♟︎"}, {{BLACK, KNIGHT}, "♞"}, {{BLACK, BISHOP}, "♝"}, {{BLACK, ROOK}, "♜"}, {{BLACK, QUEEN}, "♛"}, {{BLACK, KING}, "♚"}};

	return (out << pieceMap.find({piece.GetColor(), piece.GetType()})->second);
}
