//Michelle Maidana

//January 26, 2018

//Module 3 Program 2

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

int main()
{
	int num, new_num = 40;
	char char1, up_char1, char2, low_char2;

	//1. Print “Hello my name is (add your name here)” onto the screen
	printf("Hello my name is Michelle\n");
	//2. Prompt the user for a number
	printf("Please enter a number: ");
	//3. Scan/read the number from the keyboard
	scanf("%d", &num);
	//4. Add 40 to the number
	new_num = new_num + num;
	//5. Print both the original number and the total back onto the screen
	printf("original number: %d total: %d\n", num, new_num);
	//6. Prompt the user for a letter.
	printf("Please enter a letter: ");
	//7. Scan/read the letter from the keyboard
	scanf(" %c", &char1);
	//8. Change the letter to upper case //use toupper  function from <ctype.h>
	up_char1 = toupper(char1);
	//9. Prompt the user for another letter
	printf("Please enter another letter: ");
	scanf(" %c", &char2);
	//10. Change the second letter to lowercase //use tolower function from <ctype.h>
	low_char2 = tolower(char2);
	//11. Print both the original letters and the possibly changed letters back onto the screen
	printf("original letters: %c %c possibly changed letters: %c %c\n", char1, char2, up_char1, low_char2);

	return 0;
}
