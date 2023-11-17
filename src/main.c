#include <stdio.h>

#include <player.h>
#include <bot.h>
#include <board.h>
#include <constants.h>

int main(void) {
  bool is_white = true;
  bool game_running = true;
  char** board = setupBoard(is_white); 
  Piece** pieces = setupPieces(is_white);

  bool valid_move = false;
  char* move = NULL;
  char* bot_move = NULL;
 
  printf("\n");

  while (game_running) {
    drawBoard(board, pieces);
    
    char* move = getPlayerMove();  // get players move
    if (move[0] == 'q') {
      freeBoard(board);
      break;
    }
    valid_move = evaluateMove(is_white, move, board, pieces);  // check if players move is valid
    
    // player made a valid move, now the bot plays.
    is_white = false;
    bot_move = getBotMove();
    valid_move = evaluateMove(is_white, bot_move, board, pieces);
  }

  return 0;
}
