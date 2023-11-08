#ifndef PIECE_H
#define PIECE_H

#include <stdlib.h>
#include <stdbool.h>

#include <player.h>
#include <constants.h>
#include <board.h>

Piece* createPiece(enum PieceType type, enum PieceColor color, int x, int y, int value, char chr);
bool isPieceMoveValid(Piece** pieces, Piece* piece, int file1, int rank1, int file2, int rank2);

#endif // !PIECE_H
