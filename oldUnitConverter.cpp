//Author's Note:
// My ambitions for this project got a bit larger than I am likely capable of doing at this time.
// I will probably keep this on the chance that I become able to implement the ideas I had.
// I will most likely redo this with a more simple approach that doesn't cover as many edge cases.
// It was a good startup project that helped me realize that proper structuring prior to coding is important.
// It has definitely encouraged me to continue learning more about programming.

/*****************UnitConverter.cpp**************/
//Author: Aaron Brunette
//Github: abrunette
//Last updated: 2017/06/03
//Compiled with g++
//Written on Vim and Caret
//Purpose: To accurately convert between several different units.
//Authors notes: This is needlessly complicated...
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
//possibly a better way to validate conversion, if valid words overlap at all there could be collision errors
//ask users if they meant a different word, similar to google smart search
//possibly move global variable into memory file? could also store past conversions in there, cache of sorts
//make sure to clear cache if implemented
//web scraper for money rates, if implemented would need networking errors for server disconnect or no access
//make sure global vectors are read only
//combine the vectors VolumeUVec and MassUVec if they have the same units, m^2

//Global Variables (Possible move this into main and pass it into functions)
int currentConversion = -1;
string conversionName = "None";
//-1 = no conversion
//0 = Temperature
//1 = Money
//2 = Volume
//3 = Mass

//Global Vectors, read only
vector<string> TemperatureVec;  //hold words for temperature
vector<string> TemperatureUVec; //holds words for units of temperature
vector<string> MoneyVec;        //holds words for money
vector<string> MoneyUVec;       //holds words for units of money
vector<string> VolumeVec;       //holds words for volume
vector<string> VolumeUVec;      //holds words for units of volume
vector<string> MassVec;
vector<string> MassUVec;

//Function prototypes
void initializeVectors();				//create vectors with valid words
void convTemp();						//converts temperature
void convMoney();						//converts money
void convVolume();						//convert volume
void convMass();						//convert masses
void validateConversion(string);			//determine if conversion type is a valid word, temp, money, etc
void validateConvUnits(string);       //determine if conversion units is a valid word, kelvin, celsius, etc
bool validateUnits(double);		//determines if the unit values entererd are valid
void whichConversion();					//determine what the user is converting
double unitInput();						//takes user input of the units, returns units after validation
void determineEquation(double);	//determines which equation will be used

//Function prototypes for searching vectors
bool searchConvVector(string);  //search for main conversion types
bool searchTVector(string); //temp
bool searchCVector(string); //money
bool searchvVector(string); //volume
bool searchMVector(string); //mass

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
	
	initializeVectors();
	
	whichConversion();
	
	double TheUnits = unitInput();
	
	determineEquation(TheUnits);
	
	//end of program?
	return 0;
}

//Purpose: To initialize the vectors used to determine if words are valid
//Parameters: None
//Algorithm: None
//Input: None
//Output: None
void initializeVectors()
{
	//These might need to be in main or be global vectors
  //definitely need to be global or main, these are local
  //vectors right now
	
  //might need to separate out these vectors more
  //two different vectors for each conversion type
  //hold valid conversion types, temp, money, etc
  //second will hold valid
}

//Purpose: To determine which conversion the user wants to use.
//Parameters: None
//Algorithm: While loop
//Input:
//Output: None
void whichConversion()
{
	string conversionInput; //user input

	cin >> conversionInput;
  
  //while input is invalid type or word does not exist
	while(cin.fail || validateConversion(conversionInput) == -1)
	{
		if(validateConversion(conversionInput) == -1) //word does not exist
		{
			cout << "\nPlease enter a valid conversion format: ";
			cin >> conversionInput;
		}
		else  //invalid type, cin.fail
		{
			cout << "\nPlease enter a valid word: ";
			cin >> conversionInput;
		}
	}
  return;
}

//Purpose: To call the functions to search the respective vectors for valid words.
//Parameters: toValidate is the string that is being searched for in the vectors.
//Algorithm:
//Input:
//Output:
void validateConversion(string toValidate)
{
	if(searchTVector(toValidate))	//if result is found in temperature vector
	{
	  currentConversion = 0;
    conversionName = "Temperature";
	}
	
	else if(searchCVector(toValidate))	//if result is found in money vector
	{
	  currentConversion = 1;
    conversionName = "Money";
	}

	else if(searchvVector(toValidate))	//if result is found in volume vector
  {
		currentConversion = 2;
		conversionName = "Volume";
  }

	else if(searchMVector(toValidate))	//if result is found in mass vector
  {
		currentConversion = 3;
    conversionName = "Mass";
  }
  
	else	//not found in any vectors
		currentConversion = -1;
}

void validateConvUnits(string toValidate)
{
  
}

//Purpose:
//Parameters:
//Algorithm:
//Input:
//Output:
double unitInput()
{
  double InputUnits = 0.0;
  
  cout << "You are converting " << conversionName << ".\n";
  
  switch(conversionType)
  {
    case 0: //temp
      cout << "Please input the temperature type you wish to convert.\n
      Valid types are Fahrenheit, Celsius, and Kelvin.\n
      Decimals are ok.\n\n";
              
      cin >> InputUnits;
      
      //while type is invalid or fails something else in validation
      while(cin.fail || validateUnits(InputUnits) == -1)
      {
        if(cin.fail)  //type is invalid
        {
          cout << "Please enter a valid word.\n";
          cin >> InputUnits;
        }
        
        //calling the function a second time seems inefficient, also done above
        //should probably just assign result to a variable
        else if(validateUnits(InputUnits) == -1)  //fails validation
        {
          //error message to determine why it failed validation, perror?
        }
      }
      
      //units are valid
      return InputUnits;
      
    case 1: //money
      cout << "Please input the currency you wish to convert
      
    case 2: //volume
    
    case 3: //mass
    
    default:  //error
      //error message, this should never happen though
      return -1;
  }
}
//Purpose: Determine which equation needs to be used
//Parameters:
//Algorithm:
//Input:
//Output:
void determineEquation(someUnits)
{
  //this is going to be hard to make
  //possibly use a vector for this?
  //vector would need to be 3D, to and from unit type as well as equation
}
//Purpose:
//Parameters:
//Algorithm:
//Input:
//Output:
bool validateUnits(UtoValidate)
{
  //make sure temperature never goes beyond absolute zero
  //money, volume, mass should not be negative
  //upper limit on input to make sure computation doesn't get out of hand?
}
//Purpose: Search through the conversion type vector to determine if the passed value exists
//Parameters:
//Algorithm:
//Input:
//Output:
bool searchConVector(string Consearch)
{
  
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