#include <player.h>

char* getPlayerMove(void) {
  int buffer_size = 6; // 4 chars + newline + null terminator
  char* move = (char*)malloc(buffer_size);

  printf("Enter move: ");
  if (fgets(move, buffer_size, stdin) != NULL) {
      // Remove the trailing newline character if it exists
      size_t len = strlen(move);
      if (len > 0 && move[len - 1] == '\n') {
        move[len - 1] = '\0';
      }
     printf("You entered: %s\n", move);
  } else {
    printf("Error reading input.\n");
  }
  printf("\033[H\033[J");
  return move;
}

