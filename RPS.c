/**
Just a short rock paper scissors program for C coding practice.  This was tested in Windows 10
with Visual Studio, so your mileage may vary.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_input();
int pc_choice();

//Main function
int main() {
	printf ("Type \"rock\", \"paper\", or \"scissors\" to issue a command. Type \"end\" to stop.\n");
	int playerwins = 0;		//Keeps track of player wins
	int pcwins = 0;		//Keeps track of computer wins
	int pc_choice;		//
	int player_choice;
	player_choice = get_input();
	while(player_choice != 3) {	//Cross references player player_choice with PC player_choice
		printf("%d\n", player_choice);
		pc_choice = pc_choice();
		if (player_choice == 0) {
			switch(pc_choice) {
				case 0:
					printf("Tie.\n\n");
					break;
				case 1:
					printf("You lose.\n\n");
					pcwins += 1;
					break;
				case 2:
					printf("You win.\n\n");
					playerwins += 1;
					break;
			}
		} else if (player_choice == 1) {
			switch(pc_choice) {
				case 0:
					printf("You win.\n\n");
					playerwins += 1;
					break;
				case 1:
					printf("Tie.\n\n");
					break;
				case 2:
					printf("You lose.\n\n");
					pcwins += 1;
					break;
			}
		} else if (player_choice == 2) {
			switch(pc_choice) {
				case 0:
					printf("You lose.\n\n");
					pcwins += 1;
					break;
				case 1:
					printf("You win.\n\n");
					playerwins += 1;
					break;
				case 2:
					printf("Tie.\n\n");
					break;
			}
		}
		player_choice = get_input();
	}
	if (pcwins < playerwins) {	//Checks who wins after the game ends
		printf("You win the game! %d-%d\n", playerwins, pcwins);
	} else if (pcwins > playerwins) {
		printf("You lose the game! %d-%d\n", pcwins, playerwins);
	} else {
		printf("It's a tie! %d-%d\n", pcwins, playerwins);
	}
	printf("Press enter to exit.\n");
	char enter = 0;
	while (enter != '\r' && enter != '\n') { 
		enter = getchar(); 
	}
	exit(0);
}

int pc_choice(){	//Gets computer's choice via randomizer
	int choice = rand() % 3;
	switch(choice){
		case 0:
			printf("Computer chooses Rock.\n");
			break;
		case 1:
			printf("Computer chooses Paper.\n");
			break;
		case 2:
			printf("Computer chooses Scissors.\n");
			break;
	}
	return choice;
}

int get_input() {	//Gets player input and returns a corresponding int
	printf("Enter a command\n");
	char player_choice[11];
	while (1) {
		fgets(player_choice, 11, stdin);
		if (!strchr(player_choice, '\n')) {	//In case input exceeds the buffer
			while (fgets(player_choice, sizeof player_choice, stdin) && !strchr(player_choice, '\n'))
			;
		} else {
			if (strcmp(player_choice, "rock\n") == 0) {
				printf("You choose Rock.\n")
				return 0;
			} else if (strcmp(player_choice, "paper\n") == 0) {
				printf("You choose Paper.\n")
				return 1;
			} else if (strcmp(player_choice, "scissors\n") == 0) {
				printf("You choose Scissors.\n")
				return 2;
			} else if (strcmp(player_choice, "end\n") == 0) {
				return 3;
			}
			printf("Please enter a valid command.\n");	
		}
	}
}

