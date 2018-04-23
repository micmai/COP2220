//Michelle Maidana

//Module 11 Program 8

//April 23, 2018

#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdio.h>
#define SIZE 20

typedef struct {
	char author[SIZE];
	char bookName[SIZE];
	int pageNumber;
	double cost;
}book;

//Function Prototypes

//fills the data fields of a book instance
//returns the filled book
book FillBook();

//fils the data fields of a book instance
//by reference using a pointer to a book
void FillBookPtr(book *bookptr);

//fills an array of books
void FillBookArray(book arrayB[], int *size);

//displays one book
void DisplayBook(book anyBook);

int main() {
	//Declare variables
	book myBook, myBook1, myBook2;
	book Booklist[SIZE];
	int bSize;
	int i;

	//Fill structures with a function
	myBook = FillBook();
	myBook1 = FillBook();

	//print using display function
	printf("\n---------Display myBook\n");
	DisplayBook(myBook);
	printf("\n---------Display myBook1\n");
	DisplayBook(myBook1);

	//Fill structure using pointers and display it
	FillBookPtr(&myBook2);
	printf("\n---------Display myBook2\n");
	DisplayBook(myBook2);

	//Fill the array with the function
	printf("\n---------Fill array Booklist\n");
	FillBookArray(Booklist, &bSize);

	//display an array of books
	printf("\n---------Display array Booklist\n");
	for (i = 0; i < bSize; i++) {
		DisplayBook(Booklist[i]);
	}

	return 0;
}

//Function Definitions

//fills the data fields of a book instance
//returns the filled book
book FillBook() {
	//Declare local variables
	book tempB;
	//prompt and get information
	printf("\nplease enter the author of your book: ");
	scanf("%s", tempB.author);
	//print to check
	printf("author: %s\n", tempB.author);

	//prompt and get information
	printf("\nplease enter the name of your book: ");
	scanf("%s", tempB.bookName);
	//print to check
	printf("name: %s\n", tempB.bookName);

	//prompt and get information
	printf("\nplease enter the number of pages of your book: ");
	scanf("%d", &tempB.pageNumber);
	printf("number of pages: %d\n", tempB.pageNumber);

	//prompt and get information
	printf("\nplease enter the cost of your book: ");
	scanf("%lf", &tempB.cost);
	printf("cost: %.2f\n", tempB.cost);
	return tempB;
}

//displays one book
void DisplayBook(book anyBook) {
	printf("\n\nauthor: %s\n", anyBook.author);
	printf("name: %s\n", anyBook.bookName);
	printf("number of pages: %d\n", anyBook.pageNumber);
	printf("cost: %.2f\n", anyBook.cost);
}

//fills the data fields of a book instance
//by reference using a pointer to a book
void FillBookPtr(book *bookptr) {
	//prompt and get information
	printf("\nplease enter the author of your book: ");
	scanf("%s", (*bookptr).author);

	//prompt and get information
	printf("\nplease enter the name of your book: ");
	scanf("%s", bookptr->bookName);

	//prompt and get information
	printf("\nplease enter the number of pages of your book: ");
	scanf("%d", &(*bookptr).pageNumber);

	//prompt and get information
	printf("\nplease enter the cost of your book: ");
	scanf("%lf", &(*bookptr).cost);
}

//fills an array of books
void FillBookArray(book arrayB[], int *size) {
	int i;
	//prompt the user
	printf("\nenter the number of books: ");
	scanf("%d", size);

	//print to check
	printf("size: %d\n", *size);

	for (i = 0; i < *size; i++) {
		printf("enter author: ");
		scanf("%s", arrayB[i].author);

		printf("enter name: ");
		scanf("%s", arrayB[i].bookName);

		printf("enter number of pages: ");
		scanf("%d", &arrayB[i].pageNumber);

		printf("enter cost: ");
		scanf("%lf", &arrayB[i].cost);
	}
}