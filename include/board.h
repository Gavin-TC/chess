#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>

#include <constants.h>

char** setupBoard(bool is_player_first);
Piece* setupPieces(bool is_player_first);
void drawBoard(char** board, Piece* pieces);
void freeBoard(char** board);

// externs
extern Piece pieces[32];

#endif // !BOARD_H
