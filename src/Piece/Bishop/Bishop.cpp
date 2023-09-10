#include "Bishop.h"

Bishop::Bishop(Color color) : Piece(color, BISHOP) {}

Bishop::~Bishop() {}

bool Bishop::IsValidMove(int rank, int file, int toRank, int toFile) { return false; }