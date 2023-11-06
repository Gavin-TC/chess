#ifndef INIT_H
#define INIT_H

#include <stdio.h>
#include <stdbool.h>

void initialize(bool is_player_first);
void killPiece(Piece* pieces, int* num_pieces, Piece* piece_to_remove);

// externs
extern Piece** pieces;

#endif // !INIT_H
