#include <stdio.h>

#include <player.h>
#include <board.h>
#include <constants.h>

const bool game_running = true;

int main(void) {
  char** board = setupBoard(is_player_first); 
  Piece* pieces = setupPieces(is_player_first);
 
  printf("\n");

  while (game_running) {
    drawBoard(board, pieces);
    char* move = getPlayerMove();  // get players move
    bool valid_move = evaluateMove(move);  // check if players move is valid
    
    while (!valid_move) {  // while it's not valid, get another move
      char* move = getPlayerMove();
      bool valid_move = evaluateMove(move);
    }
    movePiece(board, pieces, move);  // finally, move piece.
  }

  return 0;
}
