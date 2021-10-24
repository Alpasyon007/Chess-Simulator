#include "King.h"

King::King(Color color) : Piece(color, KING) {}

King::~King() {}

bool King::Move() { return false; }