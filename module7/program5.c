//Michelle Maidana

//February 19, 2018

//Module 7 Program 5

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//asks and gets an integer from the user
int GetInteger();
//takes one integer argument and two integer pointer arguments
//1. calculate the area of the square and store the result in areaPtr
//2. calculate the perimeter of the square and store the result in perimeterPtr
void CalculateBothSquare(int side, int*areaPtr, int * perimeterPtr);

int main() {
	int number, sumTotal = 0, productTotal = 1, length, squareArea, squarePerimeter;

	printf("PART 1:\n");
	printf("Enter an integer: ");
	number = GetInteger();

	//for loop to calculate the sum total
	for (int i = 1; i <= number; i++) {
		sumTotal += i * i;
	}

	//while loop to calculate the product total
	int j = 1;
	while (j <= number) {
		productTotal *= j * j;
		j++;
	}

	printf("The sum total is %d and the product total is %d\n\n", sumTotal, productTotal);

	printf("PART 2:\n");
	printf("You will be entering the length of the side of a square\n");
	printf("Enter an integer: ");
	length = GetInteger();
	CalculateBothSquare(length, &squareArea, &squarePerimeter);
	printf("The calculation results inside the main function:\n");
	printf("The area is %d and the perimeter is %d\n\n", squareArea, squarePerimeter);

	return 0;
}

//asks and gets an integer from the user
int GetInteger() {
	int x;
	scanf("%d", &x);
	return x;
}

//takes one integer argument and two integer pointer arguments
//1. calculate the area of the square and store the result in areaPtr
//2. calculate the perimeter of the square and store the result in perimeterPtr
void CalculateBothSquare(int side, int*areaPtr, int * perimeterPtr) {
	*areaPtr = side * side;
	*perimeterPtr = side * 4;
	printf("Inside the CalculateBothSquare function\n");
	printf("The calculation results inside the CalculateBothSquare function:\n");
	printf("The area is %d and the perimeter is %d\n\n", *areaPtr, *perimeterPtr);
}