#pragma once

#include <iostream>
#include <map>
#include <string>

enum Type {
	PAWN   = 0,
	KNIGHT = 1,
	BISHOP = 2,
	ROOK   = 3,
	QUEEN  = 4,
	KING   = 5
};

enum Color {
	WHITE = 0,
	BLACK = 1
};

class Piece {
protected:
	Type  m_type;
	Color m_color;
protected:
	Piece(Color Color, Type type);
	virtual ~Piece();
public:
	virtual bool		 IsValidMove(int rank, int file, int toRank, int toFile);

	virtual Color		 GetColor() const { return m_color; }

	virtual Type		 GetType() const { return m_type; }

	friend std::ostream& operator<<(std::ostream& out, const Piece& piece);

	friend std::string	 ToString(Type type);
	friend std::string	 ToString(Color color);
};