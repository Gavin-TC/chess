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

bool isPieceMoveValid(Piece** pieces, Piece* chosen_piece, Piece* target_piece, int file1, int rank1, int file2, int rank2) {
  // 0: PAWN    3: ROOK
  // 1: BISHOP  4: QUEEN
  // 2: KNIGHT  5: KING
  
  switch (chosen_piece->type) {
    case 0:  // PAWN
      // if we're trying to move onto a piece
      if (target_piece != NULL) {
        // if the piece is ours
        if (target_piece->color == (is_player_first) ? WHITE : BLACK) {
          printf("You can't move a piece onto your own piece!\n");
          return false;
        }
      }
      
      // if we're trying to move up 1/2 spaces and it's not on a piece 
      // (PAWN can move twice by default, add checks to see if it's moved before)
      // replace 1 and 2 with correct number based on player's piece

      printf("file1(%d) == file2(%d) = %d\n", file1, file2, (file1 == file2));
      printf("rank2(%d) == rank1(%d) + 1 = %d\n", rank2, rank1, (rank2 == rank1 + 1));
      printf("rank2(%d) == rank1(%d) + 2 = %d\n", rank2, rank1, (rank2 == rank1 + 2));

      if (file1 == file2 && (rank2 == rank1 + (is_player_first) ? -1 : 1 || rank2 == rank1 + (is_player_first) ? -2 : 2)) {
        if (target_piece != NULL) {
          if (target_piece->pos.x == file2 && target_piece->pos.y == rank2) {
            printf("You can only attack diagonally with a pawn!\n");
            return false;
          }
        }
        printf("About to make the move!\n");
        return true;
      }
      printf("You can't move the pawn there!\n");
      return false;
    
    case 1: // BISHOP
      break;
    
    case 2:  // KNIGHT
      // if there's a piece on the attempt move spot
      if (target_piece == NULL) {
        // if the piece is ours
        if (target_piece->color == (is_player_first) ? WHITE : BLACK) {
          printf("You can't move a piece onto your own piece!\n");
          return false;
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
      }
      printf("You can't move the knight there!");
      return false;
    
    case 3: // ROOK
      break;

    case 4: // QUEEN
      break;
    
    case 5: // KING
      break;
  }

  return true;
}
