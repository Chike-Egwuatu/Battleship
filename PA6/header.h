//guard code
#ifndef HEADER_H
#define HEADER_H

#include <stdio.h> // standard libray
#include <stdlib.h> // rand(), srand()
#include <time.h> // time()
#include <math.h>

#define NUM_ROWS 10
#define NUM_COLS 10

typedef struct game_stats
{
	int shots;
	int miss;
	int total_shots;
	int sunk_ships;
}game_stats;


void welcome_screen(void);
void init_board(char board[][NUM_COLS], int rows, int cols);
void print_board(char board[][NUM_COLS], int rows, int cols);
void place_ships_menu(void);
int select_who_starts_first(void);
void manually_place_ships_on_board(char board[][NUM_COLS], char ships, int size);
void randomly_place_ships_on_board(char board[][NUM_COLS], char ships, int size);
void manually_place_ships(char board[][NUM_COLS]);
void randomly_place_ships(char board[][NUM_COLS]);
void check_shot(char board[][NUM_COLS], char shot_board[][NUM_COLS], char pl_sunkships[5], game_stats *player);
void computer_check_shot(char board[][NUM_COLS], char shot_board[][NUM_COLS], char pl_sunkships[5], game_stats *computer);
void check_if_sunk_ship(char pl_sunkships[5], char check_win[5], game_stats *player);
void Determine_winner(void);
void Determine_winner_computer(void);
void print_stats(game_stats *player, game_stats *computer);


#endif