#include "Rook.h"

Rook::Rook(Color color) : Piece(color, ROOK), m_hasMoved(false) {}

Rook::~Rook() {}

bool Rook::IsValidMove(int rank, int file, int toRank, int toFile) {
	// A rook can move either vertically or horizontally, but not diagonally.
	if((rank == toRank && file != toFile) || (rank != toRank && file == toFile)) { return true && Piece::IsValidMove(rank, file, toRank, toFile); }

	// If none of the above conditions are met, the move is invalid.
	return false;
}

bool Rook::IsValidCapture(int rank, int file, int toRank, int toFile) {
	// A rook can move either vertically or horizontally, but not diagonally.
	if((rank == toRank && file != toFile) || (rank != toRank && file == toFile)) { return true && Piece::IsValidMove(rank, file, toRank, toFile); }

	// If none of the above conditions are met, the move is invalid.
	return false;
}

bool Rook::GetHasMoved() { return m_hasMoved; }

void Rook::SetHasMoved(bool moved) { m_hasMoved = moved; }