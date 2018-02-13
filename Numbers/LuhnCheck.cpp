/*****************LuhnCheck.cpp**************/
//Author: Aaron Brunette
//Github: abrunette
//Last updated: 2018/02/12
//Compiled with g++
//Written on Vim
//Purpose: To use the Luhn Algorithm to 
// validate identification numbers.
/*********************************************/

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

//Prototype
int Luhn(string);

//Purpose: Gets user input number. 
// Tests result and gives number validity.
//User information: c++11 is needed to run this.
// Compile and run.
//Input:  User inputs number to be checked.
//Output: Prints result of checksum, validity.
int main()
{
	//hold user input
	string checkNum = "";

	//User input
	printf("Please enter the number to be checked: ");
	getline(cin, checkNum);

	//Luhn Algorithm
	int result = Luhn(checkNum);

	//compare result to check digit
	if((checkNum.back()-48) == result)
		printf("Number is valid.\n");
	else
		printf("Number is invalid.\n");

	return 0;
}

//Purpose: Perform the Luhn algorithm on
// the string the user gave.
//Parameters: Gets user input string with
// number to be checked.
//Algorithm: Luhn algorithm.
int Luhn(string checkThis)
{
	int sum = 0;
	int theLength = checkThis.length();
	int parity = theLength % 2;

	for(int loc = 0; loc < (theLength - 1); loc++)
	{
		int num = checkThis[loc] - 48;	//convert string digit to int
		if (loc % 2 == parity)		//second digit
			num *= 2;
		if (num > 9)
			num -= 9;
		sum += num;
	}
	return (10 - (sum % 10));	//returns check digit
}
