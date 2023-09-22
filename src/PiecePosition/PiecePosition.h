#include <string>

class PiecePosition {
public:
	PiecePosition(int rank, int file);

	PiecePosition(const std::string& algebraicNotation);

	PiecePosition(const char* algebraicNotation);

	// PiecePosition(const std::string& descriptiveNotation);

	// PiecePosition(const std::string& ICCFNumericNotation);

	// Getter method to retrieve the rank (row)
	int					  GetRank() const { return m_rank; }

	// Getter method to retrieve the file (column)
	int					  GetFile() const { return m_file; }

	friend bool			  operator==(const PiecePosition& lhs, const PiecePosition& rhs);
	friend std::wostream& operator<<(std::wostream& out, const PiecePosition& piecePosition);
private:
	int m_rank; // Rank (row) of the piece
	int m_file; // File (column) of the piece
};