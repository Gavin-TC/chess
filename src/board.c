#include <stdbool.h>
#include <stdio.h>
#include <wchar.hDTH * sizeof(wchar_t));

    // handle malloc error, again
    if (new_board[y] == NULL) freeBoard(new_board);

    for (int x = 0; x < BOARD_WIDTH; x++) {
       new_board[y][x] = x % 2 == y % 2 ? L'▓' : L'░';
    }
  }
  
  // add the corret pieces to the correct spot. 
  setupPieces(new_board, is_player_first);

  return new_board;
}

void setupPieces(wchar_t** board, bool is_player_first) {
  // player is white, so white is at the bottom
  if (is_player_first) {
    board[BOARD_HEIGHT - 1][0] = wRook.chr;
    board[BOARD_HEIGHT - 1][1] = wKnight.chr;
    board[BOARD_HEIGHT - 1][2] = wBishop.chr;
    board[BOARD_HEIGHT - 1][3] = wQueen.chr;
    board[BOARD_HEIGHT - 1][4] = wKing.chr;
    board[BOARD_HEIGHT - 1][5] = wBishop.chr;
    board[BOARD_HEIGHT - 1][6] = wKnight.chr;
    board[BOARD_HEIGHT - 1][7] = wRook.chr;
    
    for (int i = 0; i < BOARD_WIDTH; i++) {
      board[BOARD_HEIGHT - 1][i] = wPawn.chr;
    }
  
    board[0][0] = bRook.chr;
    board[0][1] = bKnight.chr;
    board[0][2] = bBishop.chr;
    board[0][3] = bQueen.chr;
    board[0][4] = bKing.chr;
    board[0][5] = bBishop.chr;
    board[0][6] = bKnight.chr;
    board[0][7] = bRook.chr;
    
    for (int i = 0; i < BOARD_WIDTH; i++) {
      board[0][i] = bPawn.chr;
    }
  } else {
    board[BOARD_HEIGHT - 1][0] = bRook.chr;
    board[BOARD_HEIGHT - 1][1] = bKnight.chr;
    board[BOARD_HEIGHT - 1][2] = bBishop.chr;
    board[BOARD_HEIGHT - 1][3] = bQueen.chr;
    board[BOARD_HEIGHT - 1][4] = bKing.chr;
    board[BOARD_HEIGHT - 1][5] = bBishop.chr;
    board[BOARD_HEIGHT - 1][6] = bKnight.chr;
    board[BOARD_HEIGHT - 1][7] = bRook.chr;

    for (int i = 0; i < BOARD_WIDTH; i++) {
      board[BOARD_HEIGHT - 1][i] = bPawn.chr;
    }

    board[0][0] = wRook.chr;
    board[0][1] = wKnight.chr;
    board[0][2] = wBishop.chr;
    board[0][3] = wQueen.chr;
    board[0][4] = wKing.chr;
    board[0][5] = wBishop.chr;
    board[0][6] = wKnight.chr;
    board[0][7] = wRook.chr;

    for (int i = 0; i < BOARD_WIDTH; i++) {
      board[0][i] = wPawn.chr;
    }
  }
}

void drawBoard(wchar_t** board) {
  for (int y = 0; y < BOARD_HEIGHT; y++) {
    for (int x = 0; x < BOARD_WIDTH; x++) {
      wprintf("%lc", board[y][x]);
    }
  }
}

void freeBoard(wchar_t** board) {
  for (int y = 0; y < BOARD_HEIGHT; y++) { free(board[y]); }
  free(board);
}
