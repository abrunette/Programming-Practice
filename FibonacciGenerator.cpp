/*****************FibonacciGenerator.cpp**************/
//Author: Aaron Brunette
//Github: abrunette
//Last updated: 2017/02/22
//Compiled with G++
//Written on Vim
//Purpose: To generate successive fibonacci numbers up to
//the amount the user specified.
/*****************************************************/

#include <iostream>	//input/output library
using namespace std;

//declare fibonacci function
void fibonacci(int);

//Purpose: To ask the user how many fibonacci numbers
// they want to generate, then call the fibonacci function.
int main()
{
	int input;	//user input

	cout << "Please enter a the fibonacci number you want to generate up to: ";
	cin >> input;
	cout << endl;

	//checks that input is a number or is not 0
	while(cin.fail() || input == 0)
	{
		cout << "Please enter a number larger than 0: ";
		cin >> input;
		cout << endl;
	}

	fibonacci(input);	//calls fibonacci function

	return 0;
}

//Purpose: To generate the fibonacci sequence up to the
// user specified int, "Nth". Outputs all fibonacci 
// numbers up to the value specified by "Nth".

//Algorithm: Uses a while loop that checks if the counter
// has reached the value specified by "Nth". Initially
// outputs the first fibonacci number. Enters while loop.
// Adds the first seed numbers together and stores in temp.
// Outputs temp on the next line. Stores y into x, stores
// temp into y. Increments counter. Repeats so long as counter
// does not equal Nth.
void fibonacci(int Nth)
{
	int counter = 1;	//counts the number of fibonacci numbers that have been output
	int x = 0;		//initializes seed value 0
	int y = 1;		//initializes seed value 1
	int temp = 1;		//initializes First fibonacci number

	cout << temp << endl;	//outputs first fibonacci number

	while(counter != Nth)
	{
		temp = x + y;
		cout << temp << endl;
		x = y;
		y = temp;
		counter++;
	}
}
