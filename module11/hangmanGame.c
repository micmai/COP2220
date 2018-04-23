//Michelle Maidana

//Module 11 Large Program 3

//April 23, 2018

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXGUESSES 6

//this function provides instructions to the user on how to play the game
void HangmanRules();

//this fuction asks the user if they want to play another game (y or n)
void PlayAgain(char *againPtr);

//this function runs one game
//input: character from the file, void return type
//all other functions to play one round of a game are called from within the PlayOneGame function
void PlayOneGame(char solution[]);

//this function changes a character array to all uppercase letters
void UpperCaseWord(char solution[]);

//this function creates the starword array
void CreateStarword(char starword[], int length);

//this function gets the user's guess letter and adds it to the lettersGuessed array
//returns the letter entered by the user
char GetTheLetterGuess(char lettersGuessed[], int *numPtr);

//this function replaces any asterik in the starword with the current character entered by the user
int ReplaceStars(char solution[], char starword[], char letter);

//this function gets the guess word, compares the solution and the guess word
//tells the user if they have won and returns a 1, otherwise it returns a 0
int DidYouWin(char solution[]);

int main() {
	char repeat, solution[25];
	FILE *inPtr;

	inPtr = fopen("hangmanWords.txt", "r"); //reads the input file
	HangmanRules();

	do { //first game
		fscanf(inPtr," %s", solution);
		UpperCaseWord(solution);
		PlayOneGame(solution);
		PlayAgain(&repeat);
	} while (repeat == 'Y'); //reiterates if user wants to play another game

	printf("Goodbye!\n\n");
	fclose(inPtr);

	return 0;
}

//this function provides instructions to the user on how to play the game
void HangmanRules() {
	printf("WELCOME TO HANGMAN!\n\n\n");
	printf("Please read the following instructions before you play.\n\n");
	printf("-You will be presented with a word to be guessed\n");
	printf("-Guess letters one at a time\n");
	printf("-You can have up to six incorrect letter guesses\n");
	printf("-You can only guess the word when you have made a correct letter guess\n");
	printf("-The game will be OVER when you have guessed the word correctly\n");
	printf("     Or when you have guessed letters incorrectly SIX times\n\n");
	printf("HAVE FUN!\n\n\n");
}

//this fuction asks the user if they want to play another game (y or n)
void PlayAgain(char *againPtr) {
	printf("Would you like to play again (Y or N)?: ");
	scanf(" %c", againPtr);
	printf("\n");
	*againPtr = toupper(*againPtr);
}

//this function runs one game
//input: character from the file, void return type
//all other functions to play one round of a game are called from within the PlayOneGame function
void PlayOneGame(char solution[]) {
	char starword[25] = "";
	char lettersGuessed[25] = "";
	char letter;
	int length = strlen(solution);
	int test, num = 0, win = 0, numGuesses = 0;

	CreateStarword(starword, length);

	while (win == 0 && numGuesses < MAXGUESSES) {
		printf("-------------------------------\n\n");
		printf("Here are the letters guessed so far: %s\n\n", lettersGuessed);
		printf("%s\n", starword);
		letter = GetTheLetterGuess(lettersGuessed, &num);
		test = ReplaceStars(solution, starword, letter);
		
		if (test == 1) {
			printf("\nThe letter was in the word, you can now guess the word: \n");
			printf("%s\n", starword);
			win = DidYouWin(solution);
			
		} else {
			numGuesses++;
			printf("\nThe letter was not in the word, the number of guesses used is now %d\n\n", numGuesses);
		}
	}

	if (numGuesses == MAXGUESSES) {
		printf("You did not win this round, the solution was %s\n\n", solution);
	}
}

//this function changes a character array to all uppercase letters
void UpperCaseWord(char solution[]) {
	int i;
	int length = strlen(solution);

	for (i = 0; i < length; i++) {
		solution[i] = toupper(solution[i]);
	}
}

//this function creates the starword array
void CreateStarword(char starword[], int length) {
	for (int i = 0; i < length; i++) {
		starword[i] = '*';
	}
}

//this function gets the user's guess letter and adds it to the lettersGuessed array
//returns the letter entered by the user
char GetTheLetterGuess(char lettersGuessed[], int *numPtr) {
	char temp;
	
	printf("Guess a letter: ");
	scanf(" %c", &temp);
	temp = toupper(temp);
	lettersGuessed[*numPtr] = temp;
	*numPtr = *numPtr + 1;
	lettersGuessed[*numPtr] = '\0';

	return temp;
}

//this function replaces any asterik in the starword with the current character entered by the user
int ReplaceStars(char solution[], char starword[], char letter) {
	int length = strlen(solution);
	int i, returnValue = 0;

	for (i = 0; i < length; i++) {
		if (solution[i] == letter) {
			starword[i] = letter;
			returnValue = 1;
		}
	}

	return returnValue;
}

//this function gets the guess word, compares the solution and the guess word
//tells the user if they have won and returns a 1, otherwise it returns a 0
int DidYouWin(char solution[]) {
	char guessword[25];
	int returnValue = 0;

	printf("Guess the word: ");
	scanf(" %s", guessword);
	UpperCaseWord(guessword);
	
	if (strcmp(solution, guessword) == 0) {
		printf("\nYou won that round, congratulations!\n\n");
		returnValue = 1;
	}
	else {
		printf("\nThat is not the correct word\n\n");
	}
	return returnValue;
}