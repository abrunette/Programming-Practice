/*****************palindrome.cpp**************/
//Author: Aaron Brunette
//Github: abrunette
//Last updated: 2018/02/12
//Compiled with g++
//Written on Vim
//Purpose: To detect whether a string is a palindrome.
/***************************************/

#include <iostream> //input/output library
#include <cstdio> //C input/output library
#include <string> //string data type
using namespace std;

//Purpose: Determine if there is a character
// mismatch between opposite characters in
// the string.
//Parameters: Gets user input string.
//Algorithm: Compares opposite characters in
// a string one by one. Checks for mismatched
// characters and returns false, else true.
//Outputs: Returns true or false.
bool palindromedesuka(string toCheck)
{
	int mid = toCheck.length()/2;
	int front = 0;
	int back = toCheck.length() - 1;

	while(front != mid)
	{
		if(toCheck[front] != toCheck[back])
			return 0;
		
		front++;
		back--;
	}
	return 1;
}

//Purpose: To get the string from the user.
//User information: Run the program and input a string.
//Input: User input.
//Output: Outputs results to screen, is or is not a palindrome.
int main()
{
	string checkThis;

	printf("Input a word and I will tell you if it is a palindrome: ");
	getline(cin, checkThis);

	//input checking?

	if(checkThis.length() == 1)
		printf("%s is a palindrome", checkThis.c_str());
	
	if(palindromedesuka(checkThis))	//true
		printf("%s is a palindrome.\n", checkThis.c_str());
	else	//false
		printf("%s is not a palindrome.\n", checkThis.c_str());

	return 0;
}
