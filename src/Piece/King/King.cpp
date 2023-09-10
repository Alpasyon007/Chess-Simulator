#include "King.h"

King::King(Color color) : Piece(color, KING) {}

King::~King() {}

bool King::IsValidMove(int rank, int file, int toRank, int toFile) { return false; }