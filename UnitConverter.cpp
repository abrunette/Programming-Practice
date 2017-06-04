/*****************UnitConverter.cpp**************/
//Author: Aaron Brunette
//Github: abrunette
//Last updated: 2017/06/03
//Compiled with g++
//Written on Vim
//Purpose: To accurately convert between several different units.
/***************************************/

#include <iostream>	//input/output library
#include <string>	//string data type
#include <vector>	//vector data structure
using namespace std;

/*	TODO LIST	*/
//create text files for the different conversion methods, 4 total, read contents into vectors for validation
//Allow user to look at previous conversions
//change vector search to something more efficient
//make user input safer
//allow user to exit program at any time, i.e. input -1 at any time to exit

//Global Variables (Possible move this into main and pass it into functions)
int currentConversion = -1;
//-1 = no conversion
//0 = Temperature
//1 = Money
//2 = Volume
//3 = Mass

//Function prototypes
void initializeVectors();			//create vectors with valid words
void convTemp();
void convMoney();
void convVolume();				//convert volume
void convMass();				//convert masses
int validateConversion(string);			//determine if conversion type is a valid word, returns 0-3
bool validateUnites(int, double);
void whichConversion();				//determine what the user is converting
double unitInput();				//takes user input of the units, returns units after validation
void determineEquation(int, double);		//determines which equation will be used

//Function prototypes for searching vectors
bool searchTVector(string);
bool searchCVector(string);
bool searchvVector(string);
bool searchMVector(string);



//Purpose: To initialize the word validation vectors and call the relevent functions
//User information: TBD
//Algorithm:  (if needed)
//Input:  (if needed)
//Output: (if needed)
int main()
{
	//Welcome screen
	cout << "This is a simple unit conversion program.\n
		It can currently convert Temperature, Money, Volume, and Mass.\n
		First, select which unit you would like to convert: ";
	
	whichConversion();

	initializeVectors();
}

//Purpose: To initialize the vectors used to determine if words are valid 
//Parameters: None
//Algorithm: Linear search through vector (WIP)
//Input:
//Output: 
void initializeVectors()
{
	//These might need to be in main or be global vectors
	vector<string> TemperatureVec;
	vector<string> MoneyVec;
	vector<string> VolumeVec;
	vector<string> MassVec;

}

//Purpose: To determine which conversion the user wants to use.
//Parameters: None
//Algorithm: While loop
//Input:
//Output: None
void whichConversion()
{
	string conversionInput	

	cin >> conversionInput;

	while(cin.fail || validateConversion(conversionInput) == -1)
	{
		if(validateConversion(conversionInput) == -1)
		{
			cout << "\nPlease enter a valid conversion format: ";
			cin >> conversionInput;
		}
		else
		{
			cout << "\nPlease enter a valid word: ";
			cin >> conversionInput;
		}
	}

}

//Purpose: To call the functions to search the respective vectors for valid words.
//Parameters: toValidate is the string that is being searched for in the vectors.
//Algorithm:
//Input:
//Output:
int validateConversion(string toValidate)
{
	if(searchTVector(toValidate))	//if result is found in temperature vector
		return 0;	

	else if(searchCVector(toValidate))	//if result is found in money vector
		return 1;

	else if(searchvVector(toValidate))	//if result is found in volume vector
		return 2;

	else if(searchMVector(toValidate))	//if result is found in mass vector
		return 3;
	
	else	//not found in any vectors
		return -1;
}

//Purpose: Search through the temperature vector to determine if the passed value exists
//Parameters: Tsearch is the string being searched for
//Algorithm:
//Input: None
//Output: None
bool searchTVector(string Tsearch)
{

}

//Purpose: Search through the money vector to determine if the passed value exists
//Parameters: Csearch is the string being searched for
//Algorithm:
//Input: None
//Output: None
bool searchCVector(string Csearch)
{

}

//Purpose: Search through the volume vector to determine if the passed value exists
//Parameters: Vsearch is the string being searched for
//Algorithm:
//Input: None
//Output: None
bool searchvVector(string Vsearch)
{

}

//Purpose: Search through the mass vector to determine if the passed value exists
//Parameters: Msearch is the string being searched for
//Algorithm:
//Input: None
//Output: None
bool searchMVector(string Msearch)
{

}













/*
int main()
{
	validateInput(-1, NULL, NULL);	//initialize vectors

	string convType;
	int ConvCheck = -1;

	cout << "This program is a unit converter. It can currently convert:\n
		Temperature\nMoney\nVolume\nMass\n\n";

	cout << "Please enter the coversion type you want to use from the list above, or type 0 to end the program: ";
	cin >> convType;

	while(ConvCheck == -1)
	{
		switch(convType)
		{
			case 0: 
				cout << "Ending program...\n\n";
				ConvCheck = 1;
				break;
	
			case Temperature:
				cout << "You are converting temperature.";
				convTemp();
				return 0;

			case Money:
				cout << "You are converting money.";
				convMoney;
				return 0;

			case Volume:
				cout << "You are converting volume.";
				convVolume();
				return 0;

			case Mass:
				cout << "You are converting mass.";
				convMass();
				return 0;	

			default:
				cout << "You have entered an invalid choice.\n
					Please try again. Your choices are: \n
					0, Temperature, Money, Volume, Mass.\n\n";
		}
	}

	return 0;
}

bool validWord(int method, string SearchValue)
{

}

void convTemp()
{
	string FTempReq;
	double FTemp;
	string STempReq;
	double STemp;

	cout << "This program can convert between Fahrenheit, Celsius, and Kelvin.\n
		Please type what you are converting from: ";
	cin >> FTempReq;
	cout << "\n\n";
	
	while(FTempReq != "Fahrenheit" || FTempReq != "Celsius" || FTempReq != "Kelvin")
	{
		cout << "Please enter a valid temperature format: ";
		cin >> FTempReq;
		cout << "\n\n";
	}

	cout << "Please enter the temperature in " << FTempReq << ": ";
	cin >> FTemp;

	while(cin.fail())
	{
		cout << "Please enter a valid temperature: ";
		cin >> FTemp;
		cout << "\n\n";
	}

	cout << "Please enter what you are converting to: ";
	cin >> STempReq;
	cout << "\n\n";

	while(STempReq != "Fahrenheit" || STempReq != "Celsius" || STempReq != "Kelvin")
	{
		cout << "Please enter a valid temperature format: ";
		cin >> STempReq;
		cout << "\n\n";	
	}

	cout << "Please enter the temperature in " << STempReq << ": ";
	cin >> STemp

	while(cin.fail())
	{
		cout << "Please enter a valid temperature: ";
		cin >> STemp;
		cout << "\n\n";
	}

	
}
	
void convMoney()
{

}

void convVolume()
{

}

void convMass()
{

}

*/
