#pragma once
#include "../Piece.h"

class Rook : public Piece {
	private:
	public:
		Rook(Color color);
		~Rook();

		bool Move() override;
};