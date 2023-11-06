#include <stdbool.h>
#include <stdio.h>

#include <board.h>
#include <constants.h>
#include <init.h>

void setupPieces(char** board, bool is_player_first);
void freeBoard(char** board);

// returns a board[]
char** createBoard(bool is_player_first) {
  char** new_board = (char**) malloc(BOARD_HEIGHT * sizeof(char*));

  // handle malloc error
  if (new_board == NULL) return NULL;

  // make the checker pattern
  for (int y = 0; y < BOARD_HEIGHT; y++) {
    new_board[y] = (char*) malloc(BOARD_WIDTH * sizeof(char));

    // handle malloc error, again
    if (new_board[y] == NULL) freeBoard(new_board);

    for (int x = 0; x < BOARD_WIDTH; x++) {
       new_board[y][x] = x % 2 == y % 2 ? ' ' : '#';
    }
  }
  
  // initialize pieces.
  initialize(is_player_first);

  return new_board;
}

void drawBoard(char** board) {
  //printf("\033[?251");  // hides cursor
  //printf("\033[H");  // moves cursor to the top left 
  for (int y = 0; y < BOARD_HEIGHT; y++) {
    for (int x = 0; x < BOARD_WIDTH; x++) {
      printf("%c", board[y][x]);
      
      for (int i = 0; i < sizeof(pieces) / sizeof(pieces[0]); i++) {
        if (pieces[i]->pos.x == x && pieces[i]->pos.y == y) {
          printf("%c", pieces[i]->chr);
        }
      }
    }
    printf("\n");
  }
}



void freeBoard(char** board) {
  for (int y = 0; y < BOARD_HEIGHT; y++) { free(board[y]); }
  free(board);
}
