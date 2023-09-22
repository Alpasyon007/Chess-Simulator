#pragma once
#include "../Piece.h"

class Queen : public Piece {
private:
public:
	Queen(Color color);
	~Queen();

	bool IsValidMove(int rank, int file, int toRank, int toFile) override;
	bool IsValidCapture(int rank, int file, int toRank, int toFile) override;
};