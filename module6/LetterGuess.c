// Michelle Maidana

// Module 6 Large Program 1

// February 17, 2018

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#define MAXGUESSES 5

// this function provides instruction to the user on how to play the game
void LetterGuessRules();

// this function asks, gets, returns the number of games the user wants to play
int GameCount();

// this void function runs one game
// the input is the letter from the input file
// all other functions to play one round are called from within the PlayOneGame function
void PlayOneGame(char solution);

// this function prompts the user to make a guess and returns the guess
// called from within the PlayOneGame function described above
char GetGuess();

// this function takes 2 arguments: the guess from the user and the solution letter from the file
// returns a 1 if the guess matches the solution and a 0 if it does not
// lets the user know if their guess comes alphabetically before or after the solution
int CompareGuessAndSolution(char guess, char solution);


int main() {
	char letter;
	int numGames;
	FILE * inPtr;

	inPtr = fopen("letters.txt", "r"); //connects to file

	LetterGuessRules();
	numGames = GameCount();

	for (int i = 1; i <= numGames; i++) {
		printf("\n*********************************\n\n");
		printf("Let's play game %d\n\n", i);

		fscanf(inPtr, " %c", &letter); //input the first letter in the file
		letter = toupper(letter); //converts the letter to uppercase
		PlayOneGame(letter);
	}

	return 0;
}

// this function provides instruction to the user on how to play the game
void LetterGuessRules() {
	printf("Welcome to the letter guessing game!\n\n");
	printf("You will begin by entering the number of games you'd like to play (1-8)\n");
	printf("You will have 5 chances to guess the letter for each game\n");
	printf("Let's begin!\n\n");
}

// this function asks, gets, returns the number of games the user wants to play
int GameCount() {
	int num;

	printf("Enter the number of games you wish you play (1-8): ");
	scanf("%d", &num);

	return num;
}

// this void function runs one game
// the input is the letter from the input file
// all other functions to play one round are called from within the PlayOneGame function
void PlayOneGame(char solution) {
	for (int i = 0; i < MAXGUESSES; i++) {
		if (1 == CompareGuessAndSolution(GetGuess(), solution)) {
			return;
		}
	}
	printf("Sorry, you did not win this round\n");
}

// this function prompts the user to make a guess and returns the guess
// called from within the PlayOneGame function described above
char GetGuess() {
	char guess;

	printf("Enter a guess: ");
	scanf(" %c", &guess);
	guess = toupper(guess); //converts the guess letter to uppercase
	
	return guess;
}

// this function takes 2 arguments: the guess from the user and the solution letter from the file
// returns a 1 if the guess matches the solution and a 0 if it does not
// lets the user know if their guess comes alphabetically before or after the solution
int CompareGuessAndSolution(char guess, char solution) {
	if (guess == solution) {
		printf("Awesome! You win this round!\n\n");
		return 1;
	} else {
		if (guess < solution) {
			printf("The solution (?) comes alphabetically after your guess (%c)\n", guess);
		} else {
			printf("The solution (?) comes alphabetically before your guess (%c)\n", guess);
		}
		return 0;
	}
}