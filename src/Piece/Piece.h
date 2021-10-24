#pragma once

#include <iostream>

enum Type {
	PAWN = 0,
	KNIGHT,
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
		virtual ~Piece();
	public:
		virtual bool Move();
		virtual Color GetColor() const { return m_color; }

		friend std::ostream& operator<<(std::ostream& out, const Piece& piece);
};