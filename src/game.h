#ifndef GAME_H
#define GAME_H
#include "player.h"
#include <stdbool.h>
#include <stddef.h>

#define GAME_GAMEBOARD_SIZE 9

typedef struct Game {
  Player player_one;
  Player player_two;
  Player * active_player;
  size_t number_of_turns;
  char gameboard [GAME_GAMEBOARD_SIZE];
} Game;

Game new_game(const Player * player_one, const Player * player_two);
void print_gameboard(const Game * game);
bool is_cell_empty(const Game * game, size_t index);
void place_symbol_on_gameboard(Game * game);
bool is_game_won(const Game * game);

#endif // !GAME_H

