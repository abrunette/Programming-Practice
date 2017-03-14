/*****************PrimeFactors.cpp**************/
//Author: Aaron Brunette
//Github: abrunette
//Last updated: 2017/02/22
//Compiled with G++
//Written on Vim
//Purpose: To find the individual prime factors
//of a user specified number.
/***********************************************/

#include <iostream>	//input/output library
using namespace std;

bool isPrime(int);			//isPrime function declaration
void recursiveFactor(int, int);		//recursiveFactor function declaration

//Purpose: To prompt the user for a number in order to check the prime factors
// of that number. It then calls isPrime to check if it is a prime number. If
// it isn't prime, it calls recursive factor, recursively, in order to find
// all of the prime factors of the number the user input.
int main()
{
	int input;	//user input

	cout << "Please enter the prime number you would like to factor: ";
	cin >> input;
	cout << endl;

	//checks that input is a number
	while(cin.fail() || input < 1)
	{
		cout << "Please input a number greater than 0: ";
		cin >> input;
		cout << endl;
	}

	//checks if input is 1
	if(input == 1)
	{
		cout << "1 is not a prime or a composite number.\n\n";
		return 0;
	}

	//checks if input is a prime number
	else if(isPrime(input))
	{
		cout << input << " is a prime number!\n";
		return 0;
	}
	else	//input is greater than 1 and not a prime
	{
		recursiveFactor(input, input);	//calls recursiveFactor function
	}
	return 0;
}

//Purpose: To determine if the int argument is a prime number.

//Parameter: Checking is int from user input.

//Algorithm: Uses a while loop to check the modulus of every
// number between 1 and checking. If modulus of checking and 
// the current factor is 0, then the current factor is a factor
// of checking and returns false. Otherwise, progresses through
// every value until it reaches checking - 1 in which case it
// will return true.
bool isPrime(int checking)
{
	int min = 1;
	int max = checking - 1;
	int test;

	//runs while a factor hasn't been found
	while(max != min)
	{
		test = checking % max;
		if(test == 0)
			return 0;
		else
			max--;		
	}
	return 1;
}

//Purpose: To find the prime factors of the user input number.

//Parameters: Number is a constant variable that never gets
// altered and is persistant through every recursion. I could
// have used a global variable but chose not to. newFactor is
// initially another copy of Number but is the one that gets
// overwritten with the sub-factor after each recursion.

//Algorithm: Recieves two copies of the original user input.
// Starts testing every factor between 1 and Number. Finds
// the smallest factor and then finds the complementary factor.
// Outputs that the smallest prime factor is a factor of Number, then
// runs recursion on the complementary factor. Repeats previous
// steps until it finds the next smallest prime factor(s). Ends
// recursion when there are no more prime factors.
void recursiveFactor(int Number, int newFactor)
{
	//God bless this spaghetti mess

	int isFactor, otherFactor;

	//repeatedly check factors between 2 and newFactor
	for(int factor = 2; factor < newFactor; factor++)
	{
		isFactor = newFactor % factor;

		//if factor is found
		if(isFactor == 0)
		{
			cout << factor << " is a factor of " << Number << endl;
			otherFactor = newFactor / factor;

			//check if the final factor is prime
			if(isPrime(otherFactor))
			{
				cout << otherFactor << " is a factor of " << Number << endl;
				return;
			}			
			//run recursion on complementart factor
			recursiveFactor(Number, otherFactor);
			return;
		}
	}
	return;
}
