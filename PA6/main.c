/*
Programmer: Chike Egwuatu
Class: Cpts 121, Fall 2017, TA:Alexis G.
Programmer Assignment: Pa5
Date: October 24, 2017
Description: This assignment is to construct the game battleship. Consturct arrays and loops
and construct if statements.
*/

#include "header.h"

int main(void)
{
	srand(time(NULL));
	int menu_option = 0, p1 = 0, p2 = 0, player_turn = 0, turns = 0;
	char p1_board[NUM_ROWS][NUM_COLS] = { { '~' } }, p2_board[NUM_ROWS][NUM_COLS] = { { '~' } };
	char hit_miss_board1[NUM_ROWS][NUM_COLS] = { { '~' } }, hit_miss_board2[NUM_ROWS][NUM_COLS] = { { '~' } };
	char track_ship1[5] = { NULL }, track_ship2[5] = { NULL }; // array for check if sunk
	char winner_1[5] = { NULL }, winner_2[5] = { NULL }; // array for check if sunk

	struct game_stats player, computer; // struct for player stats 
	player.shots = 0;
	player.miss = 0;
	player.total_shots = 0;
	player.sunk_ships = 0;

	computer.shots = 0;
	computer.miss = 0;
	computer.total_shots = 0;
	computer.sunk_ships = 0;

	welcome_screen(); // welcome screen displaying rules
	system("pause");
	system("cls"); // clear screen
	place_ships_menu(); // Prompt the user to either enter the ships manually or randomlly have the ships placed
	printf("\nEnter 1 or 2 and press enter: "); // print statement
	scanf("%d", &menu_option); // scan statment to enter 1 or 2
	if (menu_option == 1) // if user enters 1
	{
		system("cls");
		init_board(p1_board, NUM_ROWS, NUM_COLS); // create game board
		print_board(p1_board, NUM_ROWS, NUM_COLS);
		manually_place_ships(p1_board); // The user manually places the ships
		system("pause");
		system("cls");
	}
	else
	{
		init_board(p1_board, NUM_ROWS, NUM_COLS); // Create game board
		system("cls"); // clear screen because user doesnt need to see this just the final board
		randomly_place_ships(p1_board); // display the board and the randomlly placed ships
		system("pause");
		system("cls");
		printf("Player 1 Board has been created.\n\n");
		print_board(p1_board, NUM_ROWS, NUM_COLS); // print the board for the player
		printf("\n");
		system("pause");
		system("cls");
	}
	init_board(p2_board, NUM_ROWS, NUM_COLS);
	randomly_place_ships(p2_board);
	
	// This is when the game starts and it switches from cuomputer to player
		player_turn = select_who_starts_first(); // function to decide which player goes firsts
		if (player_turn == 0) // if the function equals 0 player 1 goes first
		{
			printf("PLAYER 1 IS RANDOMLLY CHOSEN TO GO FIRST!\n\n"); // print
			system("pause");
			system("cls");
		}
		else if (player_turn == 1) // if the function equals 1 then the computer goes first
		{
			printf("THE COMPUTER IS RANDOMLLY CHOSEN TO GO FIRST!\n\n"); // print
			system("pause");
			system("cls");
		}
	
		init_board(hit_miss_board2, NUM_ROWS, NUM_COLS); // initialize shot board for player 1
		//init_board(hit_miss_board1, NUM_ROWS, NUM_COLS);

			
			while (turns == 0)
			{
				if ((winner_1[0] == 1) && (winner_1[1] == 1) && (winner_1[2] == 1) && (winner_1[3] == 1) && (winner_1[4] == 1)) // check to see if all ships are sunk which results in the player 1 winning
				{
					Determine_winner(); // print that player 1 has won the game
					print_stats(&player, &computer);
					return 0; // end the game
				}
				else if ((winner_2[0] == 1) && (winner_2[1] == 1) && (winner_2[2] == 1) && (winner_2[3] == 1) && (winner_2[4] == 1)) // check to see if the computer sunk all ships
				{
					Determine_winner_computer();// display that the computer has won the game,
					print_stats(&player, &computer);
					return 1; // end the game
				}
				// This is when the game starts and it switches from cuomputer to player
				if (player_turn == 0) // Start player 1 turn
				{
					//play game
					printf("Player 1 turn\n");
					printf("\n");
					printf("Player 1 board\n");
					print_board(p1_board, NUM_ROWS, NUM_COLS); // Print player 1 board
					printf("\n");
					printf("Computers board\n");
					check_shot(p2_board, hit_miss_board2, track_ship1, &player); // Check if the shot hit or missed, or if they have to shoot again. And also print the shot board of the Computer board.
					check_if_sunk_ship(track_ship1, winner_1, &player); // Determine if the ship is sunk and print to the program.
					system("pause");

					player_turn = 1; // set player_turn to 1 which results in the computer having a turn
				}
				else if (player_turn == 1) // start the computer turn
				{
					//play game
					printf("Computer turn\n");
					computer_check_shot(p1_board, hit_miss_board1, track_ship2, &computer); // display where the computer shot and if its a valid shot
					check_if_sunk_ship(track_ship2, winner_2, &computer); // check to see if the ships are sunk
					system("pause");
					player_turn = 0; // set player_turn to 0 which results in player 1 having a turn
				}
				system("cls");
			}

	return 0;
}