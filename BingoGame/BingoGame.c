#include <stdio.h>
#include <conio.h>
#include<math.h>
#include <stdlib.h>

#define ROW 3
#define COLUMN 9
#define PLAYER 6

int randrange(int low, int high);
void optionMenu();
void exitGameMenu();

void main() {
	int option;
	int playerCard[PLAYER][ROW][COLUMN], i, j;
	int randomIndex, player, playerCount;

	printf("Number of players(2 - 6): ");
	scanf("%d", &playerCount);

	

	for (player = 0; player < playerCount; ++player) {
		for (i = 0; i < ROW; ++i) {
			for (j = 0; j < COLUMN; ++j) {
				switch (j) {
					case 0:
						randomIndex = randrange(1, 10);
						break;
					case 1:
						randomIndex = randrange(11, 20);
						break;
					case 2:
						randomIndex = randrange(21, 30);
						break;
					case 3:
						randomIndex = randrange(31, 40);
						break;
					case 4:
						randomIndex = randrange(41, 50);
						break;
					case 5:
						randomIndex = randrange(51, 60);
						break;
					case 6:
						randomIndex = randrange(61, 70);
						break;
					case 7:
						randomIndex = randrange(71, 80);
						break;
					case 8:
						randomIndex = randrange(81, 99);
						break;
				}//switch

				playerCard[player][i][j] = randomIndex;
			}//for
		}//for
	}//for

	for (player = 0; player < playerCount; ++player) {
		printf("--------------------Player Card--------------------\n");
		for (i = 0; i < ROW; ++i) {
			for (j = 0; j < COLUMN; ++j) {
				printf("%d   ", playerCard[player][i][j]);

				//Leaves a blank line after each row
				if (j == 8)
					printf("\n\n");
			}//for
		}//for
	}//for

	optionMenu();
	printf("\nYour option: ");
	scanf("%d", &option);

	while (option != 5) {
		switch (option) {
			case 1:
				//Draw the next number
				
				break;
			case 2:
				//Save the game
				break;
			case 3:
				//Output the game status
				break;
			case 4:
				//Exit game without saving
				exitGameMenu();
				printf("\n\tYour option: ");
				scanf("%d", &option);

				switch (option) {
					case 1:
						//Open new game
						break;
					case 2:
						//Open previously save game
						break;
					case 3:
						//Exit application
						option = 5;
						break;
					default:
						printf("\nOption doesn't exist - please try again");
				}//switch
				break;
			default:
				printf("\nOption doesn't exist - please try again");
		}//switch

		if (option != 5) {
			printf("\nYour option: ");
			scanf("%d", &option);
		}//if
	}//while
	getch();
}//main

int randrange(int low, int high) {
	int randomNumber;
	srand(time(NULL));
	randomNumber = rand() % (high - low + 1) + low;
	
	return randomNumber;
}//randrange()

void optionMenu() {
	printf("\nChoose from the following options: ");
	printf("\n\t1 - Draw the next number.");
	printf("\n\t2 - Save the game.");
	printf("\n\t3 - Output the game status.");
	printf("\n\t4 - Exit the game without saving.");
}//optionMenu()

void exitGameMenu() {
	printf("\n\tChoose from the following options: ");
	printf("\n\t\t1 - Open new game.");
	printf("\n\t\t2 - Open previously save game.");
	printf("\n\t\t3 - Exit application.");
}//exitGameMenu()



