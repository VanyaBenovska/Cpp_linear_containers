// Cpp_04_03_Merge_Trains_LISTs_even_odd.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<sstream>
#include <functional>
#include <vector>
#include <list>
#include<list>

int main()
{
	std::list<int> li1;
	std::list<int> li2;

	std::string inputLine1 = "", inputLine2 = "";
	getline(std::cin, inputLine1);
	std::istringstream iss11(inputLine1);
	int number1 = 0;
	while (iss11 >> number1)
	{
		li1.push_back(number1);
	}

	getline(std::cin, inputLine2);
	std::istringstream iss22(inputLine2);
	int number2 = 0;
	while (iss22 >> number2)
	{
		li2.push_back(number2);
	}

	std::vector<char> ab;
	for (std::list<int>::iterator it = li2.begin(); it != li2.end(); it++)
	{
		if (*it % 2 == 0)
		{
			ab.push_back('B');
		}
		else
		{
			ab.push_back('A');
		}
	}
	
	int r = 0, c = 0;
	for (std::list<int>::iterator row = li1.begin(); row != li1.end(); row++)
	{
		for (std::list<int>::iterator col = li2.begin(); col != li2.end(); col++)
		{
			if (*row > *col)
			{
				li2.insert(col, *row);
				if (*row % 2 == 0)
				{
					ab.insert(ab.begin() + c, 'B');
				}
				else
				{
					ab.insert(ab.begin() + c, 'A');
				}
				break;
			}
			c++;
		}
		int num = li2.back();
		if (*row < num)
		{
			li2.push_back(*row);
			if (*row % 2 == 0)
			{
				ab.push_back('B');
			}
			else
			{
				ab.push_back('A');
			}			
		}
		r++;
	}

	for (auto it = ab.begin(); it != ab.end(); it++)
	{
		std::cout << *it << ' ';
	}
	std::cout << std::endl;

	for (auto it = li2.begin(); it != li2.end(); it++)
	{
		std::cout << *it << ' ';
	}
	std::cout << std::endl;

	return 0;
}
