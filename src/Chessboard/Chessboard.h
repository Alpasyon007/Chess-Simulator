#pragma once
#include "../Piece/Pawn/Pawn.h"
#include "../Piece/Knight/Knight.h"
#include "../Piece/Bishop/Bishop.h"
#include "../Piece/Rook/Rook.h"
#include "../Piece/Queen/Queen.h"
#include "../Piece/King/King.h"

#define RANKS 8
#define FILES 8

class Chessboard {
	private:
		int m_boardMatrix[RANKS][FILES];

		// White Pieces
		Pawn m_whitePawn[8];
		Knight m_whietKnight[2];

		// Black Pieces
		Pawn m_blackPawn[8];
		Knight m_blackKnight[2];
	private:
	public:	
		Chessboard();
		Chessboard(int boardMatrix[RANKS][FILES]);
		~Chessboard();

		// Print the chessboard
		void PrintBoard();
};