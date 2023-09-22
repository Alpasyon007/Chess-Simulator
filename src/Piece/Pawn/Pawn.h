#pragma once
#include "../Piece.h"

class Pawn : public Piece {
private:
public:
	Pawn(Color color);
	~Pawn();

	bool IsValidMove(int rank, int file, int toRank, int toFile) override;
	bool IsValidCapture(int rank, int file, int toRank, int toFile) override;
};