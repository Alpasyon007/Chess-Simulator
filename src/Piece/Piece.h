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
		Piece(Color Color, Type type);
		virtual ~Piece();
	public:
		virtual bool Move();
		virtual Color GetColor() const { return m_color; }
		virtual Type GetType() const { return m_type; }

		friend std::ostream& operator<<(std::ostream& out, const Piece& piece);
		friend std::string ColorToText(Color color);
		friend std::string TypeToText(Type type);
};