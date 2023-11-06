#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>
#include <wchar.h>

wchar_t** createBoard(bool is_player_first);
void drawBoard(wchar_t** board);
void freeBoard(wchar_t** board);

#endif // !BOARD_H
