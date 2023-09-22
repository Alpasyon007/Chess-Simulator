#include "Chessboard.h"
#include <algorithm>
#include <array>
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
					// {BLACK_ROOK(0), BLACK_KNIGHT(0), BLACK_BISHOP(0), BLACK_QUEEN, BLACK_KING, BLACK_BISHOP(1), BLACK_KNIGHT(1), BLACK_ROOK(1)},
					// {BLACK_PAWN(0), BLACK_PAWN(1), BLACK_PAWN(2), BLACK_PAWN(3), BLACK_PAWN(4), BLACK_PAWN(5), BLACK_PAWN(6), BLACK_PAWN(7)},
					// {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
					// {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
					// {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
					// {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
					// {WHITE_PAWN(0), WHITE_PAWN(1), WHITE_PAWN(2), WHITE_PAWN(3), WHITE_PAWN(4), WHITE_PAWN(5), WHITE_PAWN(6), WHITE_PAWN(7)},
					// {WHITE_ROOK(0), WHITE_KNIGHT(0), WHITE_BISHOP(0), WHITE_QUEEN, WHITE_KING, WHITE_BISHOP(1), WHITE_KNIGHT(1), WHITE_ROOK(1)}
					{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
					{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
					{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
					{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
					{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
					{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
					{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
					{nullptr, WHITE_BISHOP(0), nullptr, nullptr, nullptr, nullptr, nullptr}
					}, m_currentTurn(WHITE) {}

void Chessboard::PrintBoard() {
	static const std::wstring ideographicSpace = L"\u3000";
	static const std::wstring punctuationSpace = L"\u2008";
	static const std::wstring fileLabels	   = L"abcdefgh";

	// ANSI escape codes to clear the screen
	std::wcout << L"\033[H\033[J";

	// Print file labels
	std::wcout << ideographicSpace << ideographicSpace;
	for(wchar_t file : fileLabels) {
		std::wcout << file << punctuationSpace;
	}
	std::wcout << std::endl;
	std::wcout << ideographicSpace << ideographicSpace;
	for(int i = 0; i < 8; i++) {
		std::wcout << i << punctuationSpace;
	}
	std::wcout << std::endl;

	// Iterate over the ranks
	for(int rank = 0; rank < RANKS; rank++) {
		std::wcout << (8 - rank) << punctuationSpace;
		std::wcout << (rank) << punctuationSpace;

		// Iterate over the files
		for(int file = 0; file < FILES; file++) {
			if(m_boardMatrix[rank][file] == nullptr) {
				std::wcout << ideographicSpace;
			} else {
				std::wcout << *m_boardMatrix[rank][file] << " ";
			}
		}

		std::wcout << punctuationSpace << (rank) << punctuationSpace;
		std::wcout << punctuationSpace << (8 - rank) << std::endl;
	}

	// Print file labels again
	std::wcout << ideographicSpace << ideographicSpace;
	for(wchar_t file : fileLabels) {
		std::wcout << file << punctuationSpace;
	}
	std::wcout << std::endl;
	std::wcout << ideographicSpace << ideographicSpace;
	for(int i = 0; i < 8; i++) {
		std::wcout << i << punctuationSpace;
	}
	std::wcout << std::endl;
}

void Chessboard::MovePiece(int rank, int file, int toRank, int toFile) {
	Piece** currentPiece = &(m_boardMatrix[rank][file]);
	bool	validMove	 = (*currentPiece)->IsValidMove(rank, file, toRank, toFile) && (*currentPiece)->GetColor() == m_currentTurn;

	if(validMove) {
		m_boardMatrix[toRank][toFile] = *currentPiece;

		switch((*currentPiece)->GetType()) {
			case KING: static_cast<King*>((*currentPiece))->SetHasMoved(true);
			case ROOK: static_cast<Rook*>((*currentPiece))->SetHasMoved(true);
			default: break;
		}

		*currentPiece = nullptr;
		m_currentTurn = static_cast<Color>(m_currentTurn ^ BLACK);
	};
}

void Chessboard::MovePiece(PiecePosition currentPosition, PiecePosition targetPosition) {
	MovePiece(currentPosition.GetRank(), currentPosition.GetFile(), targetPosition.GetRank(), targetPosition.GetFile());
}

std::vector<PiecePosition> Chessboard::GetSquaresUnderThreat() {
	std::vector<PiecePosition> threatenedSquares;
	Color					   pieceColor = WHITE;

	// Iterate through the board
	for(int rank = 0; rank < RANKS; rank++) {
		for(int file = 0; file < FILES; file++) {
			Piece* currentPiece = m_boardMatrix[rank][file];

			// Skip empty squares
			if(currentPiece == nullptr) { continue; }

			// Iterate through the board to check for threatened squares
			for(int toRank = 0; toRank < RANKS; toRank++) {
				for(int toFile = 0; toFile < FILES; toFile++) {
					// Check if the move is valid for the current piece
					if(currentPiece->IsValidCapture(rank, file, toRank, toFile)) {
						// Add threatened square to the vector
						threatenedSquares.emplace_back(toRank, toFile);
					}
				}
			}
		}
	}

	return threatenedSquares;
}

bool Chessboard::CanCastleKingSide() {
	// Check if it's white's turn and they haven't moved their king or king-side rook
	if(m_currentTurn == WHITE) {
		if(!White.king.GetHasMoved() && !White.rook[1].GetHasMoved()) {
			// Check if the squares between the king and rook are empty
			if(m_boardMatrix[7][5] == nullptr && m_boardMatrix[7][6] == nullptr) {
				// Check if these squares are not under threat from opponent pieces
				std::vector<PiecePosition> threatenedSquares = GetSquaresUnderThreat();
				for(const PiecePosition& position : threatenedSquares) {
					if(PiecePosition(7, 4) == position || PiecePosition(7, 5) == position || PiecePosition(7, 6) == position) { return false; }
				}
				return true;
			}
		}
	} else {
		// Check if it's black's turn and they haven't moved their king or king-side rook
		if(!Black.king.GetHasMoved() && !Black.rook[1].GetHasMoved()) {
			// Check if the squares between the king and rook are empty
			if(m_boardMatrix[0][5] == nullptr && m_boardMatrix[0][6] == nullptr) {
				// Check if these squares are not under threat from opponent pieces
				std::vector<PiecePosition> threatenedSquares = GetSquaresUnderThreat();
				for(const PiecePosition& position : threatenedSquares) {
					if(PiecePosition(0, 4) == position || PiecePosition(0, 5) == position || PiecePosition(0, 6) == position) { return false; }
				}
				return true;
			}
		}
	}
	return false;
}

bool Chessboard::CanCastleQueenSide() {
	// Check if it's white's turn and they haven't moved their king or queen-side rook
	if(m_currentTurn == WHITE) {
		if(!White.king.GetHasMoved() && !White.rook[0].GetHasMoved()) {
			// Check if the squares between the king and rook are empty
			if(m_boardMatrix[7][1] == nullptr && m_boardMatrix[7][2] == nullptr && m_boardMatrix[7][3] == nullptr) {
				// Check if these squares are not under threat from opponent pieces
				std::vector<PiecePosition> threatenedSquares = GetSquaresUnderThreat();
				for(const auto& position : threatenedSquares) {
					if(PiecePosition(7, 4) == position || PiecePosition(7, 3) == position || PiecePosition(7, 2) == position) { return false; }
				}
				return true;
			}
		}
	} else {
		// Check if it's black's turn and they haven't moved their king or queen-side rook
		if(!Black.king.GetHasMoved() && !Black.rook[0].GetHasMoved()) {
			// Check if the squares between the king and rook are empty
			if(m_boardMatrix[0][1] == nullptr && m_boardMatrix[0][2] == nullptr && m_boardMatrix[0][3] == nullptr) {
				// Check if these squares are not under threat from opponent pieces
				std::vector<PiecePosition> threatenedSquares = GetSquaresUnderThreat();
				for(const PiecePosition& position : threatenedSquares) {
					if(PiecePosition(0, 4) == position || PiecePosition(0, 3) == position || PiecePosition(0, 2) == position) { return false; }
				}
				return true;
			}
		}
	}
	return false;
}

void Chessboard::PrintSquaresUnderThreat() {
	static const std::wstring ideographicSpace = L"\u3000";
	static const std::wstring punctuationSpace = L"\u2008";
	static const std::wstring fileLabels	   = L"abcdefgh";
	std::wcout << std::endl;

	// Print file labels
	std::wcout << ideographicSpace << ideographicSpace;
	for(wchar_t file : fileLabels) {
		std::wcout << file << punctuationSpace;
	}
	std::wcout << std::endl;
	std::wcout << ideographicSpace << ideographicSpace;
	for(int i = 0; i < 8; i++) {
		std::wcout << i << punctuationSpace;
	}
	std::wcout << std::endl;

	std::array<std::array<int, 8>, 8> m_threatenedSpuares;

	for(int i = 0; i < RANKS; i++) {
		for(int j = 0; j < FILES; j++) {
			m_threatenedSpuares[i][j] = 0;
		}
	}

	std::vector<PiecePosition> threatenedSquares = GetSquaresUnderThreat();

	for(auto square : threatenedSquares) {
		m_threatenedSpuares[square.GetRank()][square.GetFile()] = 1;
	}

	for(int i = 0; i < RANKS; i++) {
		std::wcout << (8 - i) << punctuationSpace;
		std::wcout << (i) << punctuationSpace;

		for(int j = 0; j < FILES; j++) {
			std::wcout << m_threatenedSpuares[i][j] << " ";
		}

		std::wcout << (i) << punctuationSpace;
		std::wcout << punctuationSpace << (8 - i);
		std::wcout << std::endl;
	}

	// Print file labels again
	std::wcout << ideographicSpace << ideographicSpace;
	for(wchar_t file : fileLabels) {
		std::wcout << file << punctuationSpace;
	}
	std::wcout << std::endl;
	std::wcout << ideographicSpace << ideographicSpace;
	for(int i = 0; i < 8; i++) {
		std::wcout << i << punctuationSpace;
	}
	std::wcout << std::endl;
}