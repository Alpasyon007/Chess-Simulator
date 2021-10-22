# CMake Bulid File
#
# CMake Version
cmake_minimum_required(VERSION 3.10)

# Compiler Settings
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set Variables
set(SOURCE_DIR src)

# Set the project name
project(ChessSim)

# Add the executable
add_executable(
	ChessSim
		${SOURCE_DIR}/main.cpp
		${SOURCE_DIR}/Piece/Piece.h
		${SOURCE_DIR}/Board/Board.h
		${SOURCE_DIR}/Piece/Pawn/Pawn.cpp
		${SOURCE_DIR}/Piece/Pawn/Pawn.h
		${SOURCE_DIR}/Piece/Knight/Knight.cpp
		${SOURCE_DIR}/Piece/Knight/Knight.h
		${SOURCE_DIR}/Piece/Bishop/Bishop.cpp
		${SOURCE_DIR}/Piece/Bishop/Bishop.h
		${SOURCE_DIR}/Piece/Rook/Rook.cpp
		${SOURCE_DIR}/Piece/Rook/Rook.h
		${SOURCE_DIR}/Piece/Queen/Queen.cpp
		${SOURCE_DIR}/Piece/Queen/Queen.h
		${SOURCE_DIR}/Piece/King/King.cpp
		${SOURCE_DIR}/Piece/King/King.h
)

# Include target directories
target_include_directories(
	ChessSim
	PRIVATE
		${SOURCE_DIR}/ChessBoard
		${SOURCE_DIR}/Piece
		${SOURCE_DIR}/Piece/Pawn
		${SOURCE_DIR}/Piece/Knight
		${SOURCE_DIR}/Piece/Bishop
		${SOURCE_DIR}/Piece/Rook
		${SOURCE_DIR}/Piece/Queen
		${SOURCE_DIR}/Piece/King
)