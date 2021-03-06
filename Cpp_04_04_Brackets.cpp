// Cpp_04_04_Brackets.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <string>
#include <vector>
#include<sstream>
#include <map>


int main()
{
	std::string inputStr = "";
	getline(std::cin, inputStr);
	std::vector<char> brackets = { '{', '[', '(' };
	std::vector<int> ocurences = { 0, 0, 0 };
	std::vector<char> bracketsInput;
	std::istringstream iss(inputStr);
	char bracket;
	while (iss >> bracket)
	{
		bracketsInput.push_back(bracket);
	}

	////CHECK:
	//std::cout << "CHAR input vector = ";
	//for (int i = 0; i < bracketsInput.size(); i++)
	//{
	//	std::cout << bracketsInput[i] << ' ';
	//}
	//std::cout << "\n";	

	int k = 0;

	for (std::vector<char>::iterator it = bracketsInput.begin(); it != bracketsInput.end(); it++)
	{
		char s = bracketsInput[k];
		switch (s)
		{
		case '{':
			ocurences[0]++;
			break;
		case '[':
			ocurences[1]++;
			break;
		case '(':
			ocurences[2]++;
			break;
		case '}':			
			ocurences[0]--;
			if (ocurences[0] < 0 || ocurences[1] % 2 != 0 || ocurences[2] % 2 != 0)
			{
				std::cout << "invalid" << std::endl;
				return 0;
			}
			break;
		case ']':
			ocurences[1]--;
			if (ocurences[1] < 0 || ocurences[2] % 2 != 0)
			{
				std::cout << "invalid" << std::endl;
				return 0;
			}
			break;
		case ')':
			ocurences[2]--;
			if (ocurences[2] < 0 )
			{
				std::cout << "invalid" << std::endl;
				return 0;
			}
			break;
		}
		k++;
	}
	if (ocurences[0] != 0 || ocurences[1] != 0 || ocurences[2] != 0)
	{
		std::cout << "invalid" << std::endl;
		return 0;
	}
	std::cout << "valid" << std::endl;
	return 0;
}

