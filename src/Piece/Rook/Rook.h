#pragma once
#include "../Piece.h"

class Rook : public Piece {
public:
	Rook(Color color);
	~Rook();

	bool IsValidMove(int rank, int file, int toRank, int toFile) override;
	bool IsValidCapture(int rank, int file, int toRank, int toFile) override;
	bool GetHasMoved();
	void SetHasMoved(bool moved);
private:
	bool m_hasMoved;
};