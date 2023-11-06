#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>

char** createBoard(bool is_player_first);
void drawBoard(char** board);
void freeBoard(char** board);

#endif // !BOARD_H
