#include "Bishop.h"
#include <iostream>

Bishop::Bishop(Color color) : Piece(color, BISHOP) {}

Bishop::~Bishop() {}

bool Bishop::IsValidMove(int rank, int file, int toRank, int toFile) {
	// Check if the starting and ending positions are on the same diagonal.
	if(abs(rank - toRank) == abs(file - toFile)) {
		// The move is diagonal, which is valid for a Bishop.
		return true && Piece::IsValidMove(rank, file, toRank, toFile);
	}

	// If not on the same diagonal, the move is invalid for a Bishop.
	return false;
}

bool Bishop::IsValidCapture(int rank, int file, int toRank, int toFile) {
	// Check if the starting and ending positions are on the same diagonal.
	if(abs(rank - toRank) == abs(file - toFile)) {
		// The move is diagonal, which is valid for a Bishop.
		return true && Piece::IsValidMove(rank, file, toRank, toFile);
	}

	// If not on the same diagonal, the move is invalid for a Bishop.
	return false;
}