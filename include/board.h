#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include <constants.h>
#include <player.h>
#include <piece.h>

char** setupBoard(bool is_player_first);
Piece** setupPieces(bool is_player_first);
void drawBoard(char** board, Piece** pieces);
bool evaluateMove(char* move, char** board, Piece** pieces);
void movePiece(Piece** pieces, Piece* chosen_piece, int move_file, int move_rank);
void freeBoard(char** board);

// externs
extern Piece pieces[32];

#endif // !BOARD_H
