// TestChocolateBox.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ChocolateBox.h"
using namespace std;

int main(){

    //Calls the default constructor 

    ChocolateBox cBox;
	cout << "Chocolates in cBox= " << endl;
    cout << cBox << endl;

    ChocolateBox cBoxOne(cBox);
    
    cout << "Now, you can fill Box One with your favorite truffles: " << endl;
    cin >> cBoxOne;

	cout << endl;
	cout << "Chocolates in cBoxOne= " << endl;
    cout << cBoxOne << endl;

	ChocolateBox cBoxTwo(2, 2, Chocolate("Milk White"));

	cout << "Chocolates in cBoxTwo= " << endl;
	cout << cBoxTwo << endl;
	                                                      // can modify Chocolate entries now!
	ChocolateBox cBoxThree = cBoxOne + cBoxTwo;       //adds two ChocolateBox
	cout << "Chocolates in cBoxThree = " << endl;
	cout << cBoxThree << endl;
	
	cout << " \"1\"  will be printed if chocolates in cBoxOne and cBoxTwo are equal" << endl;
	cout << (cBoxOne == cBoxTwo) << endl; //if all chocolates in a box are of the same type
	
	if (!cBoxThree)
		cout << "It is not \"Butterscotch Walnut\"!" << endl; //if all chocolates in the box is of type "Butterscotch Walnut", then returns true
	else
		cout << "It is \"Butterscotch Walnut\"." << endl;

	ChocolateBox cBoxFour;               //Creates a ChocolateBox with the default constructor

	cBoxFour = move(cBoxTwo);                              //moves cBoxtwo to cBoxFour
	cout << "Chocolates in cBoxFour= " << endl;
	cout << cBoxFour << endl;
	ChocolateBox cBoxFive = std::move(cBoxOne);         //moves cBoxOne to cBoxFive
	cout << "Chocolates in cBoxFive= " << endl;
	cout << cBoxFive << endl;

	cout << "Chocolates in cBoxOne= " << endl;
	cout << cBoxOne << endl;
	
	cout << "Chocolates in cBoxTwo= " << endl;
	cout << cBoxTwo << endl;
   
}
