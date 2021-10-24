#include "Piece.h"

Piece::Piece(Color color, Type type) : m_color(color), m_type(type) {};

Piece::~Piece() {};

bool Piece::Move() { return false; }

std::string ColorToText(Color color) {
	switch (color) {
		case WHITE:
			return "W";
			break;
		case BLACK:
			return "B";
			break;
	}
	return "INVALID";
};

std::string TypeToText(Type type) {
	switch (type) {
		case PAWN:
			return "P";
			break;
		case KNIGHT:
			return "K";
			break;
		case BISHOP:
			return "B";
			break;
		case ROOK:
			return "R";
			break;
		case QUEEN:
			return "Q";
			break;
		case KING:
			return "K";
			break;
	}
	return "INVALID";
};

std::ostream& operator<<(std::ostream& out, const Piece& piece) {
	return (out << ColorToText(piece.GetColor()) << TypeToText(piece.GetType()));
}
