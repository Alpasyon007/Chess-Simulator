#pragma once

enum Type {
	PAWN = 0,
	KNIGHT,
	KING,
	BISHOP,
	ROOK,
	QUEEN,
	KING
};

enum Color {
	WHITE = 0,
	BLACK
};

class Piece {
	protected:
		Type m_type;
		Color m_color;
	protected:
		Piece(Color Color);
		~Piece();
	public:
		virtual bool Move() = 0;
};