#include <string>

class PiecePosition {
private:
	int m_rank; // Rank (row) of the piece
	int m_file; // File (column) of the piece
public:
	PiecePosition(const std::string& algebraicNotation);

	PiecePosition(const char* position);

	// PiecePosition(const std::string& descriptiveNotation);

	// PiecePosition(const std::string& ICCFNumericNotation);

	// Getter method to retrieve the rank (row)
	int GetRank() const { return m_rank; }

	// Getter method to retrieve the file (column)
	int GetFile() const { return m_file; }
};