/*****************FloorCost.cpp**************/
//Author: Aaron Brunette
//Github: abrunette
//Last updated: 2017/02/23
//Compiled with G++
//Written on Vim
//Purpose: To calculate the cost of a floorplan
//with given cost and size.
/********************************************/

#include <iostream>	//input/output library
#include <iomanip>	//input/output manipulation library
using namespace std;

//declare calculateTotal function
double calculateTotal(double, double, double);

//Purpose: To recieve user input regarding the width, height,
// and cost of a floor plan. It then calls a function to 
// calculate the total cost to tile the floor plan.
//User information: Run the program.
//Input: Takes three positive numbers, width, height, and cost.
//Output: Outputs the combined total of the three previous values.
int main()
{
	double width, height, cost;	

	cout << "Please enter the width of the floor plan (ft): ";
	cin >> width;
	cout << "\nPlease enter the height of the floor plan (ft): ";
	cin >> height;
	cout << "\nPlease enter the cost per square foot for flooring ($): ";
	cin >> cost;

	double finalCost = calculateTotal(width, height, cost); 

	cout << "The cost to tile a floor plan of " 
	     << width << "x" << height << " is $" 
	     << setprecision(2) << fixed
	     << finalCost << " at " << cost 
	     << " per square foot.\n";

	return 0;
}

//Purpose: To calculate the total cost needed to tile
// a floor of W width, and H height, at C cost.
//Parameters: W is width, H is height, C is cost.
//Algorithm: Multiplication of 3 variables. Returns immediately.
double calculateTotal(double W, double H, double C)
{
	return ((W * H) * C);
}
