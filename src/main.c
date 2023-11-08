#include <stdio.h>

#include <player.h>
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
    bool valid_move = evaluateMove(move, board, pieces);  // check if players move is valid
    
    //while (!valid_move) {  // while it's not valid, get another move
    //  char* move = getPlayerMove();
    //  bool valid_move = evaluateMove(move, pieces);
    //}
    //movePiece(board, pieces, move);  // finally, move piece.
    //game_running = false;
  
  }

  return 0;
}
