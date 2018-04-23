//Michelle Maidana

//February 5, 2018

//Module 4 Program 3

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//included for the pow function
#include <math.h>

int main() {
	//Declare variables: radius, sideLength, areaSquare, areaCircle, circCircle
	int radius, sideLength, areaSquare;
	double areaCircle, circCircle;

	//Prompt for the radius of the circle
	printf("Enter a radius: ");
	//Get the radius from the keyboard
	scanf("%d", &radius);
	//Calculate the area of the circle (use 3.14159)
	areaCircle = 3.14159 * pow(radius, 2);
	//Calculate the circumference of the circle (use 3.14159)
	circCircle = 2 * 3.14159 * radius;
	//Display the radius, circumference and area of the circle onto the screen
	printf("radius: %d circumference: %f area: %f\n", radius, circCircle, areaCircle);

	//Prompt for the length of a side of the square
	printf("Enter the length of a side of a square: ");
	//Get the length from the keyboard
	scanf("%d", &sideLength);
	//Calculate the area of the square
	areaSquare = pow(sideLength, 2);
	//Display the side length and area of the square onto the screen
	printf("side length: %d area of the square: %d\n", sideLength, areaSquare);

	return 0;
}