#include "Pawn.h"

Pawn::Pawn(Color color) : Piece(color, PAWN) {}

Pawn::~Pawn() {}

bool Pawn::Move() { return false; }