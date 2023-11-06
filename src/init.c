#include <constants.h>
#include <init.h>

Piece** pieces = NULL;

void initialize(bool is_player_first) {
  pieces = (Piece**) malloc(32 * sizeof(Piece*));
//  Piece* pieces = (Piece*) malloc(32 * sizeof(Piece));
  int black_height = is_player_first ? (BOARD_HEIGHT - 1) : 0;

	for (int i = 0; i < 8; i++) {
	  pieces[i] = createPiece(PAWN,  WHITE, i, 1, 1, 'P');
	}

	pieces[8]  = createPiece(ROOK,   WHITE, 0, 0, 5, 'R');
	pieces[9]  = createPiece(KNIGHT, WHITE, 1, 0, 3, 'N');
	pieces[10] = createPiece(BISHOP, WHITE, 2, 0, 3, 'B');
	pieces[11] = createPiece(QUEEN,  WHITE, 3, 0, 9, 'Q');
	pieces[12] = createPiece(KING,   WHITE, 4, 0, 0, 'K');
	pieces[13] = createPiece(BISHOP, WHITE, 5, 0, 3, 'B');
	pieces[14] = createPiece(KNIGHT, WHITE, 6, 0, 3, 'N');
	pieces[15] = createPiece(ROOK,   WHITE, 7, 0, 5, 'R');

	for (int i = 16; i < 24; i++) {
    pieces[i] = createPiece(PAWN,  BLACK, i - 16, black_height - 1, 1, 'P');
	}

	pieces[24]  = createPiece(ROOK,   BLACK, 0, black_height, 5, 'r');
	pieces[25]  = createPiece(KNIGHT, BLACK, 1, black_height, 3, 'n');
	pieces[26] = createPiece(BISHOP, BLACK, 2, black_height, 3, 'b');
	pieces[27] = createPiece(QUEEN,  BLACK, 3, black_height, 9, 'q');
	pieces[28] = createPiece(KING,   BLACK, 4, black_height, 0, 'k');
	pieces[29] = createPiece(BISHOP, BLACK, 5, black_height, 3, 'b');
	pieces[30] = createPiece(KNIGHT, BLACK, 6, black_height, 3, 'n');
	pieces[31] = createPiece(ROOK,   BLACK, 7, black_height, 5, 'r');

  printf("pieces have been initialized.\n");
}

/* Fix this junk vvvvv
void killPiece(Piece* pieces, int* num_pieces, Piece* piece_to_remove) {
  int piece_index = -1;
:QUEEN
  for (int i = 0; i < *num_pieces; i++) {
    if (pieces[i] == piece_to_remove) {
      piece_index = i;
      break;
    }
  }

  if (piece_index != -1) {
    free(pieces[piece_index]);

    for (int i = piece_index; i < *num_pieces - 1; i++) {
      pieces[i] = pieces[i+1];
    }
    (*num_pieces)--;
  }
}
*/
