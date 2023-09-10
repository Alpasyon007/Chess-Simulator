#pragma once
#include "../Piece.h"

class Rook : public Piece {
private:
public:
	Rook(Color color);
	~Rook();

	bool IsValidMove(int rank, int file, int toRank, int toFile) override;
};