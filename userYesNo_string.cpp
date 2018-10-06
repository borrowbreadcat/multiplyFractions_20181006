
#include "stdafx.h"
#include <iostream>
#include <string>

bool userYesNo(std::string question)
{
	bool YesOrNo{ false };
	bool isValid{ false };
	std::string userInput{ "default" };
	do
	{
		std::cout << question;
		std::getline(std::cin, userInput);
		if (userInput == "yes" || userInput == "y" || userInput == "Yes" || userInput == "YES" || userInput == "Y")
		{
			YesOrNo = true;
			isValid = true;
			std::cout << "Okay!\n";
		}
		else if (userInput == "no" || userInput == "n" || userInput == "No" || userInput == "NO" || userInput == "N")
		{
			YesOrNo = false;
			isValid = true;
			std::cout << "No?\n";
		}
		else
		{
			isValid = false;
			std::cout << "Just a simple 'yes' or 'no' will do, please.  Let's try again... \n";
		}
	} while (isValid == false);
	
	return YesOrNo;
}
