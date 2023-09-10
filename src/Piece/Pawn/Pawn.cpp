#include "Pawn.h"

Pawn::Pawn(Color color) : Piece(color, PAWN) {}

Pawn::~Pawn() {}

bool Pawn::IsValidMove(int rank, int file, int toRank, int toFile) {
	// Implement your validation logic here
	// For a pawn, you might check if it's moving one step forward, capturing diagonally, etc.
	// Ensure the move is within the bounds of the board.
	// Return true if valid, false otherwise.
	// Example logic (adjust as needed):
	return (toRank >= 0 && toRank < 8 && toFile >= 0 && toFile < 8 && (toRank == rank + 1) && (toFile == file));
}
