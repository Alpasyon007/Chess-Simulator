#include "Piece.h"

Piece::Piece(Color color) : m_color(color) {};

Piece::~Piece() {};

bool Piece::Move() { return false; }

std::ostream& operator<<(std::ostream& out, const Piece& piece) {
	if(piece.GetColor() == WHITE) {
		return (out << "WHITE");
	}

	if(piece.GetColor() == BLACK) {
		return (out << "BLACK");
	}
}