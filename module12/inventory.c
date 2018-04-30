//Michelle Maidana

//Module 12 Large Program 4

//April 30, 2018

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#define SIZE 50

typedef struct {
	char name[30];
	char manufacturer[30];
	int id;
	int releaseYear;
	double price;
	double screenSize;
}phone;

//greets the user
void GreetUser();

//helper to add the phone to the phone list
void AddToPhoneList(phone list[], int index, char name[], char manufacturer[], int id, int releaseYear, double price, double screenSize);

//hardcodes six entries
void AddSixEntries(phone list[]);

//runs the menu and gets the user choice
char GetMenuInput();

//prints the contents of the list onto the screen
void PrintToScreen(phone list[], int count);

//prints a report to a file
//declares the file pointer, connects to the file, and closes the file pointer
void SaveToFile(phone list[], int count);

//adds an item to the list
void AddPhone(phone list[], int count);

//displays the IDs in the list, gets the ID from the user, and returns it
int DisplaysIDs(phone list[], int count);

//searches the list by ID and returns the index, if there is a match or returns -1
int SearchList(phone list[], int count, int id);

//removes an item from the list
void RemoveItem(phone list[], int* count, int index);

//updates an item in the list
void UpdateItem(phone list[], int index);

int main() {
	phone list[SIZE];
	char letter;
	int count = 0, id, index;
	
	AddSixEntries(list);
	//list now has 6 entries
	count = 6;
	GreetUser();
	letter = GetMenuInput();

	while (letter != 'Q') {
		if (letter == 'P') {
			PrintToScreen(list, count);
		}
		else if (letter == 'A') {
			AddPhone(list, count);
			count++;
		}
		else if (letter == 'C') {
			count = 0;
			printf("All records cleared\n");
		}
		else if (letter == 'S') {
			SaveToFile(list, count);
			printf("Saved current report to file\n");
		}
		else if (letter == 'D') {
			id = DisplaysIDs(list, count);
			index = SearchList(list, count, id);
			RemoveItem(list, &count, index);
		}
		else if (letter == 'U') {
			id = DisplaysIDs(list, count);
			index = SearchList(list, count, id);
			UpdateItem(list, index);
		}
		else {
			printf("Error: unrecognized letter\n");
		}
		letter = GetMenuInput();
	}

	return 0;
}

//greets the user
void GreetUser() {
	printf("Welcome to the phone inventory!\n");
	printf("This program manages a list of phones\n");
	printf("Each phone has a unique ID\n");
	printf("Follow the prompts on the menu:\n");
}

//helper to add the phone to the phone list
void AddToPhoneList(phone list[], int index, char name[], char manufacturer[], int id, int releaseYear, double price, double screenSize) {
	strcpy(list[index].name, name);
	strcpy(list[index].manufacturer, manufacturer);
	list[index].id = id;
	list[index].releaseYear = releaseYear;
	list[index].price = price;
	list[index].screenSize = screenSize;
}

//hardcodes six entries
void AddSixEntries(phone list[]) {
	AddToPhoneList(list, 0, "LGG6", "LG", 34, 2017, 650.00, 5.7);
	AddToPhoneList(list, 1, "Nexus6", "Motorola", 42, 2014, 649.00, 5.96);
	AddToPhoneList(list, 2, "OnePlus2", "OnePlus", 13, 2015, 390.00, 5.5);
	AddToPhoneList(list, 3, "Pixel2", "Google", 20, 2017, 649.00, 5.0);
	AddToPhoneList(list, 4, "GalaxyS6", "Samsung", 76, 2015, 649.99, 5.1);
	AddToPhoneList(list, 5, "iPhoneX", "Apple", 12, 2017, 999.00, 5.8);
}

//runs the menu and gets the user choice
char GetMenuInput() {
	char let;

	printf("\n----------------------------------------------\n\n");
	printf("Select an option:\n");
	printf("P....Print the inventory list onto the screen\n");
	printf("A....Add a new phone entry\n");
	printf("C....Clear all records\n");
	printf("S....Create a current report (save it to a file)\n");
	printf("D....Delete a phone from the list (inventory)\n");
	printf("U....Update the price of a phone\n");
	printf("Q....Quit\n\n");

	scanf(" %c", &let);
	let = toupper(let);
	return let;
}

//prints the contents of the list onto the screen
void PrintToScreen(phone list[], int count) {
	if (count == 0) {
		printf("Empty list\n");
	}

	for (int i = 0; i < count; i++) {
		printf("\n\n---Item %d:\n", i+1);
		printf("The name is: %s\n", list[i].name);
		printf("The manufacturer is: %s\n", list[i].manufacturer);
		printf("The ID is: %d\n", list[i].id);
		printf("The release year is: %d\n", list[i].releaseYear);
		printf("The price is: %.2f\n", list[i].price);
		printf("The screen size is: %.2f\n", list[i].screenSize);
	}
}

//prints a report to a file
//declares the file pointer, connects to the file, and closes the file pointer
void SaveToFile(phone list[], int count) {
	FILE *outPtr;
	outPtr = fopen("out.txt", "w");

	for (int i = 0; i < count; i++) {
		fprintf(outPtr, "---Item %d:\n", i + 1);
		fprintf(outPtr, "The name is: %s\n", list[i].name);
		fprintf(outPtr, "The manufacturer is: %s\n", list[i].manufacturer);
		fprintf(outPtr, "The ID is: %d\n", list[i].id);
		fprintf(outPtr, "The release year is: %d\n", list[i].releaseYear);
		fprintf(outPtr, "The price is: %.2f\n", list[i].price);
		fprintf(outPtr, "The screen size is: %.2f\n\n", list[i].screenSize);
	}
	fclose(outPtr);
}

//adds an item to the list
void AddPhone(phone list[], int count) {
	printf("Enter name: ");
	scanf("%s", list[count].name);
	printf("Enter manufacturer: ");
	scanf("%s", list[count].manufacturer);
	printf("Enter ID: ");
	scanf("%d", &list[count].id);
	printf("Enter release year: ");
	scanf("%d", &list[count].releaseYear);
	printf("Enter price: ");
	scanf("%lf", &list[count].price);
	printf("Enter screen size: ");
	scanf("%lf", &list[count].screenSize);
}

//displays the IDs in the list, gets the ID from the user, and returns it
int DisplaysIDs(phone list[], int count) {
	int currentID;

	for (int i = 0; i < count; i++) {
		printf("ID %d: %s\n", list[i].id, list[i].name);
	}

	printf("Enter ID: ");
	scanf("%d", &currentID);
	return currentID;
}

//searches the list by ID and returns the index, if there is a match or returns -1
//three arguments: list, number of items, id
int SearchList(phone list[], int count, int id) {
	for (int i = 0; i < count; i++) {
		if (id == list[i].id) {
			return i;
		}
	}
	return -1;

}

//removes an item from the list
//three arguments: list, number of items, location
void RemoveItem(phone list[], int* count, int index) {
	if (index == -1) {
		printf("Error: not found\n");
	}
	else {
		printf("The phone %s has been deleted\n", list[index].name);
		list[index] = list[*count - 1];
		*count = *count - 1;
	}
}

//updates an item in the list
//three arguments: list, number of items, location
void UpdateItem(phone list[], int index) {
	if (index == -1) {
		printf("Error: not found\n");
	}
	else {
		double newPrice;
		printf("$%.2f is the current price for %s\n", list[index].price, list[index].name);
		printf("Enter the new price: ");
		scanf("%lf", &newPrice);
		list[index].price = newPrice;
		printf("The price of %s has been updated to $%.2f\n", list[index].name, newPrice);
	}
}