#include "./Chessboard/Chessboard.h"

int main() {
	Chessboard Board;
	Board.PrintBoard();
	Board.MovePiece(1, 1, 2, 1);
	std::cout << std::endl;
	Board.PrintBoard();
	return 0;
}