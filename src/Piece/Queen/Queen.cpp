#include "Queen.h"

Queen::Queen(Color color) : Piece(color, QUEEN) {}

Queen::~Queen() {}

bool Queen::IsValidMove(int rank, int file, int toRank, int toFile) {
	// Calculate the absolute differences in ranks and files.
	int rankDiff = abs(rank - toRank);
	int fileDiff = abs(file - toFile);

	// A queen can move either vertically, horizontally, or diagonally.
	// Check if the move is valid in any of these directions.
	if(rank == toRank || file == toFile || rankDiff == fileDiff) { return true && Piece::IsValidMove(rank, file, toRank, toFile); }

	// If none of the above conditions are met, the move is invalid.
	return false;
}

bool Queen::IsValidCapture(int rank, int file, int toRank, int toFile) {
	// Calculate the absolute differences in ranks and files.
	int rankDiff = abs(rank - toRank);
	int fileDiff = abs(file - toFile);

	// A queen can move either vertically, horizontally, or diagonally.
	// Check if the move is valid in any of these directions.
	if(rank == toRank || file == toFile || rankDiff == fileDiff) { return true && Piece::IsValidMove(rank, file, toRank, toFile); }

	// If none of the above conditions are met, the move is invalid.
	return false;
}