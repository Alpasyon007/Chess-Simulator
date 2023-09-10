#include "Pawn.h"

Pawn::Pawn(Color color) : Piece(color, PAWN) {}

Pawn::~Pawn() {}

bool Pawn::IsValidMove(int rank, int file, int toRank, int toFile) {
	const bool isValid = (toFile == file) && Piece::IsValidMove(rank, file, toRank, toFile);

	switch(m_color) {
		case WHITE: {
			const bool pawnMove		 = (toRank == rank - 1);
			const bool pawnStartMove = (toRank == rank - 2);

			if(rank == 6) { return (pawnMove || pawnStartMove) && isValid; }
			return pawnMove && isValid;
		};
		case BLACK: {
			const bool pawnMove		 = (toRank == rank + 1);
			const bool pawnStartMove = (toRank == rank + 2);

			if(rank == 1) { return (pawnMove || pawnStartMove) && isValid; }
			return pawnMove && isValid;
		};
	}
}
