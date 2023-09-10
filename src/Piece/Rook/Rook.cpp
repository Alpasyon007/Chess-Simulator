#include "Rook.h"

Rook::Rook(Color color) : Piece(color, ROOK) {}

Rook::~Rook() {}

bool Rook::IsValidMove(int rank, int file, int toRank, int toFile) { return false; }