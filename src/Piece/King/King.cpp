#include "King.h"

King::King(Color color) : Piece(color, KING), m_hasMoved(false) {}

King::~King() {}

bool King::IsValidMove(int rank, int file, int toRank, int toFile) {
	// Calculate the absolute differences in ranks and files.
	int rankDiff = abs(rank - toRank);
	int fileDiff = abs(file - toFile);

	// A king can move one square in any direction (horizontally, vertically, or diagonally).
	if((rankDiff == 1 && fileDiff == 0) || // Vertical move
	   (rankDiff == 0 && fileDiff == 1) || // Horizontal move
	   (rankDiff == 1 && fileDiff == 1)) { // Diagonal move
		return true && Piece::IsValidMove(rank, file, toRank, toFile);
	}

	// // Check for castling:
	// // The king can castle if it hasn't moved, and it's moving 2 squares horizontally (castling).
	// if(rankDiff == 0 && fileDiff == 2 && rank == toRank) {
	// 	// Check if the king is not in check, and the squares between the king and rook are empty.
	// 	// Implement these additional conditions as per your chess game's logic.
	// 	// You also need to check if the king and rook involved haven't moved before.
	// 	if(IsCastlingValid(rank, file, toRank, toFile)) {
	// 		return true; // Valid castling move
	// 	}
	// }

	// If none of the above conditions are met, the move is invalid.
	return false;
}

bool King::IsValidCapture(int rank, int file, int toRank, int toFile) {
	// Calculate the absolute differences in ranks and files.
	int rankDiff = abs(rank - toRank);
	int fileDiff = abs(file - toFile);

	// A king can move one square in any direction (horizontally, vertically, or diagonally).
	if((rankDiff == 1 && fileDiff == 0) || // Vertical move
	   (rankDiff == 0 && fileDiff == 1) || // Horizontal move
	   (rankDiff == 1 && fileDiff == 1)) { // Diagonal move
		return true && Piece::IsValidMove(rank, file, toRank, toFile);
	}

	// Check for castling:
	// The king can castle if it hasn't moved, and it's moving 2 squares horizontally (castling).
	// if(rankDiff == 0 && fileDiff == 2 && rank == toRank) {
	// 	// Check if the king is not in check, and the squares between the king and rook are empty.
	// 	// Implement these additional conditions as per your chess game's logic.
	// 	// You also need to check if the king and rook involved haven't moved before.
	// 	if(IsCastlingValid(rank, file, toRank, toFile)) {
	// 		return true; // Valid castling move
	// 	}
	// }

	// If none of the above conditions are met, the move is invalid.
	return false;
}

bool King::GetHasMoved() { return m_hasMoved; }

void King::SetHasMoved(bool moved) { m_hasMoved = moved; }