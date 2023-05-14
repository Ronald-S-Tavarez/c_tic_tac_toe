#ifndef PLAYER_H
#define PLAYER_H

#include <stdbool.h>

#define PLAYER_ALIAS_LENGTH 20
#define PLAYER_STRING_BUFFER_SIZE 75

typedef struct Player {
  char alias [PLAYER_ALIAS_LENGTH];
  char symbol;
} Player;

Player new_player(const char * alias, char symbol);
Player new_player_from_input(void);
void print_player(const Player * player, bool is_player_one);

#endif // !PLAYER_H
