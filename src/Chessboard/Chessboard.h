#pragma once

#include <vector>

#include "../Piece/Pawn/Pawn.h"
#include "../Piece/Knight/Knight.h"
#include "../Piece/Bishop/Bishop.h"
#include "../Piece/Rook/Rook.h"
#include "../Piece/Queen/Queen.h"
#include "../Piece/King/King.h"

#define RANKS 8
#define FILES 8

enum Status {
	EMPTY = 0,
	OCCUPIED
};
struct WhitePieces {
	Pawn pawn[8] = { Pawn(WHITE), Pawn(WHITE), Pawn(WHITE), Pawn(WHITE), Pawn(WHITE), Pawn(WHITE), Pawn(WHITE), Pawn(WHITE) };
	Knight knight[2] = { Knight(WHITE), Knight(WHITE) };
	Bishop bishop[2] = { Bishop(WHITE), Bishop(WHITE) };
	Rook rook[2] = { Rook(WHITE), Rook(WHITE) };
	Queen queen[2] = { Queen(WHITE), Queen(WHITE) };
	King king[2] = { King(WHITE), King(WHITE) };
};

struct BlackPieces {
	Pawn pawn[8] = { Pawn(BLACK), Pawn(BLACK), Pawn(BLACK), Pawn(BLACK), Pawn(BLACK), Pawn(BLACK), Pawn(BLACK), Pawn(BLACK) };
	Knight knight[2] = { Knight(BLACK), Knight(BLACK) };
	Bishop bishop[2] = { Bishop(BLACK), Bishop(BLACK) };
	Rook rook[2] = { Rook(BLACK), Rook(BLACK) };
	Queen queen[2] = { Queen(BLACK), Queen(BLACK) };
	King king[2] = { King(BLACK), King(BLACK) };
};

class Chessboard {
	private:
		Piece* m_boardMatrix[RANKS][FILES];

		// White Pieces
		WhitePieces White;

		// Black Pieces
		BlackPieces Black;

	private:
	public:
		Chessboard();
		Chessboard(int boardMatrix[RANKS][FILES]);
		// ~Chessboard();

		// Print the chessboard
		void PrintBoard();
};