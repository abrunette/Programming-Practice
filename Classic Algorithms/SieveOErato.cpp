/*****************SieveOErato.cpp**************/
//Author: Aaron Brunette
//Github: abrunette
//Last updated: 2017/10/19
//Compiled with g++
//Written on Vim
//Purpose: Generate prime numbers using the
// Sieve of Eratosthenes.
/***************************************/

#include <iostream>
#include <cmath>
using namespace std;

//Purpose: to find all prime numbers up to user input integer
//User information: input an integer
//Algorithm:  sieve out all multiples of primes
//Input:  upper bound integer
//Output: prime numbers up to upper bound
int main()
{
	int input = 0;			//size of the array, n
	
	cout 	<< "This is a prime number generator using the Sieve of Eratosthenes.\n"
		<< "I will tell you all prime numbers up to the number you input.\n\n"
		<< "Please enter an integer greater than 1: ";
	cin >> input;			//get upper bound
	cout << endl;

	//error checking
	while(cin.fail())	//check for non integers
	{
		cout << "Please enter an integer greater than 1: ";
		cin >> input;
	}
	
	while (input < 2)	//check for interger greater than 2
	{
		cout 	<< "You've entered an invalid input.\n"
			<< "Please enter an integer greater than 1: ";
		cin >> input;
	}

	//array initialization
	int arraySize = input + 1;	//account for 0
	bool numbers[arraySize];	//initialize array to hold "input" numbers

	//initialize all array values to true
	for(int i = 0; i < arraySize; i++)
		numbers[i] = true;

	//Sieve of Eratosthenes
	cout << "Beginning Sieve of Eratosthenes...\n\n";

	//while the current array location does not exceed the square of the upper bound
	for(int count = 2; count < (sqrt(arraySize)); count++)
	{
		//if the number is prime
		if(numbers[count] == true)
		{
			//(i^2) + (x*i)	;;; where i is the current prime, and x is a multiple of i
			for(int factor = 0; ((count * count) + (factor * count)) < arraySize; factor++)
				numbers[((count * count) + (factor * count))] = false;			//not a prime
		}
	}

	//Output
	for(int output = 2; output < arraySize; output++)
	{
		if(numbers[output] == true)
			cout << output  << " is a prime number.\n";
	}
	cout << endl;
	return 0;
}
