#pragma once

#include <utility>
#include <vector>

#include "../Piece/Bishop/Bishop.h"
#include "../Piece/King/King.h"
#include "../Piece/Knight/Knight.h"
#include "../Piece/Pawn/Pawn.h"
#include "../Piece/Queen/Queen.h"
#include "../Piece/Rook/Rook.h"
#include "../PiecePosition/PiecePosition.h"

#define RANKS 8
#define FILES 8

enum Status {
	EMPTY = 0,
	OCCUPIED
};

struct WhitePieces {
	Pawn   pawn[8]	 = {Pawn(WHITE), Pawn(WHITE), Pawn(WHITE), Pawn(WHITE), Pawn(WHITE), Pawn(WHITE), Pawn(WHITE), Pawn(WHITE)};
	Knight knight[2] = {Knight(WHITE), Knight(WHITE)};
	Bishop bishop[2] = {Bishop(WHITE), Bishop(WHITE)};
	Rook   rook[2]	 = {Rook(WHITE), Rook(WHITE)};
	Queen  queen	 = Queen(WHITE);
	King   king		 = King(WHITE);
};

struct BlackPieces {
	Pawn   pawn[8]	 = {Pawn(BLACK), Pawn(BLACK), Pawn(BLACK), Pawn(BLACK), Pawn(BLACK), Pawn(BLACK), Pawn(BLACK), Pawn(BLACK)};
	Knight knight[2] = {Knight(BLACK), Knight(BLACK)};
	Bishop bishop[2] = {Bishop(BLACK), Bishop(BLACK)};
	Rook   rook[2]	 = {Rook(BLACK), Rook(BLACK)};
	Queen  queen	 = Queen(BLACK);
	King   king		 = King(BLACK);
};

class Chessboard {
public:
	Chessboard();
	Chessboard(int boardMatrix[RANKS][FILES]);

	// Print the chessboard
	void					   PrintBoard();
	void					   PrintSquaresUnderThreat();

	void					   MovePiece(int rank, int file, int toRank, int toFile);
	void					   MovePiece(PiecePosition currentPosition, PiecePosition targetPosition);

	std::vector<PiecePosition> GetSquaresUnderThreat();

	bool					   CanCastleQueenSide();
	bool					   CanCastleKingSide();
private:
	std::string InternalToAlegbraicNotation(std::pair<int, int> internalNotation);
private:
	Piece*		m_boardMatrix[RANKS][FILES];

	Color		m_currentTurn;

	// White Pieces
	WhitePieces White;
	// Black Pieces
	BlackPieces Black;
};