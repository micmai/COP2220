//Michelle Maidana

//Module 8: Large Program 2

//March 25, 2018

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAXCREDIT -4500.00

//displays the list of options available
//prompts for the user’s selection and sets the value of the selection
void RunBankChoices(int* choice);

//greets the user
void Greeting();

//takes one double argument and one character argument
//displays the current balance of the account ('C' checking, 'S' savings, 'R' credit)
void AccountBalance(double account, char letter);

//takes reference to all the bank account money values and the menu selection
//makes the decision of which transaction should be done
void TransactionDecision(int num, double* cPtr, double* sPtr, double* rPtr);

//takes a reference to the selected account balance
//gets the added amount from the user and adds it to the account
void DepositMoney(double* accountPtr);

//takes a reference to the selected account balance
//gets the withdrawal amount from the user 
//checks to see if there is enough money available OR enough credit available
//subtracts the money from the account if available
void WithdrawMoney(double* accountPtr, char letter);

int main() {
	int choice;
	double checking = 480.45, savings = 124.62, credit = -2134.78;

	Greeting();
	//displays the initial account balances
	AccountBalance(checking, 'C');
	AccountBalance(savings, 'S');
	AccountBalance(credit, 'R');

	//displays the bank options after each transaction decision until the user enters (-1) to stop the program
	RunBankChoices(&choice);
	while (choice != -1) {
		TransactionDecision(choice, &checking, &savings, &credit);
		RunBankChoices(&choice);
	}
	
	return 0;
}

//displays the list of options available
//prompts for the user’s selection and sets the value of the selection
void RunBankChoices(int* choice) {
	printf("\n------------------------\n");
	printf("(1) to DEPOSIT to CHECKING\n");
	printf("(2) to WITHDRAW from CHECKING\n");
	printf("(3) to DEPOSIT to SAVINGS\n");
	printf("(4) to WITHDRAW from SAVINGS\n");
	printf("(5) to DEPOSIT to CREDIT\n");
	printf("(6) to TAKE an ADVANCE from CREDIT\n");
	printf("(7) for all ACCOUNT BALANCES\n\n");
	printf("(-1) QUIT\n\n");

	printf("Select an option: ");
	scanf("%d", choice);
}

//greets the user
void Greeting() {
	printf("*******************************\n\n");
	printf("Welcome to the Bank of COP 2220\n\n");
	printf("It is a pleasure to manage your checking, savings, and credit accounts\n\n");
}

//takes one double argument and one character argument
//displays the current balance of the account ('C' checking, 'S' savings, 'R' credit)
void AccountBalance(double account, char letter) {
	if (letter == 'C') {
		printf("-- You currently have $%.2f in your checking account\n", account);
	}
	if (letter == 'S') {
		printf("-- You currently have $%.2f in your savings account\n", account);
	}
	if (letter == 'R') {
		printf("-- You currently have $%.2f credit balance\n", account);
	}
}

//takes reference to all the bank account money values and the menu selection
//makes the decision of which transaction should be done
void TransactionDecision(int num, double* cPtr, double* sPtr, double* rPtr) {
	printf("\nThe transaction you chose was: %d\n", num);
	if (num == 1) {
		printf(" Deposit to Checking\n");
		AccountBalance(*cPtr, 'C');
		DepositMoney(cPtr);
		AccountBalance(*cPtr, 'C');
	} else if (num == 2) {
		printf(" Withdraw from Checking\n");
		AccountBalance(*cPtr, 'C');
		WithdrawMoney(cPtr, 'C');
		AccountBalance(*cPtr, 'C');
	} else if (num == 3) {
		printf(" Deposit to Savings\n");
		AccountBalance(*sPtr, 'S');
		DepositMoney(sPtr);
		AccountBalance(*sPtr, 'S');
	} else if (num == 4) {
		printf(" Withdraw from Savings\n");
		AccountBalance(*sPtr, 'S');
		WithdrawMoney(sPtr, 'S');
		AccountBalance(*sPtr, 'S');
	} else if (num == 5) {
		printf(" Deposit to Credit\n");
		AccountBalance(*rPtr, 'R');
		DepositMoney(rPtr);
		AccountBalance(*rPtr, 'R');
	} else if (num == 6) {
		printf(" Take out more Credit\n");
		AccountBalance(*rPtr, 'R');
		WithdrawMoney(rPtr, 'R');
		AccountBalance(*rPtr, 'R');
	} else if (num == 7) {
		printf(" Show account balances\n");
		AccountBalance(*cPtr, 'C');
		AccountBalance(*sPtr, 'S');
		AccountBalance(*rPtr, 'R');
	} else {
		printf("\nNot recognized\n");
	}
}

//takes a reference to the selected account balance
//gets the added amount from the user and adds it to the account
void DepositMoney(double* accountPtr) {
	double amount;
	printf("\nEnter the amount to deposit: ");
	scanf("%lf", &amount);
	*accountPtr += amount;
}

//takes a reference to the selected account balance
//gets the withdrawal amount from the user 
//checks to see if there is enough money available OR enough credit available
//subtracts the money from the account if available
void WithdrawMoney(double* accountPtr, char letter) {
	double amount;
	printf("\nEnter the amount to withdraw: ");
	scanf("%lf", &amount);
	if (letter == 'C' || letter == 'S') {
		if (amount > *accountPtr) {
			printf("\n*** There is not enough money for that withdrawal\n");
		} else {
			*accountPtr -= amount;
		}
	}
	if (letter == 'R') {
		if (*accountPtr - amount < MAXCREDIT) {
			printf("\n*** There is not enough credit available for this transaction\n\n");
			printf("*** The maximum credit allowed is $%.2f\n\n", MAXCREDIT);
			printf("*** Contact customer service about raising your Credit Line\n");
		} else {
			*accountPtr -= amount;
		}
	}
}