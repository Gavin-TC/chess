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

// TODO: is_player_first needs to be replaced with
// a parameter or a extern that is changed depending
// on whos turn it is.

bool isPieceMoveValid(Piece** pieces, Piece* chosen_piece, Piece* target_piece, int file1, int rank1, int file2, int rank2) {
  // 0: PAWN    3: ROOK
  // 1: BISHOP  4: QUEEN
  // 2: KNIGHT  5: KING
  
  if (target_piece != NULL) {
    // if the piece is ours
    if (target_piece->color == (is_player_first ? WHITE : BLACK)) {
      printf("You can't move a piece onto your own piece!\n");
      return false;
    }
  }
  
  switch (chosen_piece->type) {
    case 0:  // PAWN
      // if we're trying to move up 1/2 spaces and it's not on a piece 
      // (PAWN can move twice by default, add checks to see if it's moved before)
      // replace 1 and 2 with correct number based on player's piece
      
      if (file1 == file2 && rank2 == rank1 + (is_player_first ? -1 : 1)) {
        if (target_piece != NULL) {
          if (target_piece->pos.x == file2 && target_piece->pos.y == rank2) {
            printf("You can only attack diagonally with a pawn!\n");
            return false;
          }
        }
        return true;

        // if we're trying to go 2 spaces, check if its the first pawn move
      } else if (file1 == file2 && (rank2 == rank1 + (is_player_first ? -2 : 2))
                 && chosen_piece->pos.y == (is_player_first ? 6 : 1)) {
        if (target_piece != NULL) {
          if (target_piece->pos.x == file2 && target_piece->pos.y == rank2) {
            printf("You can only attack diagonally with a pawn!\n");
            return false;
          }
        }
        return true;

      } else if (file2 == file1 - 1 || file2 == file1 + 1 && rank2 == rank1 + (is_player_first ? -1 : 1)) { 
        if (target_piece->pos.x == file2 && target_piece->pos.y == rank2) {
          return true;
        }
      }

      printf("You can't move the pawn there!\n");
      return false;
    
    case 1: // BISHOP
      int file_difference = file2 - file1;
      int rank_difference = rank2 - rank1;

      int file_zeroed = file_difference * -1;
      int rank_zeroed = rank_difference * -1;

      if (abs(file_difference) == abs(rank_difference)) {
        // now we need to loop through each tile
        // towards the destination and check if there's a piece.
        for (int i = 1; i < abs(file_difference); i++) {
          for (int j = 0; j < 32; j++) {
            int target_x = file1 < file2 ? file1 + i : file1 - i;
            int target_y = rank1 < rank2 ? rank1 + i : rank1 - i;

            if (pieces[j]->pos.x == target_x && pieces[j]->pos.y == target_y) {
              printf("There's a piece blocking that bishop move!\n");
              return false;
            }
          }
        }
        printf("Moving the bishop...\n");
        return true;
      }
      
      printf("You can't move the bishop there!\n");
      return false;
    
    case 2:  // KNIGHT
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
      int ver_difference = rank2 - rank1;
      int hor_difference = file2 - file1;

      if (abs(hor_difference) > 0 && ver_difference == 0) {
        for (int i = file1 + (hor_difference < 0 ? -1 : 1); i != file2; i += (hor_difference < 0 ? -1 : 1)) {
          for (int j = 0; j < 32; j++) {
            if (pieces[j]->pos.x == i && pieces[j]->pos.y == rank1
                && pieces[j] != target_piece && pieces[j] != chosen_piece) {
              printf("There's a piece blocking that horizontal rook move!\n");
              return false;
            }
          }
          return true;
        }
      } else if (abs(ver_difference) > 0 && hor_difference == 0) {
        for (int i = rank1 + (ver_difference < 0 ? -1 : 1); i != rank2; i += (ver_difference < 0 ? -1 : 1)) {
          for (int j = 0; j < 32; j++) {
            if (pieces[j]->pos.x == file1 && pieces[j]->pos.y == i 
                && pieces[j] != target_piece) {
              printf("There's a piece blocking that vertical rook move!\n");
              return false;
            }
          }
        return true;
        }
      }
      printf("You can't move the rook there!\n");
      return false;

    case 4: // QUEEN
      break;
    
    case 5: // KING
      break;
    
    default:
      printf("There was an issue making your move!\n");
  }

  return true;
}

void freePieces(Piece** pieces) {
  for (int y = 0; y < 32; y++) free(pieces[y]);
  free(pieces);
}
