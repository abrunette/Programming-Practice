/*****************NextPrime.cpp**************/
//Author: Aaron Brunette
//Github: abrunette
//Last updated: 2017/02/23
//Compiled with G++
//Written on Vim
//Purpose: To generate successive prime numbers
//until the user tells the program to stop.
/********************************************/
#include <iostream>	//input/output library
using namespace std;

//declare findNextPrime function
int findNextPrime(int);

//Purpose: To continuously generate the next prime number
// for as long as the user want to.
//User information: Run the program.
//Input: Takes a char input to determine if the user wants
// to continue generating prime numbers.
//Output: Outputs each prime number that is generated.
int main()
{
	char input;		//user input
	int currPrime = 2;	//initialize first prime number
	int NoPrimes = 1;	//prime number counter

	cout << "This program generates prime numbers.\n"
	     << "Would you like the first prime number? (y/n): ";
	cin >> input;

	//checks that the user wants to continue generating number
	while(input == 'y' || input == 'Y')
	{
		cout << "Prime #" << NoPrimes << ": " << currPrime << endl;

		currPrime = findNextPrime(currPrime);	//call function findNextPrime
		NoPrimes++;				//increment the number of primes generated		

		cout << "Do you want to continue generating numbers? (y/n): ";
		cin >> input;	
	}

	return 0;
}

//Purpose: To find the next prime number from the previous one.
//Parameters: Finding is the previous number generated. Can be prime
// or composite.
//Algorithm: This function is called in main when the use wants to
// find the next prime number. It is also called recursively when
// if the number that is being checked is not a prime. If the number
// isn't prime it recursively checks if the next number is prime and
// returns it if it is. Otherwise it continues to the next number.
int findNextPrime(int finding)
{
	int next = finding + 1;		//next number
	int min = 1;			//min factor
	int max = next - 1;		//next factor
	int test;			//hold factor result

	//runs while a factor hasn't been found
	while(max != min)
	{
		test = next % max;	//check if is factorable
		if(test == 0)
			return findNextPrime(next);	//recursively calls itself
		else
			max--;		//decrements factor
	}
	return next;
}
