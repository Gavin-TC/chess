#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include <constants.h>

char** setupBoard(bool is_player_first);
Piece* setupPieces(bool is_player_first);
void drawBoard(char** board, Piece* pieces);
bool evaluateMove(char* move);
void movePiece(char** board, Piece* pieces, char* move);
void freeBoard(char** board);

// externs
extern Piece pieces[32];

#endif // !BOARD_H
