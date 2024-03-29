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

# Find packages
find_package(OpenGL REQUIRED)

# Add the executable
add_executable(
	ChessSim
	${SOURCE_DIR}/main.cpp
	${SOURCE_DIR}/Chessboard/Chessboard.cpp
	${SOURCE_DIR}/Chessboard/Chessboard.h
	${SOURCE_DIR}/Piece/Piece.cpp
	${SOURCE_DIR}/Piece/Piece.h
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
	${SOURCE_DIR}/PiecePosition/PiecePosition.cpp
	${SOURCE_DIR}/PiecePosition/PiecePosition.h
	)

	# Include target directories
	target_include_directories(
		ChessSim
		PRIVATE
		${SOURCE_DIR}/Chessboard
		${SOURCE_DIR}/Piece
		${SOURCE_DIR}/Piece/Pawn
		${SOURCE_DIR}/Piece/Knight
		${SOURCE_DIR}/Piece/Bishop
		${SOURCE_DIR}/Piece/Rook
		${SOURCE_DIR}/Piece/Queen
		${SOURCE_DIR}/Piece/King
		${SOURCE_DIR}/PiecePosition
	)