#include "Queen.h"

Queen::Queen(Color color) : Piece(color, QUEEN) {}

Queen::~Queen() {}

bool Queen::Move() { return false; }