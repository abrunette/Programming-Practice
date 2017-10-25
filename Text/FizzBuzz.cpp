/*****************FizzBuzz.cpp**************/
//Author: Aaron Brunette
//Github: abrunette
//Last updated: 2017/10/24
//Compiled with g++
//Written on Vim
//Purpose: Prints out numbers 1 to 100
// if the number is a multiple of 3, prints Fizz
// if the number is a multiple of 5, prints Buzz
// if the number is a multiple of both, prints FizzBuzz
/***************************************/

#include <stdio.h>
using namespace std;

//Purpose: Prints out values
//User information: Run the program
int main()
{
	for(int i = 1; i <= 100; i++)
	{
		if((i % 3) == 0)
		{
			if((i % 5) == 0)
				printf("FizzBuzz\n");
			else
				printf("Fizz\n");
		}
		else if((i % 5) == 0)
			printf("Buzz\n");
		else
			printf("%d \n", i);
	}
}
