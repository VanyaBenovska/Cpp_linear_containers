// Cpp_04_02_Positions_Of.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <vector>
#include <string>
#include<sstream>

void PrintPositionOfAppearance(int arrayMatrix[100][100], int rows, int cols, int number);

const int maxSize = 100;

int main()
{
	int arrayMatrix[maxSize][maxSize] = { { 0 } };
	std::string strRowsAndCols;
	std::getline(std::cin, strRowsAndCols);
	unsigned int rows, cols;
	std::istringstream iss(strRowsAndCols);
	iss >> rows >> cols;	

	for (int r = 0; r < rows; r++)
	{
		std::string row = "";
		getline(std::cin, row);
		std::istringstream iss(row);
		
		for (int c = 0; c < cols; c++) {
			int num;
			iss >> num;
			arrayMatrix[r][c] = num;
		}
	}

	int number;
	std::cin >> number;

	PrintPositionOfAppearance(arrayMatrix, rows, cols, number);

	return 0;
}

void PrintPositionOfAppearance(int arrayMatrix[100][100], int rows, int cols, int number)
{
	bool isFound = false;
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			if (arrayMatrix[r][c] == number)
			{
				std::cout << r << ' ' << c << std::endl;
				isFound = true;
			}
		}
	}
	if(!isFound)
	{
		std::cout << "not found" << std::endl;
	}
	std::cout << std::endl << std::endl;
}

