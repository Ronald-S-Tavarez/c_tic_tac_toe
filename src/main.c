#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "util.h"
#include "player.h"
#include "game.h"

bool poll_menu_input(void);

int main(int argc, char ** argv) {
  bool user_choice = poll_menu_input();
  if (user_choice) {
    Player player_one = new_player_from_input();
    Player player_two = new_player_from_input();
    Game game = new_game(&player_one, &player_two);

    do {
      system("cls");
      print_player(&game.player_one, true);
      print_player(&game.player_two, false);
      print_gameboard(&game);

      game.active_player = (game.number_of_turns % 2 == 0) ? &game.player_two : &game.player_one;
      place_symbol_on_gameboard(&game);
      print_gameboard(&game);

      if (is_game_won(&game)) {
        printf("Victory in %d Turns!\n", game.number_of_turns);
        printf("Victor: %s\n", game.active_player->alias);
        break;
      }
      game.number_of_turns++;
      continue;
    } while(true);
  }
  printf("Exiting program... Goodbye.\n");
  return EXIT_SUCCESS;
}

bool poll_menu_input(void) {
  char user_input = 'A';
  do {
    system("cls");
    printf("Y | Play Game.\n");
    printf("N | Exit Program.\n");
    prompt_user_for_input("Enter Menu Option: ", " %c", &user_input);
  } while (
      user_input != 'Y' && 
      user_input != 'y' && 
      user_input != 'N' && 
      user_input != 'n');

  if (user_input == 'Y' || user_input == 'y') {
    return true;
  } else {
    return false;
  }
} 

