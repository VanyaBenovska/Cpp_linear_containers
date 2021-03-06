// Cpp_04_03_Merge_Trains_even_odd.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<sstream>
#include <functional>
#include <vector>
#include<cstdlib>

int main()
{
	std::vector<int> intDataA;
	std::vector<int> intDataB;


	std::string inputFirstLine = "", inputSecondLine = "";
	getline(std::cin, inputFirstLine);
	std::istringstream iss1(inputFirstLine);
	int number = 0;
	while (iss1 >> number)
	{
		intDataA.push_back(number);
	}

	getline(std::cin, inputSecondLine);
	std::istringstream iss2(inputSecondLine);
	int numberA = 0, numberB = 0;
	while (iss2 >> number)
	{
		intDataB.push_back(number);
	}

	std::vector<int> intOrderedData;
	std::vector<char> ab;


	int r = 0, c = 0;

	int temp = intDataA[r];
	int sumBothSizes = intDataA.size() + intDataB.size();
	for (int i = 0; i < sumBothSizes; i++) {

		if (intDataA.size() == NULL)
		{
			for (int y = 0; y < intDataB.size(); y++)
			{
				intOrderedData.push_back(intDataB[y]);
				if (intDataB[y] % 2 == 0)
				{
					ab.push_back('B');
				}
				else
				{
					ab.push_back('A');
				}
				i++;
			}
		}
		else if (intDataB.size() == NULL)
		{
			for (int y = 0; y < intDataA.size(); y++)
			{
				intOrderedData.push_back(intDataA[y]);
				if (intDataA[y] % 2 == 0)
				{
					ab.push_back('B');
				}
				else
				{
					ab.push_back('A');
				}
				i++;
			}
		}
		else if (intDataA[0] > intDataB[0])
		{
			intOrderedData.push_back(intDataA[r]);
			if (intDataA[r] % 2 == 0)
			{
				ab.push_back('B');
			}
			else
			{
				ab.push_back('A');
			}
			intDataA.erase(intDataA.begin());
		}
		else
		{
			intOrderedData.push_back(intDataB[c]);
			if (intDataB[c] % 2 == 0)
			{
				ab.push_back('B');
			}
			else
			{
				ab.push_back('A');
			}
			intDataB.erase(intDataB.begin());
		}
	}

	for (char item : ab)
	{
		std::cout << item;
	}
	std::cout << std::endl;

	for (int i = 0; i < intOrderedData.size(); i++)
	{
		std::cout << intOrderedData[i] << ' ';
	}
	std::cout << std::endl;

	return 0;
}

