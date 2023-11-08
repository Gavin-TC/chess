#include <stdlib.h>

#include <piece.h>
#include <constants.h>

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

bool isPieceMoveValid(Piece** pieces, Piece* piece, int file1, int rank1, int file2, int rank2) {
  // 0: PAWN    3: ROOK
  // 1: BISHOP  4: QUEEN
  // 2: KNIGHT  5: KING
  int piece_type = piece->type;

  switch (piece_type) {
    case 0:  // PAWN
      break;
    
    case 1: // BISHOP
      break;
    
    case 2:  // KNIGHT
      // checking if the move is ontop of a same colored piece 
      for (int i = 0; i < 32; i++) {
        // if there's a piece on the attempt move spotif
        if (pieces[i]->pos.x == file2 && pieces[i]->pos.y == rank2) {
          // if the piece is our piece
          if (pieces[i]->color == (is_player_first) ? 0 : 1) {
            printf("You can't move a piece onto your own piece!\n");
            return false;
          }
        }
      }

      if (file2 == file1 + 1 && (rank2 == rank1 + 2 || rank2 == rank1 - 2)) {
        // up/down 2 right 1
        return true;
      } else if (file2 == file1 + 2 && (rank2 == rank1 + 1 || rank2 == rank1 - 1)) {
        // up/down 1 right 2
        return true;
      } else if (file2 == file1 - 1 && (rank2 == rank1 + 2 || rank2 == rank1 - 2)) {
        // up/down 2 left 1
        return true;
      } else if (file2 == file1 + 2 && (rank2 == rank1 + 1 || rank2 == rank1 - 1)) {
        // up/down 1 left 2
        return true;
      } else {
        printf("You can't move the knight there!");
        return false;
      }
      break;
    
    case 3: // ROOK
      break;

    case 4: // QUEEN
      break;
    
    case 5: // KING
      break;
  }

  return true;
}
