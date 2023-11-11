#include <board.h>

void freeBoard(char** board);
int letterToNumberFile(char* rank);
void movePiece(Piece** pieces, Piece* chosen_piece, int move_file, int move_rank);

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

Piece** setupPieces(bool is_player_first) {
  Piece** pieces = calloc(32, sizeof(Piece*));

  for (int i = 0; i < 32; i++) {
    pieces[i] = calloc(32, sizeof(Piece));
  }

  int white_height = is_player_first ? (BOARD_HEIGHT - 1) : 0;
  int white_pawn_height = (white_height - 1 > 0) ? (white_height - 1) : 1;

  int black_height = (white_height == (BOARD_HEIGHT - 1)) ? 0 : (BOARD_HEIGHT - 1);
  int black_pawn_height = (black_height - 1 > 0) ? (black_height - 1) : 1;

	for (int i = 0; i < 8; i++) {
	  pieces[i]->type = PAWN; 
    pieces[i]->color = WHITE;
    pieces[i]->pos.x = i;
    pieces[i]->pos.y = white_pawn_height;
    pieces[i]->value = 1;
    pieces[i]->chr = 'P';
	}

  pieces[8]->type = ROOK;
  pieces[8]->color = WHITE;
  pieces[8]->pos.x = 0;
  pieces[8]->pos.y = white_height;
  pieces[8]->value = 5;
  pieces[8]->chr = 'R';

  pieces[9]->type = KNIGHT;
  pieces[9]->color = WHITE;
  pieces[9]->pos.x = 1;
  pieces[9]->pos.y = white_height;
  pieces[9]->value = 3;
  pieces[9]->chr = 'N';

  pieces[10]->type = BISHOP;
  pieces[10]->color = WHITE;
  pieces[10]->pos.x = 2;
  pieces[10]->pos.y = white_height;
  pieces[10]->value = 3;
  pieces[10]->chr = 'B';

  pieces[11]->type = QUEEN;
  pieces[11]->color = WHITE;
  pieces[11]->pos.x = 3;
  pieces[11]->pos.y = white_height;
  pieces[11]->value = 9;
  pieces[11]->chr = 'Q';

  pieces[12]->type = KING;
  pieces[12]->color = WHITE;
  pieces[12]->pos.x = 4;
  pieces[12]->pos.y = white_height;
  pieces[12]->value = 0;
  pieces[12]->chr = 'K';

  pieces[13]->type = BISHOP;
  pieces[13]->color = WHITE;
  pieces[13]->pos.x = 5;
  pieces[13]->pos.y = white_height;
  pieces[13]->value = 3;
  pieces[13]->chr = 'B';

  pieces[14]->type = KNIGHT;
  pieces[14]->color = WHITE;
  pieces[14]->pos.x = 6;
  pieces[14]->pos.y = white_height;
  pieces[14]->value = 3;
  pieces[14]->chr = 'N';

  pieces[15]->type = ROOK;
  pieces[15]->color = WHITE;
  pieces[15]->pos.x = 7;
  pieces[15]->pos.y = white_height;
  pieces[15]->value = 5;
  pieces[15]->chr = 'R';
  
  for (int i = 16; i < 24; i++) {
    //pieces[i] = (Piece*) { PAWN,  BLACK, {i - 16, black_pawn_height}, 1, 'p'};
	  pieces[i]->type = PAWN; 
    pieces[i]->color = BLACK;
    pieces[i]->pos.x = i - 16;
    pieces[i]->pos.y = black_pawn_height;
    pieces[i]->value = 1;
    pieces[i]->chr = 'p';
	}

  pieces[24]->type = ROOK;
  pieces[24]->color = BLACK;
  pieces[24]->pos.x = 0;
  pieces[24]->pos.y = black_height;
  pieces[24]->value = 5;
  pieces[24]->chr = 'r';

  pieces[25]->type = KNIGHT;
  pieces[25]->color = BLACK;
  pieces[25]->pos.x = 1;
  pieces[25]->pos.y = black_height;
  pieces[25]->value = 3;
  pieces[25]->chr = 'n';

  pieces[26]->type = BISHOP;
  pieces[26]->color = BLACK;
  pieces[26]->pos.x = 2;
  pieces[26]->pos.y = black_height;
  pieces[26]->value = 3;
  pieces[26]->chr = 'b';

  pieces[27]->type = QUEEN;
  pieces[27]->color = BLACK;
  pieces[27]->pos.x = 3;
  pieces[27]->pos.y = black_height;
  pieces[27]->value = 9;
  pieces[27]->chr = 'q';

  pieces[28]->type = KING;
  pieces[28]->color = BLACK;
  pieces[28]->pos.x = 4;
  pieces[28]->pos.y = black_height;
  pieces[28]->value = 0;
  pieces[28]->chr = 'k';

  pieces[29]->type = BISHOP;
  pieces[29]->color = BLACK;
  pieces[29]->pos.x = 5;
  pieces[29]->pos.y = black_height;
  pieces[29]->value = 3;
  pieces[29]->chr = 'b';

  pieces[30]->type = KNIGHT;
  pieces[30]->color = BLACK;
  pieces[30]->pos.x = 6;
  pieces[30]->pos.y = black_height;
  pieces[30]->value = 3;
  pieces[30]->chr = 'n';

  pieces[31]->type = ROOK;
  pieces[31]->color = BLACK;
  pieces[31]->pos.x = 7;
  pieces[31]->pos.y = black_height;
  pieces[31]->value = 5;
  pieces[31]->chr = 'r';

  return pieces;  
}

void drawBoard(char** board, Piece** pieces) {
  char print_board[BOARD_HEIGHT][BOARD_WIDTH];

  for (int y = 0; y < BOARD_HEIGHT; y++) {
    for (int x = 0; x < BOARD_WIDTH; x++) {
      print_board[y][x] = board[y][x];
    }
  }

  for (int i = 0; i < 32; i++) {
    int x = pieces[i]->pos.x;
    int y = pieces[i]->pos.y;
    char piece_char = pieces[i]->chr;

    print_board[y][x] = piece_char;
  }

  for (int y = 0; y < BOARD_HEIGHT; y++) {
    printf("%d ", 8 - y);
    for (int x = 0; x < BOARD_WIDTH; x++) {
      printf("%c", print_board[y][x]);
    }
    printf("\n");
  }
  printf("\n  abcdefgh\n");
}

bool evaluateMove(char* move, char** board, Piece** pieces) {
  // file is x, rank is y;
  char file_ch1[2];  // [a]1b1
  int file1 = 0;  // [a] converted to index
  char rank_ch1[2];  // a[1]b1
  int rank1 = 0;  // [1] convert from char to int (index)

  char file_ch2[2];  // a1[b]1
  int file2 = 0;  // [b] converted to index
  char rank_ch2[2];  // a1b[1]
  int rank2 = 0;  // [1] converted from char to int (index)

  // x indices
  strncpy(file_ch1, move, 2);
  file_ch1[1] = '\0';
  strncpy(file_ch2, move + 2, 2);
  file_ch2[1] = '\0';

  // y indices
  strncpy(rank_ch1, move + 1, 2);
  rank_ch1[1] = '\0';
  strncpy(rank_ch2, move + 3, 2);
  rank_ch2[1] = '\0';

  //rank1 = letterToNumberFile(rank_ch1);
  //rank2 = letterToNumberFile(rank_ch2);
  file1 = letterToNumberFile(file_ch1);
  file2 = letterToNumberFile(file_ch2);

  // if there was an error converting:
  if (file1 == -1 || file2 == -1) return false;

  rank1 = (int) 8 - (rank_ch1[0] - '0');
  rank2 = (int) 8 - (rank_ch2[0] - '0');

  // if anything is out of bounds
  if (!(file1 >= 0 && file1 < 8) ||
      !(file2 >= 0 && file2 < 8) ||
      !(rank1 >= 0 && rank1 < 8) ||
      !(rank2 >= 0 && rank2 < 8)) {
    printf("One or more of the coordinates are out of bounds! (e.g. a9i0 = bad!)\n");
    return false;
  } else {
    printf("Piece move was x: %d - y: %d\n", file2, rank2);
  }

  // player is selecting the same piece
  if (file1 == file2 && rank1 == rank2) return false;

  Piece* chosen_piece = NULL;
  Piece* target_piece = NULL;  // the piece that the player is trying to move onto
  for (int i = 0; i < 32; i++) {
    // Grab the piece that is selected
    if (pieces[i]->pos.x == file1 && pieces[i]->pos.y == rank1) {
      chosen_piece = pieces[i];
    }

    if (pieces[i]->pos.x == file2 && pieces[i]->pos.y == rank2) {
      target_piece = pieces[i];
    } else {
      target_piece = NULL;
    }
  }

  // if we didn't find the piece the player was choosing
  if (chosen_piece == NULL) { 
    printf("There isn't a piece there!\n");
    return false;
  }

  if (chosen_piece->pos.x == file1 && chosen_piece->pos.y == rank1) {
    if (chosen_piece->color == (is_player_first) ? BLACK : WHITE) {
      printf("You cannot the opponents pieces!\n");
      return false;
    }
  }

  if (chosen_piece->pos.x == file2 && chosen_piece->pos.y == rank2) {
    // trying to take/move onto a friendly piece
    if (chosen_piece->color == (is_player_first) ? WHITE : BLACK) {
      printf("You cannot move your piece ontop of your own pieces!\n");
      return false;
    }
  }

  if (isPieceMoveValid(pieces, chosen_piece, target_piece, file1, rank1, file2, rank2)) {
    movePiece(pieces, chosen_piece, file2, rank2);
  }
  return true;
}

int letterToNumberFile(char* file) {
  int number_file = 0;

  switch (file[0]) {
    case 'a':
      number_file = 0;
      break;

    case 'b':
      number_file = 1;
      break;
    
    case 'c':
      number_file = 2;
      break;
    
    case 'd':
      number_file = 3;
      break;
    
    case 'e':
      number_file = 4;
      break;
    
    case 'f':
      number_file = 5;
      break;
    
    case 'g':
      number_file = 6;
      break;
    
    case 'h':
      number_file = 7;
      break;
    
    default:
      return -1;
      printf("There was an error parsing the letter file to an integer.\n");
      break;
  }
  return number_file;
}

void movePiece(Piece** pieces, Piece* chosen_piece, int move_file, int move_rank) {
  for (int i = 0; i < 32; i++) {
    if (pieces[i]->pos.x == move_file && pieces[i]->pos.y == move_rank) {
      pieces[i]->pos.x -= 20;
    }
  }

  chosen_piece->pos.x = move_file;
  chosen_piece->pos.y = move_rank;
}

void freeBoard(char** board) {
  for (int y = 0; y < BOARD_HEIGHT; y++) { free(board[y]); }
  free(board);
}
