#include "Chessboard.h"
#include <iostream>

// Macro white pieces
#define WHITE_PAWN(_ARG_)	&White.pawn[_ARG_]
#define WHITE_KNIGHT(_ARG_) &White.knight[_ARG_]
#define WHITE_BISHOP(_ARG_) &White.bishop[_ARG_]
#define WHITE_ROOK(_ARG_)	&White.rook[_ARG_]
#define WHITE_QUEEN			&White.queen
#define WHITE_KING			&White.king

// Macro black pieces
#define BLACK_PAWN(_ARG_)	&Black.pawn[_ARG_]
#define BLACK_KNIGHT(_ARG_) &Black.knight[_ARG_]
#define BLACK_BISHOP(_ARG_) &Black.bishop[_ARG_]
#define BLACK_ROOK(_ARG_)	&Black.rook[_ARG_]
#define BLACK_QUEEN			&Black.queen
#define BLACK_KING			&Black.king

Chessboard::Chessboard()
	: m_boardMatrix{// Construct initial board state
					{BLACK_ROOK(0), BLACK_KNIGHT(0), BLACK_BISHOP(0), BLACK_QUEEN, BLACK_KING, BLACK_BISHOP(1), BLACK_KNIGHT(1), BLACK_ROOK(1)},
					{BLACK_PAWN(0), BLACK_PAWN(1), BLACK_PAWN(2), BLACK_PAWN(3), BLACK_PAWN(4), BLACK_PAWN(5), BLACK_PAWN(6), BLACK_PAWN(7)},
					{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
					{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
					{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
					{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
					{WHITE_PAWN(0), WHITE_PAWN(1), WHITE_PAWN(2), WHITE_PAWN(3), WHITE_PAWN(4), WHITE_PAWN(5), WHITE_PAWN(6), WHITE_PAWN(7)},
					{WHITE_ROOK(0), WHITE_KNIGHT(0), WHITE_BISHOP(0), WHITE_QUEEN, WHITE_KING, WHITE_BISHOP(1), WHITE_KNIGHT(1), WHITE_ROOK(1)}}, m_currentTurn(WHITE) {}

void Chessboard::PrintBoard() {
	static const std::string ideographicSpace = "\u3000";
	static const std::string punctuationSpace = "\u2008";
	static const std::string fileLabels		  = "abcdefgh";

	// ANSI escape codes to clear the screen
	// std::cout << "\033[H\033[J";

	// Print file labels
	std::cout << ideographicSpace;
	for(char file : fileLabels) {
		std::cout << file << punctuationSpace;
	}
	std::cout << std::endl;

	// Iterate over the ranks
	for(int rank = 0; rank < RANKS; rank++) {
		std::cout << (8 - rank) << punctuationSpace;

		// Iterate over the files
		for(int file = 0; file < FILES; file++) {
			if(m_boardMatrix[rank][file] == nullptr) {
				std::cout << ideographicSpace;
			} else {
				std::cout << *m_boardMatrix[rank][file] << " ";
			}
		}

		std::cout << punctuationSpace << (8 - rank) << std::endl;
	}

	// Print file labels again
	std::cout << ideographicSpace;
	for(char file : fileLabels) {
		std::cout << file << punctuationSpace;
	}
	std::cout << std::endl;
}

void Chessboard::MovePiece(int rank, int file, int toRank, int toFile) {
	Piece** currentPiece = &(m_boardMatrix[rank][file]);
	bool	validMove	 = (*currentPiece)->IsValidMove(rank, file, toRank, toFile) && (*currentPiece)->GetColor() == m_currentTurn;

	if(validMove) {
		m_boardMatrix[toRank][toFile] = *currentPiece;
		*currentPiece				  = nullptr;
		m_currentTurn				  = static_cast<Color>(m_currentTurn ^ BLACK);
	};
}

void Chessboard::MovePiece(PiecePosition currentPosition, PiecePosition targetPosition) {
	std::cout << currentPosition.GetRank() << currentPosition.GetFile() << targetPosition.GetRank() << targetPosition.GetFile() << std::endl;
	MovePiece(currentPosition.GetRank(), currentPosition.GetFile(), targetPosition.GetRank(), targetPosition.GetFile());
}