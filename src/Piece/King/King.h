#pragma once
#include "../Piece.h"

class King : public Piece {
public:
	King(Color color);
	~King();

	bool IsValidMove(int rank, int file, int toRank, int toFile) override;
	bool IsValidCapture(int rank, int file, int toRank, int toFile) override;

	bool GetHasMoved();
	void SetHasMoved(bool hasMoved);
private:
	bool m_hasMoved;
};