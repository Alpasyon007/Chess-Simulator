#pragma once
#include "../Piece.h"

class King : public Piece {
private:
public:
	King(Color color);
	~King();

	bool IsValidMove(int rank, int file, int toRank, int toFile) override;
};