//Michelle Maidana

//Module 9 Program 6

//April 2, 2017

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 15

//uses a loop to read the integers into the array from the input file
void ReadIntegers(int num_array[], FILE * inPtr);
//uses a loop to print the array onto the screen in a column
void PrintArray(int num_array[]);
//uses a loop to add up all the items in the array and stores the sum
int ArraySum(int num_array[]);
//uses a loop to locate the largest integer in the array and stores it
int LargestInteger(int num_array[]);

int main() {
	int num_array[SIZE], sum, largestNum;
	FILE * inPtr;

	inPtr = fopen("numInput.txt", "r"); //reads to file
	if (inPtr == NULL) {
		perror("Error: can't open file");
		return -1;
	}

	ReadIntegers(num_array, inPtr);
	PrintArray(num_array);
	sum = ArraySum(num_array);
	largestNum = LargestInteger(num_array);
	//prints the sum and the largest value onto the screen
	printf("sum: %d largest value: %d\n", sum, largestNum);
	fclose(inPtr);

	//writes the sum and the largest value to the output file
	inPtr = fopen("resOut.txt", "w"); //writes to file
	fprintf(inPtr, "sum: %d largest value: %d\n", sum, largestNum);
	fclose(inPtr);

	return 0;
}

//uses a loop to read the integers into the array from the input file
void ReadIntegers(int num_array[], FILE * inPtr) {
	for (int i = 0; i < SIZE; i++) {
		fscanf(inPtr, "%d", &num_array[i]);
	}
}

//uses a loop to print the array onto the screen in a column
void PrintArray(int num_array[]) {
	for (int i = 0; i < SIZE; i++) {
		printf("%d\n", num_array[i]);
	}
}

//uses a loop to add up all the items in the array and stores the sum
int ArraySum(int num_array[]) {
	int sum = 0;
	for (int i = 0; i < SIZE; i++) {
		sum += num_array[i];
	}
	return sum;
}

//uses a loop to locate the largest integer in the array and stores it
int LargestInteger(int num_array[]) {
	int largestNum = num_array[0];
	for (int i = 1; i < SIZE; i++) {
		if (num_array[i] > largestNum) {
			largestNum = num_array[i];
		}
	}
	return largestNum;
}