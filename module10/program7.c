//Michelle Maidana

//Module 10 Program 7

//April 9, 2018

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	//declares 2 character arrays
	char word1[20], word2[20];
	//declares a character for the yes or no
	char answer;

	//greets the user
	printf("Hello!\n\n");

	//uses strcpy to initialize the character arrays to empty strings
	strcpy(word1, "");
	strcpy(word2, "");

	//asks and gets 2 words from the user
	printf("Enter the first of two words: ");
	scanf(" %s", word1);
	printf("Enter the second of two words: ");
	scanf(" %s", word2);

	//combines the 2 words into one word using strcat
	strcat(word1, word2);
	//prints the new word onto the screen
	printf("New word: %s\n\n", word1);

	//asks the user if they want to enter another 2 words
	printf("Would you like to enter another 2 words (y/n)?: ");
	scanf(" %c", &answer);

	while (answer == 'y' || answer == 'Y') {
		strcpy(word1, "");
		strcpy(word2, "");

		printf("Enter the first of two words: ");
		scanf(" %s", word1);
		printf("Enter the second of two words: ");
		scanf(" %s", word2);

		strcat(word1, word2);
		printf("New word: %s\n\n", word1);

		printf("Would you like to enter another 2 words (y/n)?: ");
		scanf(" %c", &answer);
	}

	return 0;
}