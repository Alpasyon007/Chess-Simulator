#include "Piece.h"

Piece::Piece(Color color) : m_color(color) {};

Piece::~Piece() {};

bool Piece::Move() { return false; }