// multiplyFractions_learncppCh4sec7q2_20181006.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

#include "io.h"

void splash()
{
	using std::cout;
	cout << "I am writing this program primarily as practice exercise to help me learn C++. \n";
	cout << "It is a response to learncpp.com's chapter 4, section 7, question 2. \n";
	cout << "\tVERSION HISTORY\n";
	cout << "\tbegun, written, and completed on 2018 10 06\n\n";
	cout << "2) Create a struct to hold a fraction. The struct should have an integer numerator and an\n";
	cout << "integer denominator member.Declare 2 fraction variables and read them in from the user. Write\n";
	cout << "a function called multiply that takes both fractions, multiplies them together, and prints\n";
	cout << "the result out as a decimal number. You do not need to reduce the fraction to its lowest terms.\n\n";

}

struct Fraction
{
	int numerator{ 1 };
	int denominator{ 1 };
};

Fraction input()
{
	int numerator;
	int denominator;
	static bool isFirst{ true };
	if (isFirst == true)
	{
		std::cout << "First, you'll tell me what the first fraction is... \n";
	}
	else if (isFirst == false)
	{
		std::cout << "Let's get another fraction...\n";
	}
	isFirst = false;
	bool repeat{ false };
	do
	{
		std::cout << "What is the numerator of this fraction? \n";
		std::cin >> numerator;
		std::cout << "Alright, and what's the denominator? \n";
		std::cin >> denominator;
		std::cin.ignore(32767, '\n');
		std::cout << "Lemme make sure I got this right... \n";
		//std::to_string() is an awesome tool fro C++11! see next line
		repeat = !userYesNo("Is " + std::to_string(numerator) + "/" + std::to_string(denominator) + " the fraction you want to use?\n");
		
	} while (repeat == true);
	
	
//	Fraction temp{ numerator,denominator }; //unnecessary to define--just pass values straight through return
	return { numerator, denominator };
}

double multiplyFractions(Fraction x, Fraction y)
{
	
	double newNumerator = static_cast<double>(x.numerator) * static_cast<double>(y.numerator);
	double newDenominator = static_cast<double>(x.denominator) * static_cast<double>(y.denominator);
	double product{ newNumerator / newDenominator };
	std::cout << x.numerator << "/" << x.denominator << " * " << y.numerator << "/" << y.denominator << " = "
		<< newNumerator << "/" << newDenominator << " = " << product << "\n";
	return product;
}

int main()
{
	splash();

	bool repeat{ false };
	do
	{
		multiplyFractions(input(), input());
		repeat = (userYesNo("Do you want to multiply another pair of fractions?\n"));
	} while (repeat == true);

	std::cout << "Thanks for testing my program!  Hope it was as helpful for you as it is for me! See ya later!\n";
	return 0;
}

