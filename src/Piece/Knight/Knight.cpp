#include "Knight.h"

Knight::Knight(Color color) : Piece(color, KNIGHT) {}

Knight::~Knight() {}

bool Knight::IsValidMove(int rank, int file, int toRank, int toFile) { return false; }