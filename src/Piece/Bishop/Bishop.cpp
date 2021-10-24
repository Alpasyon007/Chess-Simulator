#include "Bishop.h"

Bishop::Bishop(Color color) : Piece(color, BISHOP) {}

Bishop::~Bishop() {}

bool Bishop::Move() { return false; }