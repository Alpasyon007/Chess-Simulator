#include "./Chessboard/Chessboard.h"
#include <fcntl.h>
#include <io.h>

int main() {
	_setmode(_fileno(stdout), _O_U16TEXT);

	Chessboard Board;
	// Board.MovePiece(("b2"), ("b3"));
	// Board.MovePiece(("c7"), ("c5"));
	Board.PrintBoard();

	Board.PrintSquaresUnderThreat();

	return 0;
}