/****************PigLatin.cpp**************/
//Author: Aaron Brunette
//Github: abrunette
//Last updated: 2018/02/18
//Compiled with g++
//Written on Vim
//Purpose: Convert English words to Pig Latin. 
/***************************************/

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

void getWord(string&);
bool checkWord(string);
bool cons(char);

char vowels[5] = {'a','e','i','o','u'};

//cons(w) -> (w)con(ay)
//
//cons-cons(w) -> (w)cons-cons(ay)
//
//vow -> vow(w)(ay)

//Purpose:
//User information:
//Algorithm:  (if needed)
//Input:  (if needed)
//Output: (if needed)
int main()
{
	printf("This program will convert individual words into Pig Latin.\n\n");

	string theWord, hold;

	getWord(theWord);

	while(!checkWord(theWord))
	{
		printf("%s is not valid.\n", theWord.c_str());
		getWord(theWord);
	}
	
	if(cons(theWord[0]))	//cons
	{
		hold = theWord[0];
		theWord += hold;
		theWord.erase(0,1);
	}
	if(cons(theWord[0]))	//cons cons
	{
		hold = theWord[0];
		theWord += hold;
		theWord.erase(0,1);
	}
	theWord.append("ay", 2);	//ay is always appended last

	printf("Your word has been converted: %s\n\n", theWord.c_str());

	return 0;
}

//Purpose: Gets word from user and passes by reference.
//Parameters: Reference string
//Input: User input
void getWord(string &getting)
{
	printf("Please enter the word you want to convert: ");
	getline(cin, getting);
	cout << endl;
}

//Purpose: To check if the word contains any invalid characters.
//Parameters: checking is the word being checked
//Algorithm: loops through each character checking if it's alphabetic
//Output: returns if the word is valid
bool checkWord(string checking)
{
	if(checking.empty())	//empty string
		return false;

	for(int i = 0; i < checking.size(); i++)
	{
		if(!isalpha(checking[i]))	//if not alphabetic
			return false;
	}
	return true;	//alphabetic
}

//Purpose: Checks if the first two chars are consonants
//Parameters: compareThis is the char being compared
//Algorithm: Loops and compares char to an array of vowels
//Output: Returns if char is cons or vowel
bool cons(char compareThis)
{
	for(int count = 0; count < 5; count++)
	{
		if(compareThis != vowels[count])
			return false;	//vowel
	}
	return true;	//consonant
}
