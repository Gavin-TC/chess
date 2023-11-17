#include <stdio.h>

#include <player.h>
#include <board.h>
#include <constants.h>

int main(void) {
  bool is_white = true;
  bool game_running = true;
  bool quit = false;
  char** board = setupBoard(is_white); 
  Piece** pieces = setupPieces(is_white);

  bool valid_move = false;
  char* move = NULL;
  char* bot_move = NULL;

  printf("\n");

  while (game_running) {
    valid_move = false;
    is_white = true;

    while (valid_move == false) {
      drawBoard(board, pieces);  //  seg fault occurs here after breaking the loop with 'q';
      move = getPlayerMove();  // get players move
      valid_move = evaluateMove(is_white, move, board, pieces);  // check if players move is valid
      printf("%d\n", valid_move);

      if (move[0] == 'q') {
        quit = true;
        break;
      }
    }
    if (quit) {
      freeBoard(board);
      break;
    }
    
    is_white = false;
    valid_move = false;
    while (valid_move == false) {
      drawBoard(board, pieces);  //  seg fault occurs here after breaking the loop with 'q';
      move = getPlayerMove();  // get players move
      valid_move = evaluateMove(is_white, move, board, pieces);  // check if players move is valid
      printf("%d\n", valid_move);

      if (move[0] == 'q') {
        quit = true;
        break;
      }
    }
    if (quit) {
      freeBoard(board);
      game_running = false;
    }
  }

  return 0;
}
