#include "game.h"
#include "util.h"
#include <stdio.h>

Game new_game(const Player * player_one, const Player * player_two) {
  Game game = { .gameboard = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, .number_of_turns = 1 };
  game.player_one = *player_one;
  game.player_two = *player_two;
  return game;
}

void print_gameboard(const Game * game) {
    for (size_t i = 0; i < GAME_GAMEBOARD_SIZE; i++) {
      printf("|  %c  |", game->gameboard[i]);
      if ((i + 1) % 3 == 0) {
        printf("\n");
        if ((i + 1) < GAME_GAMEBOARD_SIZE - 2) {
          printf("---------------------\n");
        }
      }
    }
    printf("\n");
}

bool is_cell_empty(const Game * game, size_t index) {
  return game->gameboard[index] == ' ';
}

void place_symbol_on_gameboard(Game * game) {
  size_t index = 0;
  do {
    prompt_user_for_input("Enter Cell Index: ", " %d", &index);
  } while(index < 1 || index > GAME_GAMEBOARD_SIZE || !is_cell_empty(game, (index - 1)));
  game->gameboard[index - 1] = game->active_player->symbol;
}

bool is_game_won(const Game * game) {
  // Check Rows
  for (size_t row = 0; row < 3; row++) {
    size_t offset = 3 * row;

    char cell_start = game->gameboard[0 + offset];
    char cell_middle = game->gameboard[1 + offset];
    char cell_end = game->gameboard[2 + offset];

    if (cell_start != ' ' && cell_start == cell_middle && cell_middle == cell_end) { 
      return true; 
    }
  }

  // Check Columns
  for (size_t column = 0; column < 3; column++) {
    char cell_start = game->gameboard[column];
    char cell_middle = game->gameboard[column + 3];
    char cell_end = game->gameboard[column + 6];
    
    if (cell_start != ' ' && cell_start == cell_middle && cell_middle == cell_end) {
      return true;
    }
  }
  
  // Top Left Diagonal
  {
    char cell_start = game->gameboard[0];
    char cell_middle = game->gameboard[4];
    char cell_end = game->gameboard[8];

    if (cell_start != ' ' && cell_start == cell_middle && cell_middle == cell_end) {
      return true;
    }
  }

  // Top Right Diagonal
  {
    char cell_start = game->gameboard[2];
    char cell_middle = game->gameboard[4];
    char cell_end = game->gameboard[6];

    if (cell_start != ' ' && cell_start == cell_middle && cell_middle == cell_end) {
      return true;
    }
  }

  return false;
}


