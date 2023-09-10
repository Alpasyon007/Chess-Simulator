#include "Knight.h"

Knight::Knight(Color color) : Piece(color, KNIGHT) {}

Knight::~Knight() {}

bool Knight::IsValidMove(int rank, int file, int toRank, int toFile) {
	// Calculate the absolute differences in ranks and files
	int rankDiff = std::abs(rank - toRank);
	int fileDiff = std::abs(file - toFile);

	// Knights move in an L-shape: 2 squares in one direction and 1 square in the other
	// So, the valid moves are (2, 1) or (1, 2) in terms of rankDiff and fileDiff
	return (rankDiff == 2 && fileDiff == 1) || (rankDiff == 1 && fileDiff == 2) && Piece::IsValidMove(rank, file, toRank, toFile);
}