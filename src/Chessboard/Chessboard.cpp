#include <iostream>
#include "Chessboard.h"

Chessboard::Chessboard() {
	for (int i = 0; i < RANKS; i++) {
		for (int j = 0; j < FILES; j++)	{
			m_boardMatrix[i][j] = new Pawn(WHITE);
		}
		std::cout << std::endl;
	}
}

void Chessboard::PrintBoard() {
	// Iterate over the ranks
	for (int i = 0; i < RANKS; i++) {
		// Itreate over the files
		for (int j = 0; j < FILES; j++)	{
			// Print the squares
			std::cout << m_boardMatrix[i][j] << "  ";
		}
		std::cout << std::endl;
	}
}