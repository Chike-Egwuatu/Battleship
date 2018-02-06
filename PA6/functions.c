#include "header.h"

//welcome screen
void welcome_screen(void) // Welcome screen with rules 
{
	printf("*****Welcome to Battleship*****\n\n");
	printf("Rules Of the Game:\n\n");
	printf("Player 1 is you and Player 2 is the computer\n");
	printf("Your fleet consist of 5 ships.\n");
	printf("The Carrier has 5 cells, Battleship 4 cells, Cruisers 3 cells, Submarine 3 cells, and the Destroyer  2 cells\n");
	printf("Pick a target hole in the gride and choose its location or randomlly have it chosen\n");
	printf("Each target hole has a number (row&column) coordinate on your opponents grid\n");
	printf("Determine each coordinate by findinig its corresponding coordinate on the side and the number on the top of the grid\n");
	printf("If you call out a shot location that is occupied by a ship on your opponents ocean grid, you shot is a hit!\n");
	printf("The program will remind you whether you got a hit or miss on the grid.\n");
	printf("The goal is to hit and sink you opponents ship before they do!\n");
	printf("\nHit enter to start the game! Good Luck!\n\n\n");
}


// initialize the game board to water ('~') symbols
void init_board(char board[][NUM_COLS], int rows, int cols)
{
	int i = 0;
	int row_index = 0, col_index = 0;
	for (row_index = 0; row_index < rows; ++row_index)
	{
		for (col_index = 0; col_index < cols; ++col_index)
		{
			board[row_index][col_index] = '~';
		}
	}

}
//Print the game board
void print_board(char board[][NUM_COLS], int rows, int cols) // print game board
{
	int i = 0;
	int row_index = 0, col_index = 0;
	printf("    0");
	for (i = 1; i < 10; i++) // print column numbers
	{
		printf("   %d", i);
	}
	printf("\n");


	for (row_index = 0; row_index < rows; ++row_index) // print row numbers
	{
		//printf("\n");
		if (row_index == 9)
		{
			printf(" 9|");
		}
		else
		{
			printf(" %d|", row_index);
		}
		for (col_index = 0; col_index < cols; ++col_index)
		{

			printf(" %c |", board[row_index][col_index]);
		}
		printf("\n");

	}

}

// menu for the user to either place ships manually or randomlly place ships
void place_ships_menu(void) // menu to tell the player to select randomlly place ships or manually place ships.
{
	printf("****Please select from the following menu****\n\n");
	printf("1. Enter positions of ships manually.\n");
	printf("2. Allow the program to randomly select positions of ships.\n");

}
// function to determine which player goes first
int select_who_starts_first(void)
{
	return rand() % 2;
}
// function to manually place ships
void manually_place_ships_on_board(char board[][NUM_COLS] , char ships, int size) // Manual Place Ships
{
	int index = 0, row_1 = 0, row_2 = 0, col_1 = 0, col_2 = 0, check_spot = 0;
	int saved_spots[10] = { 0 };
	if (ships == 'C') // If C then prompt to enter 5 spaces
	{
		printf("\nThe ship to place is the aircraft carrier.\n");
		printf("Pick the starting coordinate and ending coordinate for 5 spaces.(You cannot place the ships Vertically!)\n");
		printf("Make sure you enter the points with a space in-between (row column row column): ");
	}
	else if (ships == 'B') // if B then prompt to enter 4 spaces for Battleship
	{
		printf("\nThe ship to place is the Battleship.\n");
		printf("Pick the starting coordinate and ending coordinate for 4 spaces.(You cannot place the ships Vertically!)\n");
		printf("Make sure you enter the points with a space in-between (row column row column): ");
	}
	else if (ships == 'R') // If R then prompt eneter to 3 spaces for Cruiser
	{
		printf("\nThe ship to place is the Cruiser.\n");
		printf("Pick the starting coordinate and ending coordinate for 3 spaces.(You cannot place the ships Vertically!)\n");
		printf("Make sure you enter the points with a space in-between (row column row column): ");
	}
	else if (ships == 'S')// If S then prompt to enter 3 spaces for submarine
	{
		printf("\nThe ship to place is the Submarine.\n");
		printf("Pick the starting coordinate and ending coordinate for 3 spaces.(You cannot place the ships Vertically!)\n");
		printf("Make sure you enter the points with a space in-between (row column row column): ");
	}
	else if (ships == 'D') // If D then prompt user to enter 2 spaces for Destroyer
	{
		printf("\nThe ship to place is the Destroyer.\n");
		printf("Pick the starting coordinate and ending coordinate for 2 spaces.(You cannot place the ships Vertically!)\n");
		printf("Make sure you enter the points with a space in-between (row column row column): ");
	}
	do 
	{
		check_spot = 0; // reset check spot to 0 
		int i = 0;
		scanf("%d%d%d%d", &row_1, &col_1, &row_2, &col_2);
		if (row_1 == row_2)
		{
			
			if (size == abs((col_1 - col_2)) + 1) // Check to see if user entered the right size for Column
			{
				if (col_1 > col_2) 
				{
					for (index = col_1; index >= col_2; index--) // Loop is checking the spots to see if its okay to use, and also register the spots in the new array
					{
						saved_spots[i] = row_1;
						saved_spots[i + 1] = index;
						if (board[row_1][index] != '~') // Checking to see If there is an error or overlap in the spot
						{
							check_spot = 1; // if check_spot equals 1 that means there is an error
							printf("Cannot place ship in occupied spot");
							break;
						}
						i = i + 2; // saving two spots in the array at a time
					}
				}
				else if (col_2 > col_1)
				{
					for (index = col_1; index <= col_2; index++)
					{
						saved_spots[i] = row_2;
						saved_spots[i + 1] = index;
						if (board[row_2][index] != '~')
						{
							check_spot = 1;
							printf("Cannot place ship in occupied spot");
							break;
						}
						i = i + 2;
					}
				}
			}
			else
			{
				check_spot = 1;
				printf("The length of the coordinates are too long/short. Please re-enter: ");

			}

		}

		else if (col_1 == col_2)
		{
			if (size == abs((row_1 - row_2)) + 1)
			{
				if (row_1 > row_2)
				{
					for (index = row_1; index >= row_2; index--)
					{
						saved_spots[i] = index;
						saved_spots[i + 1] = col_2;
						if (board[index][col_2] != '~')
						{
							check_spot = 1;
							printf("Cannot place ship in occupied spot");
							break;
						}
						i = i + 2;

					}
				}
				else if (row_2 > row_1)
				{
					for (index = row_1; index <= row_2; index++)
					{
						saved_spots[i] = index;
						saved_spots[i + 1] = col_1;
						if (board[index][col_1] != '~')
						{
							check_spot = 1;
							printf("Cannot place ship in occupied spot");
							break;
						}
						i = i + 2;
					}
				}
			}
			else
			{
				check_spot = 1;
				printf("The length of the coordinates are too long/short. Please re-enter: ");
			}
		}
		else
		{
			check_spot = 1;
			printf("The length of the coordinates are too long/short. Please re-enter: ");
		}
	} while (check_spot != 0);
	if (check_spot != 1) // If check spot does not equal 1 continue on and allow spots to be saved into array
	{
		for (index = 0; index < (size * 2); index += 2)
		{
			board[saved_spots[index]][saved_spots[index + 1]] = ships;
		}
	}
}
//function to randomlly place ships for player1
void randomly_place_ships_on_board(char board[][NUM_COLS], char ships, int size)
{
	int index = 0, row_1 = 0, row_2 = 0, col_1 = 0, col_2 = 0, check_spot = 0, change = 0;
	int saved_spots[10] = { 0 };
	do
	{
		check_spot = 0; // reset check spot to 0 
		int i = 0;
		change = (rand() % 2); // input change to either have the ships horizontal or vertical.
		if (change == 0)
		{
			col_1 = rand() % (11 - size); // Column 1 has a range from [0,11-shipsize]
			col_2 = col_1 + (size - 1); // Column 2 point is column 1 range plus the (shipsize - 1)
			row_1 = rand() % 10; // Row 1 range is 0 - 9
			row_2 = row_1; // Row 2 range is equal to row 1 because it is horizontal
		}
		else if (change == 1)
		{
			row_1 = rand() % (11 - size); // Row 1 has a range from [0,11-shipsize]
			row_2 = row_1 + (size - 1); // Row 2 point is column 1 range plus the (shipsize - 1)
			col_1= rand() % 10; //  Column 1 range is 0 - 9
			col_2 = col_1; //  Column 2 range is equal to row 1 because it is horizontal
		}
		if (row_1 == row_2)
		{
			if (size == abs((col_1 - col_2)) + 1)
			{
				if (col_1 > col_2)
				{
					for (index = col_1; index >= col_2; index--)
					{
						saved_spots[i] = row_1;
						saved_spots[i + 1] = index;
						if (board[row_1][index] != '~')
						{
							check_spot = 1;
							break;
						}
						i = i + 2;
					}
				}
				else if (col_2 > col_1)
				{
					for (index = col_1; index <= col_2; index++)
					{
						saved_spots[i] = row_2;
						saved_spots[i + 1] = index;
						if (board[row_2][index] != '~')
						{
							check_spot = 1;
							break;
						}
						i = i + 2;
					}
				}
			}
			else
			{
				check_spot = 1;

			}

		}

		else if (col_1 == col_2)
		{
			if (size == abs((row_1 - row_2)) + 1)
			{
				if (row_1 > row_2)
				{
					for (index = row_1; index >= row_2; index--)
					{
						saved_spots[i] = index;
						saved_spots[i + 1] = col_2;
						if (board[index][col_2] != '~')
						{
							check_spot = 1;
							break;
						}
						i = i + 2;

					}
				}
				else if (row_2 > row_1)
				{
					for (index = row_1; index <= row_2; index++)
					{
						saved_spots[i] = index;
						saved_spots[i + 1] = col_1;
						if (board[index][col_1] != '~')
						{
							check_spot = 1;
							break;
						}
						i = i + 2;
					}
				}
			}
			else
			{
				check_spot = 1;
			}
		}
		else
		{
			check_spot = 1;
		}
	} while (check_spot != 0);
	if (check_spot != 1) // If check spot does not equal 1 continue on and allow spots to be saved into array
	{
		for (index = 0; index < (size * 2); index += 2)
		{
			board[saved_spots[index]][saved_spots[index + 1]] = ships; // Retrieving the coordinates and putting them into the array
		}
	}
}

//function to automatically run through and place each type of shit
void manually_place_ships(char board[][NUM_COLS])
{
	//print_board(board, NUM_ROWS, NUM_COLS);
	manually_place_ships_on_board(board , 'C' , 5); // calling function for user to manually place carrier ship
	system("pause"); // stops the program
	system("cls"); // clear program
	print_board(board, NUM_ROWS, NUM_COLS);// prints new board for player to record progress
	manually_place_ships_on_board(board, 'B', 4);
	system("pause");
	system("cls");
	print_board(board, NUM_ROWS, NUM_COLS);
	manually_place_ships_on_board(board, 'R', 3);
	system("pause");
	system("cls");
	print_board(board, NUM_ROWS, NUM_COLS);
	manually_place_ships_on_board(board, 'S', 3);
	system("pause");
	system("cls");
	print_board(board, NUM_ROWS, NUM_COLS);
	manually_place_ships_on_board(board, 'D', 2);
	system("pause");
	system("cls");
	printf("Player 1 Board has been created.\n\n");
	print_board(board, NUM_ROWS, NUM_COLS);
	printf("\n");

}

//function to place ships randomly in order from carrier to destroyer.
void randomly_place_ships(char board[][NUM_COLS])
{
	randomly_place_ships_on_board(board, 'C', 5); // randomly place the carrier
	randomly_place_ships_on_board(board, 'B', 4); // randomly place the battleship
	randomly_place_ships_on_board(board, 'R', 3); // randomly place the cruiser
	randomly_place_ships_on_board(board, 'S', 3); // randomly place the submarine
	randomly_place_ships_on_board(board, 'D', 2); // randomly place the destroyer
}
// Function to check whether a shot was a hit or miss, and prompt the user to enter coordinates to attack ship.
void check_shot(char board[][NUM_COLS], char shot_board[][NUM_COLS], char pl_sunkships[5], game_stats *player)
{
	int row_1 = 0, col_1 = 0, occupied = 0, i = 0;
	print_board(shot_board, NUM_ROWS, NUM_COLS);
	do
	{
		printf("\nEnter coordinates where you would like to hit (row column):"); // tell user to enter coordinates to shoot ship
		scanf("%d%d", &row_1, &col_1); // input row and column where you would like to shoot
		//hit shot
		if (board[row_1][col_1] != '~' && board[row_1][col_1] != 'M' && board[row_1][col_1] != '*') // if board is not equal to tilde or Miss or Hit then the shot is a hit
		{
		
			if (board[row_1][col_1] == 'C') // everytime a shot hits 'C' it is added to the sunk ship array
			{
				pl_sunkships[0]++;

			}
			else if (board[row_1][col_1] == 'B') // everytime a shot hits 'B' it is added to the sunk ship array
			{
				pl_sunkships[1]++;
			}
			else if (board[row_1][col_1] == 'R') // everytime a shot hits 'R' it is added to the sunk ship array
			{
				pl_sunkships[2]++;
			}
			else if (board[row_1][col_1] == 'S')// everytime a shot hits 'S' it is added to the sunk ship array
			{
				pl_sunkships[3]++;
			}
			else // everytime a shot hits 'D' it is added to the sunk ship array
			{
				pl_sunkships[4]++;
			}
			board[row_1][col_1] = '*'; // shot is hit
			printf("Its a Hit!\n"); // prints to user its a hit
			player->shots++;
			player->total_shots++;
			shot_board[row_1][col_1] = '*'; // adds to shot_board array a hit
			return 1;
		}
		//missed shot
		else if (board[row_1][col_1] == '~') // if the coordinates equal a tilde its a miss
		{
			board[row_1][col_1] = 'M'; // print miss on board
			printf("Its a miss!\n");// print miss to user
			player->miss++;
			player->total_shots++;
			shot_board[row_1][col_1] = 'M'; // add M to other array 
			return 0;
		}
		//cannot shoot at coordinate that has already been used
		else if ((board[row_1][col_1] == '*') || (board[row_1][col_1] == 'M')) // if shot has already been used prompts user to shoot again
		{
			printf("Cannot shoot a target that has already been used."); // tells to shoot again
			occupied = 1; // sets occupied equal to 1
		}
	} while (occupied == 1); // if occupied == 1, then go through the loop again
	

}
//function to check shot and see if it is valid
void computer_check_shot(char board[][NUM_COLS], char shot_board[][NUM_COLS], char pl_sunkships[5], game_stats *computer)
{
	int row_1 = 0, col_1 = 0, occupied = 0;
	do
	{
		occupied = 0;
		printf("Computer has taken his turn and shot\n"); // display that its the computer turn
		row_1 = rand() % 10; // computer randomly shoot row
		col_1 = rand() % 10; // computer randomly shoots column
		printf("Computer shot coordinates: %d %d\n", row_1, col_1);
		//hit shot
		if (board[row_1][col_1] != '~' && board[row_1][col_1] != 'M' && board[row_1][col_1] != '*')
		{
				if (board[row_1][col_1] == 'C') 
				{
					pl_sunkships[0]++; // add to the sunk ship array for each cell

				}
				else if (board[row_1][col_1] == 'B')
				{
					pl_sunkships[1]++;
				}
				else if (board[row_1][col_1] == 'R')
				{
					pl_sunkships[2]++;
				}
				else if (board[row_1][col_1] == 'S')
				{
					pl_sunkships[3]++;
				}
				else
				{
					pl_sunkships[4]++;
				}
			board[row_1][col_1] = '*';
			printf("Its a Hit!\n");
			computer->shots++;
			computer->total_shots++;
			shot_board[row_1][col_1] = '*';
			return 1;
		}
		//missed shot
		else if (board[row_1][col_1] == '~')
		{
			board[row_1][col_1] = 'M';
			printf("Its a miss!\n");
			computer->miss++;
			computer->total_shots++;
			shot_board[row_1][col_1] = 'M';
			return 0;
		}
		//cannot shoot at coordinate that has already been used
		else if ((board[row_1][col_1] == '*') || (board[row_1][col_1] == 'M'))
		{
			printf("Computer is shooting at same Target, Computer must re shoot.\n\n");
			occupied = 1;
		}
	} while (occupied == 1);

}
// function to determine if ship is sunk 
void check_if_sunk_ship(char pl_sunkships[5], char check_win[5], game_stats *player)
{
	int i = 0;
		if (pl_sunkships[0] == 5) // if the cell equals a certain number then print that the ship is destroyed and set win array to 1.
		{
			check_win[0] = 1;
			printf("The Carrier has Been destroyed\n");
			pl_sunkships[0] = -1;
			player->sunk_ships++;
		}
		

		else if (pl_sunkships[1] == 4)
		{
				check_win[1] = 1;
				printf("The Battleship has Been destroyed\n");
				pl_sunkships[1] = -1;
				player->sunk_ships++;
		}
		else if (pl_sunkships[2] == 3)
		{
				check_win[2] = 1;
				printf("The Cruiser has Been destroyed\n");
				pl_sunkships[2] = -1;
				player->sunk_ships++;
		}
		else if (pl_sunkships[3] == 3)
		{
			check_win[3] = 1;
			printf("The Submarine has Been destroyed\n");
			pl_sunkships[3] = -1;
			player->sunk_ships++;
		}
		else if (pl_sunkships[4] == 2)
		{
			check_win[4] = 1;
			printf("The Destroyer has Been destroyed\n");
			pl_sunkships[4] = -1;
			player->sunk_ships++;
		}			
}

// Function to determine if the player won
void Determine_winner(void)
{
		printf("*****Player 1 Is the Winner! You have Won the game of Battleship!!!!*****\n");
		return 0;

}
// function to determine if compputer won the game
void Determine_winner_computer(void)
{
		printf("*****The Computer Has Won Battleship! You Lost The game of Battleship!*****");
}

//Print the game states to the .txt file
void print_stats(game_stats *player, game_stats *computer)
{
	FILE *outfile = NULL;

	outfile = fopen("logfile.txt", "w"); // open the file

	fprintf(outfile, "Player Stats: \n"); // print player stats to txt file
	fprintf(outfile, "Shots hit: %d\n", player->shots); // print how many shots where were hit to text file
	fprintf(outfile, "Miss: %d\n", player->miss); // print how many misses
	fprintf(outfile, "Total Shots: %d\n", player->total_shots); // print total shots
	fprintf(outfile, "Ships that were sunk: %d\n", player->sunk_ships); // print amount of ships that were sunk

	fprintf(outfile, "Computer Stats: \n");
	fprintf(outfile, "Shots Hit: %d\n", computer->shots);
	fprintf(outfile, "Miss: %d\n", computer->miss);
	fprintf(outfile, "Total Shots: %d\n", computer->total_shots);
	fprintf(outfile, "Ships that were sunk: %d\n", computer->sunk_ships);

	fclose(outfile); // close the file

}