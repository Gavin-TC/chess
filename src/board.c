#include <board.h>

void freeBoard(char** board);

// returns a board[]
char** setupBoard(bool is_player_first) {
  char** new_board = (char**) malloc(BOARD_HEIGHT * sizeof(char*));
  if (new_board == NULL) return NULL;

  // make the checker pattern
  for (int y = 0; y < BOARD_HEIGHT; y++) {
    new_board[y] = (char*) malloc(BOARD_WIDTH * sizeof(char));
    if (new_board[y] == NULL) freeBoard(new_board);

    for (int x = 0; x < BOARD_WIDTH; x++) {
       new_board[y][x] = x % 2 == y % 2 ? ' ' : '#';
    }
  }

  return new_board;
}

Piece* setupPieces(bool is_player_first) {
  Piece* pieces = (Piece*) malloc(32 * sizeof(Piece));

  int white_height = is_player_first ? (BOARD_HEIGHT - 1) : 0;
  int white_pawn_height = (white_height - 1 > 0) ? (white_height - 1) : 1;

  int black_height = (white_height == (BOARD_HEIGHT - 1)) ? 0 : (BOARD_HEIGHT - 1);
  int black_pawn_height = (black_height - 1 > 0) ? (black_height - 1) : 1;

	for (int i = 0; i < 8; i++) {
	  pieces[i] = (Piece) { PAWN,  WHITE, {i, white_pawn_height}, 1, 'P' };
	}

	pieces[8]  = (Piece) { ROOK,   WHITE, {0, white_height}, 5, 'R' };
	pieces[9]  = (Piece) { KNIGHT, WHITE, {1, white_height}, 3, 'N' };
	pieces[10] = (Piece) { BISHOP, WHITE, {2, white_height}, 3, 'B' };
	pieces[11] = (Piece) { QUEEN,  WHITE, {3, white_height}, 9, 'Q' };
	pieces[12] = (Piece) { KING,   WHITE, {4, white_height}, 0, 'K' };
	pieces[13] = (Piece) { BISHOP, WHITE, {5, white_height}, 3, 'B' };
	pieces[14] = (Piece) { KNIGHT, WHITE, {6, white_height}, 3, 'N' };
	pieces[15] = (Piece) { ROOK,   WHITE, {7, white_height}, 5, 'R' };
  
	for (int i = 16; i < 24; i++) {
    pieces[i] = (Piece) { PAWN,  BLACK, {i - 16, black_pawn_height}, 1, 'p'};
	}

	pieces[24] = (Piece) { ROOK,   BLACK, {0, black_height}, 5, 'r' };
	pieces[25] = (Piece) { KNIGHT, BLACK, {1, black_height}, 3, 'n' };
	pieces[26] = (Piece) { BISHOP, BLACK, {2, black_height}, 3, 'b' };
	pieces[27] = (Piece) { QUEEN,  BLACK, {3, black_height}, 9, 'q' };
	pieces[28] = (Piece) { KING,   BLACK, {4, black_height}, 0, 'k' };
	pieces[29] = (Piece) { BISHOP, BLACK, {5, black_height}, 3, 'b' };
	pieces[30] = (Piece) { KNIGHT, BLACK, {6, black_height}, 3, 'n' };
	pieces[31] = (Piece) { ROOK,   BLACK, {7, black_height}, 5, 'r' };

  return pieces;  
}

void drawBoard(char** board, Piece* pieces) {
  char** print_board = board;

  for (int y = 0; y < BOARD_HEIGHT; y++) {
    for (int x = 0; x < BOARD_WIDTH; x++) {
      char piece_char = print_board[y][x];

      for (int i = 0; i < 32; i++) {
        if (pieces[i].pos.x == x && pieces[i].pos.y == y) {
          piece_char = pieces[i].chr;
          break;
        } 
      }
      print_board[y][x] = piece_char;
      printf("%c", print_board[y][x]);
    }
    printf("\n");
  }
}

bool evaluateMove(char* move) {
  char piece[2];  // e.g. [a1]b2
  char to_move[2];  // e.g. a1[b2]
 
  puts(move);

  strncpy(piece, move, 2);
  strncpy(to_move, move + 2, 2);
 
  puts(piece);
  puts(to_move);

  return false;
}

// this assumes the move is valid
// stupid, i know
void movePiece(char** board, Piece* pieces, char* move) {

}

void freeBoard(char** board) {
  for (int y = 0; y < BOARD_HEIGHT; y++) { free(board[y]); }
  free(board);
}
