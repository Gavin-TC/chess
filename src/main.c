#include <stdio.h>

#include <player.h>
#include <bot.h>
#include <board.h>
#include <constants.h>

int main(void) {
  bool game_running = true;
  char** board = setupBoard(is_player_first); 
  Piece** pieces = setupPieces(is_player_first);
 
  printf("\n");

  while (game_running) {
    drawBoard(board, pieces);
    char* move = getPlayerMove();  // get players move
    if (move[0] == 'q') {
      freeBoard(board);
      break;
    }
    bool valid_move = evaluateMove(move, board, pieces);  // check if players move is valid
  }

  return 0;
}
