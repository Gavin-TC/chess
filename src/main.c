#include <stdio.h>

#include <player.h>
#include <board.h>
#include <constants.h>
#include <init.h>

int main(void) {
  char** board = createBoard(is_player_first); 
  
  drawBoard(board);

  return 0;
}
