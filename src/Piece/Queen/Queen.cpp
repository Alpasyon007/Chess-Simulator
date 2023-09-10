#include "Queen.h"

Queen::Queen(Color color) : Piece(color, QUEEN) {}

Queen::~Queen() {}

bool Queen::IsValidMove(int rank, int file, int toRank, int toFile) { return false; }