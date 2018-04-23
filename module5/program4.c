//Michelle Maidana

//February 10, 2018

//Module 5 Program 4

#define _CRT_SECURE_NO_WARNINGS
//Preprocessor directive for the value pi
#define PI 3.141592
#include <stdio.h>
//For the pow function
#include <math.h>

//Function prototypes

//Gets an integer from the user and returns it
//Makes 2 calls to this function:
//1. Gets the radius of a circle and returns it to main
//2. Gets the length of the side of a square and returns it to main
int GetInteger();
//Takes one argument, the length of the side of the square and returns the perimeter
int CalculatePerimeterSquare(int length);
//Takes one argument, the radius of the circle and returns the area
double CalculateAreaCir(int radius);


int main() {
	//Declared variables
	int radius, length, squarePerimeter;
	double circleArea;

	//Greets the user
	printf("Welcome to the simple calculator!\n\n");

	printf("You will be entering the radius\n");
	//Prompts for the radius
	printf("Enter an integer: ");
	//Calls the GetInteger function, it will return an integer that will be assigned to radius
	radius = GetInteger();
	//Passes the radius to the CalculateAreaCir function
	//Calculates the area and returns the result, the area will be assigned to the variable circleArea in main
	circleArea = CalculateAreaCir(radius);
	//Displays the radius and area (to 3 decimal places) of the circle onto the screen from the main function
	printf("The radius is %d and the area is %.3f\n\n", radius, circleArea);

	printf("You will be entering the length of the side of a square\n");
	//Prompts for the length of a side
	printf("Enter an integer: ");
	//Calls the GetInteger function, it will return an integer that will be assigned to length
	length = GetInteger();
	//Passs the length to the CalculatePerimeterSquare function
	//Calculates the perimeter and returns the result, the perimeter will be assigned to the variable squarePerimeter in main
	squarePerimeter = CalculatePerimeterSquare(length);
	//Displays the side length and perimeter of the square onto the screen from the main function
	printf("The side length is %d and the perimeter is %d\n\n", length, squarePerimeter);

	return 0;
}

//Gets an integer from the user and returns it
//Makes 2 calls to this function:
//1. Gets the radius of a circle and returns it to main
//2. Gets the length of the side of a square and returns it to main
int GetInteger() {
	int x;
	scanf("%d", &x);
	return x;
}

//Takes one argument, the length of the side of the square and returns the perimeter
int CalculatePerimeterSquare(int length) {
	int x;
	//Formula for the perimeter of a square
	x = length * 4;
	return x;
}

//Takes one argument, the radius of the circle and returns the area
double CalculateAreaCir(int radius) {
	double x;
	//Formula for the area of a circle
	x = PI * pow(radius, 2);
	return x;
}