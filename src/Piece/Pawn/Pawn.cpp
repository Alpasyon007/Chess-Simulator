#include "Pawn.h"

Pawn::Pawn(Color color) : Piece(color, PAWN) {}

Pawn::~Pawn() {}

bool Pawn::IsValidMove(int rank, int file, int toRank, int toFile) {
	const bool isValid = (toFile == file) && Piece::IsValidMove(rank, file, toRank, toFile);

	switch(m_color) {
		case WHITE: {
			const bool pawnMove			 = (toRank == rank - 1);
			const bool pawnStartMove	 = (toRank == rank - 2);
			const bool pawnStartPosition = (rank == 6);

			return ((pawnStartPosition && (pawnMove || pawnStartMove)) || (!pawnStartPosition && pawnMove)) && isValid;
		}
		case BLACK: {
			const bool pawnMove			 = (toRank == rank + 1);
			const bool pawnStartMove	 = (toRank == rank + 2);
			const bool pawnStartPosition = (rank == 1);

			return ((pawnStartPosition && (pawnMove || pawnStartMove)) || (!pawnStartPosition && pawnMove)) && isValid;
		}
	}
}

bool Pawn::IsValidCapture(int rank, int file, int toRank, int toFile) {
	// Calculate the rank and file difference

	int rankDiff = toRank - rank;
	int fileDiff = abs(toFile - file); // Use abs to ensure the file difference is positive

	// Depending on the Pawn's color, validate the capture
	switch(m_color) {
		case WHITE: {
			// White Pawns can only capture diagonally by moving one rank forward and one file left or right
			return (rankDiff == -1 && fileDiff == 1);
		}
		case BLACK: {
			// Black Pawns can only capture diagonally by moving one rank backward and one file left or right
			return (rankDiff == 1 && fileDiff == 1);
		}
	}
}