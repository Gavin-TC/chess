#include <stdio.h>
#include <wchar.h>

#include <player.h>
#include <board.h>
#include <constants.h>

int main(void) {
  wchar_t** board = createBoard(is_player_first); 

  drawBoard(board);

  return 0;
}
