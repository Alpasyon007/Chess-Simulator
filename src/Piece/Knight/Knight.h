#pragma once
#include "../Piece.h"

class Knight : public Piece {
private:
public:
	Knight(Color color);
	~Knight();

	bool IsValidMove(int rank, int file, int toRank, int toFile) override;
};