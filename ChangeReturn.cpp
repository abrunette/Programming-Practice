/*****************ChangeReturn.cpp**************/
//Author: Aaron Brunette
//Github: abrunette
//Last updated: 2017/04/22
//Compiled with g++
//Written on Vim
//Purpose: To find the change needed from cash given.
/***************************************/

#include <iostream>	//input/output library
#include <math.h>	//mathematical declarations
using namespace std;

void findDollars(int);		//declare findDollars function
void findChange(int, int);	//deckare findChange function

//Purpose:
//User information: Run the program.
//Input: Takes three doubles, cost, payment,
// and change.
int main()
{
	//initialize doubles to hold the cost of the item and
	// the payment the customer gives
	double cost, payment;
	int change;

	cout << "Please enter the price of the items: ";
	cin >> cost;	//cost of item

	while(cin.fail())	//check cost is valid
	{
		cout << "\nPlease enter a valid number: ";
		cin >> cost;
	}
	int icost = nearbyint(cost * 100);	//convert to integer

	cout << "\nPlease enter the amount the customer is paying with: ";
	cin >> payment;	//customers payment

	while(cin.fail())	//check payment is valid
	{
		cout << "\nPlease enter a valid number: ";
		cin >> payment;
	}
	int ipayment = nearbyint(payment * 100);	//convert to integer

	//check for exact change
	if(icost == ipayment)
	{
		cout << "Customer gave exact change.\n";
		return 0;
	}
	else if(icost > ipayment)		//customer didn't pay enough
	{
		cout << "Customer did not give enough payment.\n";
		return 0;
	}
	else	//customer gets change
		change = ipayment - icost;		//find total change needed

	cout << "change = " << change << "\n\n";

	findDollars(change);	//call findChange function

	return 0;
}

//Purpose: To find the number of dollars in change the customer gets back.
//Parameters: Takes one double that is divided up into dollars and cents.
//Output: Outputs the number of dollars the customer will get back.
void findDollars(int theChange)
{
	int theDollars = theChange / 100;	//cut off decimal to get dollars
	cout << "Customer gets $" << theDollars << " back.\n";
	theChange -= (theDollars * 100);
	findChange(theChange, theDollars);

	return;
}

//Purpose: To find the amount of change the customer will get back
//Paramters: Takes two doubles, the number of dollars in changes,
// and the dollars with the change.
//Output: Will output the required individual change the customer
// will get back.
void findChange(int splitChange, int cutDollars)
{
	//finding quarters
	int quarters = splitChange / 25;
	splitChange = splitChange % 25;
	cout << "Customer gets " << quarters << " quarters.\n";
	
	//finding dimes
	int dimes = splitChange / 10;
	splitChange = splitChange % 10;
	cout << "Customer gets " << dimes << " dimes.\n";

	//finding nickels
	int nickels = splitChange / 5;
	splitChange = splitChange % 5;
	cout << "Customer gets " << nickels << " nickels.\n";

	//finding pennies
	cout << "Customer gets " << splitChange << " pennies.\n";

	return;
}
