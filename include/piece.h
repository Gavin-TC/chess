#ifndef PIECE_H
#define PIECE_H

#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include <player.h>
#include <constants.h>
#include <board.h>

Piece* createPiece(enum PieceType type, enum PieceColor color, int x, int y, int value, char chr);
bool isPieceMoveValid(bool is_white, bool checking_attack, Piece** pieces, Piece* chosen_peice, Piece* target_piece, int file1, int rank1, int file2, int rank2);
bool moveIntoCheck(bool is_white, Piece** pieces, Piece* chosen_piece, Piece* target_piece, int file2, int rank2);

#endif // !PIECE_H
