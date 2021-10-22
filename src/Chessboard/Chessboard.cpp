#include <iostream>
#include "Chessboard.h"

void Chessboard::PrintBoard() {
	// Iterate over the ranks
	for (int i = 0; i < RANKS; i++) {
		// Itreate over the files
		for (int j = 0; j < FILES; j++)	{
			// Print the squares
			std::cout << m_boardMatrix[i][j] << std::endl;
		}
		std::cout << std::endl;
	}
}