/*****************FizzBuzz.cpp**************/
//Author: Aaron Brunette
//Github: abrunette
//Last updated: 2018/02/12
//Compiled with g++
//Written on Vim
//Purpose: Prints out numbers 1 to 100
// if the number is a multiple of 3, prints Fizz
// if the number is a multiple of 5, prints Buzz
// if the number is a multiple of both, prints FizzBuzz
/***************************************/

#include <stdio.h>
#include <string>
using namespace std;

//Purpose: Prints out values
//User information: Run the program
int main()
{	
	for(int i = 1; i <= 100; i++)
	{
		string out = "";
		
		if(!(i % 3))
			out.append("Fizz");
		if(!(i % 5))
			out.append("Buzz");
		
		if(out.empty())
			printf("%d \n", i);
		else	
			printf("%s \n", out.c_str());
	}
}
