#pragma once
#include "../Piece.h"

class Bishop : public Piece {
private:
public:
	Bishop(Color color);
	~Bishop();

	bool IsValidMove(int rank, int file, int toRank, int toFile) override;
};