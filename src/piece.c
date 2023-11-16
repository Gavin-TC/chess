#include <stdlib.h>

#include <piece.h>
#include <constants.h>

bool makeDiagonalMove(Piece** pieces, Piece* chosen_piece, Piece* target_piece, int file1, int rank1, int file2, int rank2);
bool makeAxisMove(Piece** pieces, Piece* chosen_piece, Piece* target_piece, int file1, int rank1, int file2, int rank2);
bool moveIntoCheck(bool is_white, Piece** pieces, Piece* chosen_piece, Piece* target_piece, int file2, int rank2);

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

bool isPieceMoveValid(bool is_white, Piece** pieces, Piece* chosen_piece, Piece* target_piece, int file1, int rank1, int file2, int rank2) {
  // 0: PAWN    3: ROOK
  // 1: BISHOP  4: QUEEN
  // 2: KNIGHT  5: KING
  bool valid_move = false;
  int file_difference = 0;
  int rank_difference = 0;

  if (target_piece != NULL) {
    // if the piece is ours
    if (target_piece->color == (is_white ? WHITE : BLACK)) {
      return false;
    }
  }

  switch (chosen_piece->type) {
    case 0:  // PAWN
      // if we're trying to move up 1/2 spaces and it's not on a piece 
      // (PAWN can move twice by default, add checks to see if it's moved before)
      // replace 1 and 2 with correct number based on player's piece
      if (file1 == file2 && rank2 == rank1 + (is_white ? -1 : 1)) {
        if (target_piece != NULL) {
          if (target_piece->pos.x == file2 && target_piece->pos.y == rank2) {
            return false;
          }
        }
        return true;

        // if we're trying to go 2 spaces, check if its the first pawn move
      } else if (file1 == file2 && (rank2 == rank1 + (is_white ? -2 : 2))
                 && chosen_piece->pos.y == (is_white ? 6 : 1)) {
        if (target_piece != NULL) {
          if (target_piece->pos.x == file2 && target_piece->pos.y == rank2) {
            return false;
          }
        }
        return true;
        
        // if we're attempting to take 
      } else if (file2 == file1 - 1 || file2 == file1 + 1 && rank2 == rank1 + (is_white ? -1 : 1)) { 
        if (target_piece != NULL) {
          if (target_piece->pos.x == file2 && target_piece->pos.y == rank2) {
            return true;
          }
        }
      }

      return false;
    
    case 1: // BISHOP
      valid_move = makeDiagonalMove(pieces, chosen_piece, target_piece, file1, rank1, file2, rank2);
      return valid_move;
    
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

      return false;
    
    case 3: // ROOK
      valid_move = makeAxisMove(pieces, chosen_piece, target_piece, file1, rank1, file2, rank2);
      return valid_move; 

    case 4: // QUEEN
      valid_move = false;
      
      file_difference = file2 - file1;
      rank_difference = rank2 - rank1;

      int ver_difference = rank2 - rank1;
      int hor_difference = file2 - file1;

      // if the move is diagonal, make diagonal move.
      if (abs(file_difference) == abs(rank_difference)) {
        valid_move = makeDiagonalMove(pieces, chosen_piece, target_piece, file1, rank1, file2, rank2);
      } else if (ver_difference == 0 && hor_difference != 0
              || ver_difference != 0 && hor_difference == 0) {
        valid_move = makeAxisMove(pieces, chosen_piece, target_piece, file1, rank1, file2, rank2);
      }
      
      return valid_move;
    
    case 5: // KING
      file_difference = file2 - file1;
      rank_difference = rank2 - rank1;

      if (abs(file_difference) == 1 && abs(rank_difference) == 1
          || abs(file_difference) == 0 && abs(rank_difference) == 1
          || abs(file_difference) == 1 && abs(rank_difference) == 0) {
        for (int i = 0; i < 32; i++) {
          // check if we're trying to go onto our own piece.
          if (pieces[i]->pos.x == file2 && pieces[i]->pos.y == rank2
              && pieces[i]->color == (is_white ? WHITE : BLACK)) {
            return false;
          }
        }
        // make sure the king isn't moving into check.
        if (moveIntoCheck(is_white, pieces, chosen_piece, target_piece, file2, rank2)) {
          return false;
        }
        return true;
      }
      return false;
    
    default:
      return false;
  }

  return true;
}

bool makeDiagonalMove(Piece** pieces, Piece* chosen_piece, Piece* target_piece, int file1, int rank1, int file2, int rank2) {
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
          return false;
        }
      }
    }
    return true;
  }
  return false;
}

bool makeAxisMove(Piece** pieces, Piece* chosen_piece, Piece* target_piece, int file1, int rank1, int file2, int rank2) {
  int ver_difference = rank2 - rank1;
  int hor_difference = file2 - file1;

  if (abs(hor_difference) > 0 && ver_difference == 0) {
    for (int i = file1 + (hor_difference < 0 ? -1 : 1); i != file2; i += (hor_difference < 0 ? -1 : 1)) {
      for (int j = 0; j < 32; j++) {
        if (pieces[j]->pos.x == i && pieces[j]->pos.y == rank1
            && pieces[j] != target_piece && pieces[j] != chosen_piece) {
          return false;
        }
      }
    }
    return true;
  } else if (abs(ver_difference) > 0 && hor_difference == 0) {
    for (int i = rank1 + (ver_difference < 0 ? -1 : 1); i != rank2; i += (ver_difference < 0 ? -1 : 1)) {
      for (int j = 0; j < 32; j++) {
        if (pieces[j]->pos.x == file1 && pieces[j]->pos.y == i 
            && pieces[j] != target_piece) {
          return false;
        }
      }
    }
    return true;
  }
  return false;
}

bool moveIntoCheck(bool is_white, Piece** pieces, Piece* chosen_piece, Piece* target_piece, int file2, int rank2) {
  // we need to check if the move is being attacked.
  // we can do this by looking at the pieces around the king
  // as well as checking the diagonals/axis. we can optimize this by checking
  // if one of these attacks would be blocking by a piece anyways and skip it.

  // eureka: loop through each piece and call isPieceMoveValid on the attempted square
  bool can_be_attacked = false;
  for (int i = 0; i < 32; i++) {
    if (pieces[i] != NULL) {
      if (pieces[i]->color == (is_white ? BLACK : WHITE)) {
        // check if a piece can move onto the king
        can_be_attacked = isPieceMoveValid(false, pieces, pieces[i], NULL, pieces[i]->pos.x, pieces[i]->pos.y, file2, rank2);
        // if any piece can do so, we immediately break as can_be_attacked is now true
        if (can_be_attacked) break;
      }
    }
  }
  if (can_be_attacked == true) {
    printf("%s is in check and it's not letting you make the move.\n", is_white ? "WHITE" : "BLACK");
  } 
  return can_be_attacked;
}

void freePieces(Piece** pieces) {
  for (int y = 0; y < 32; y++) free(pieces[y]);
  free(pieces);
}
