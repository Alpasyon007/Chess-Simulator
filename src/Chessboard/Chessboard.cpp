#include <iostream>
#include "Chessboard.h"

#define WHITE_PAWN(_ARG_) &White.pawn[_ARG_]
#define WHITE_KNIGHT(_ARG_) &White.knight[_ARG_]
#define WHITE_BISHOP(_ARG_) &White.bishop[_ARG_]
#define WHITE_ROOK(_ARG_) &White.rook[_ARG_]
#define WHITE_QUEEN &White.queen
#define WHITE_KING &White.king

#define BLACK_PAWN(_ARG_) &Black.pawn[_ARG_]
#define BLACK_KNIGHT(_ARG_) &Black.knight[_ARG_]
#define BLACK_BISHOP(_ARG_) &Black.bishop[_ARG_]
#define BLACK_ROOK(_ARG_) &Black.rook[_ARG_]
#define BLACK_QUEEN &Black.queen
#define BLACK_KING &Black.king

Chessboard::Chessboard() : m_boardMatrix{
	{ BLACK_ROOK(0),	BLACK_KNIGHT(0),	BLACK_BISHOP(0),	BLACK_QUEEN,	BLACK_KING,		BLACK_BISHOP(1),	BLACK_KNIGHT(1),	BLACK_ROOK(1) },
	{ BLACK_PAWN(0),	BLACK_PAWN(1),		BLACK_PAWN(2),		BLACK_PAWN(3),	BLACK_PAWN(4),	BLACK_PAWN(5),		BLACK_PAWN(6),		BLACK_PAWN(7) },
	{ nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr },
	{ nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr },
	{ nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr },
	{ nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr },
	{ WHITE_PAWN(0),	WHITE_PAWN(1),		WHITE_PAWN(2),		WHITE_PAWN(3),	WHITE_PAWN(4),	WHITE_PAWN(5),		WHITE_PAWN(6),		WHITE_PAWN(7) },
	{ WHITE_ROOK(0),	WHITE_KNIGHT(0),	WHITE_BISHOP(0),	WHITE_QUEEN,	WHITE_KING,		WHITE_BISHOP(1),	WHITE_KNIGHT(1),	WHITE_ROOK(1) }
	} {
}

void Chessboard::PrintBoard() {
	// Iterate over the ranks
	for (int i = 0; i < RANKS; i++) {
		// Itreate over the files
		for (int j = 0; j < FILES; j++)	{
			// Print the squares
			if(m_boardMatrix[i][j] == nullptr) {
				std::cout << m_boardMatrix[i][j] << "\t";
				continue;
			}
			std::cout << *m_boardMatrix[i][j] << "   ";
		}
		std::cout << std::endl;
	}
}