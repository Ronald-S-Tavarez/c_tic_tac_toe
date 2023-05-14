#include "player.h"
#include "util.h"
#include <string.h>
#include <stdio.h>

Player new_player(const char * alias, char symbol) {
  Player player;
  strcpy_s(player.alias, PLAYER_ALIAS_LENGTH, alias);
  player.symbol = symbol;
  return player;
}

Player new_player_from_input(void) { 
  char player_alias_buffer [PLAYER_ALIAS_LENGTH];
  char player_symbol_buffer;
  prompt_user_for_input("Enter player one alias: ", " %s", player_alias_buffer);
  prompt_user_for_input("Enter player one symbol: ", " %c", &player_symbol_buffer);
  return new_player(player_alias_buffer, player_symbol_buffer);
}

void print_player(const Player * player, bool is_player_one) {
  char player_string_buffer [PLAYER_STRING_BUFFER_SIZE];
  sprintf(player_string_buffer, "Alias: %s, Symbol: %c", player->alias, player->symbol);
  char * player_order_buffer = (is_player_one) ? "One" : "Two";
  printf("Player %s: %s\n", player_order_buffer, player_string_buffer);
}
