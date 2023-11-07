#include <player.h>

bool is_player_first = true;

char* getPlayerMove(void) {
  int buffer_size = 5; // 4 chars + null terminator
  char* move = (char*) malloc(buffer_size);

  printf("Enter move: ");

  if (fgets(move, buffer_size, stdin) != NULL) { printf("You entered: %s\n", move); }
  else { printf("Error reading input.\n"); }

  return (move != NULL) ? move : NULL;
}
