#include "Piece.h"

Piece::Piece(Color color, Type type) : m_color(color), m_type(type) {};

Piece::~Piece() {};

bool Piece::Move() { return false; }

char ToString(Color color) {
	const std::map<Color, char> colorMap = {
		{WHITE, 'W'},
		{BLACK, 'B'}};

	for( auto pair : colorMap ) {
		if(pair.first == color ) {
			return pair.second;
		}
	}

	return '0';
};

char ToString(Type type) {
	const std::map<Type, char> typeMap = {
		{PAWN,		'P'},
		{KNIGHT,	'N'},
		{BISHOP,	'B'},
		{ROOK,		'R'},
		{QUEEN,		'Q'},
		{KING,		'K'}};

	for( auto pair : typeMap ) {
		if(pair.first == type ) {
			return pair.second;
		}
	}

	return '0';
};

std::ostream& operator<<(std::ostream& out, const Piece& piece) {
	return (out << ToString(piece.GetColor()) << ToString(piece.GetType()));
}
