#ifndef PLAYER_H
#define PLAYER_H

#include <stdbool.h>
#include <stdio.h>

#include <constants.h>
#include <board.h>

char* getPlayerMove(void);

// externs
extern bool is_player_first;

#endif // !PLAYER_H
