/*****************filename**************/
//Author: Aaron Brunette
//Github: abrunette
//Last updated: 2017/10/05
//Compiled with gcc
//Written on vim
//Purpose: Performs the collatz conjecture
// on an integer.
/***************************************/

#include <iostream>
using namespace std;

//function declaration
void applyCollatz(int);

//Purpose: Get an integer n, and call applyCollatz
//User information: input a positive whole number
//Input: an integer n
int main()
{
	int n;
	cout << "Please enter a positive whole number: ";
	cin >> n;

	while(cin.fail())
	{
		cout << "Please enter a positive whole number: ";
		cin >> n;
	}
	cout << "Starting N: " << n << endl;

	applyCollatz(n);

	return 0;
}

//Purpose: To recusively apply the collatz conjecture
// to an integer until the integer becomes 1.
//Parameters: the integer num
//Algorithm: collatz
//Output: outputs numbers generated through collatz
// also tells whether it went odd or even.
void applyCollatz(int num)
{
	if((num % 2) == 0)	//even
	{
		cout << "EVEN\n";
		num = num / 2;
		
	}
	else	//odd
	{
		cout << "ODD\n";
		num = (3 * num) + 1;
	}

	cout << "Num: " << num << endl;

	if(num != 1)	//recursion
		applyCollatz(num);

	return;
}
