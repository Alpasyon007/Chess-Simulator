#include "./Chessboard/Chessboard.h"

int main() {
	Chessboard Board;
	Board.PrintBoard();
	Board.MovePiece(("b2"), ("b3"));
	std::cout << std::endl;
	Board.PrintBoard();
	Board.MovePiece(("c7"), ("c5"));
	std::cout << std::endl;
	Board.PrintBoard();
	return 0;
}