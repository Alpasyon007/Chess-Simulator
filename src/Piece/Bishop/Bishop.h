#pragma once
#include "../Piece.h"

class Bishop : public Piece {
	private:
	public:
		Bishop(Color color);
		~Bishop();

		bool Move() override;
};