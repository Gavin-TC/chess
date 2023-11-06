#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <stdlib.h>
#include <wchar.h>

#define BOARD_WIDTH 8
#define BOARD_HEIGHT 8

enum PieceType {
  PAWN,
  BISHOP,
  KNIGHT,
  ROOK,
  QUEEN,
  KING
};

enum PieceColor {
  WHITE,
  BLACK
};

typedef struct Piece {
  enum PieceType type;
  enum PieceColor color;
  int value;
  wchar_t chr; // unicode character
} Piece;

// externs
// sorted by value

// white pieces
extern struct Piece wPawn;
extern struct Piece wBishop;
extern struct Piece wKnight;
extern struct Piece wRook;
extern struct Piece wQueen;
extern struct Piece wKing;

// black pieces
extern struct Piece bPawn;
extern struct Piece bBishop;
extern struct Piece bKnight;
extern struct Piece bRook;
extern struct Piece bQueen;
extern struct Piece bKing;

#endif // !CONSTANTS_H
