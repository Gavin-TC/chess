#include <stdlib.h>

#include <constants.h>
#include <piece.h>

Piece* createPiece(enum PieceType type, enum PieceColor color, int x, int y, int value, char chr) {
  Piece* new_piece = (Piece*) malloc(sizeof(Piece));

  if (new_piece == NULL) { return NULL; }

  new_piece->type = type;
  new_piece->color = color;
  new_piece->pos.x = x;
  new_piece->pos.y = y;
  new_piece->value = value;
  new_piece->chr = chr;

  return new_piece;
}
