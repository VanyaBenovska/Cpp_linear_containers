// Cpp_04_01_Compare_Matrices.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <vector>
#include <string>
#include<sstream>

bool AreEqual(int arrayFirstMatrix[][10], int arraySecondMatrix[][10], int rows, int cols);

const int maxSize = 10;

int main()
{
	//std::vector<int arr[]> data; //NOT POSSIBLE!!!!
	int arrayFirstMatrix[maxSize][maxSize] = { {0} };
	std::string strNumber;
	std::getline(std::cin, strNumber);
	unsigned int rowsFirstMatrix = 0;
	std::istringstream iss(strNumber);
	iss >> rowsFirstMatrix;
	
	std::string row = "";
	int number = 0;
	int cols = 0;
	int colsFirstMatrix = 0;

	for (int r = 0; r < rowsFirstMatrix; r++)
	{
		getline(std::cin, row);
		std::istringstream iss(row);
		while (iss >> number)
		{
			arrayFirstMatrix[r][cols] = number;
			cols++;
		}
		colsFirstMatrix = cols;
		cols = 0;
	}

	int arraySecondMatrix[maxSize][maxSize] = { { 0 } };	
	std::getline(std::cin, strNumber);
	unsigned int rowsSecondMatrix = 0;
	std::istringstream iss2(strNumber);
	iss2 >> rowsSecondMatrix;

	row = "";
	number = 0;
	cols = 0;
	int colsSecondMatrix = 0;

	for (int r = 0; r < rowsSecondMatrix; r++)
	{
		getline(std::cin, row);
		std::istringstream iss(row);
		while (iss >> number)
		{
			arraySecondMatrix[r][cols] = number;
			cols++;
		}
		colsSecondMatrix = cols;
		cols = 0;
	}
		
	if (rowsFirstMatrix != rowsSecondMatrix)
	{
		std::cout << "not equal" << std::endl << std::endl;
	}
	else if (colsFirstMatrix != colsSecondMatrix)
	{
		std::cout << "not equal" << std::endl << std::endl;
	}
	else
	{
		if (AreEqual(arrayFirstMatrix, arraySecondMatrix, rowsFirstMatrix, colsFirstMatrix))
		{
			std::cout << "equal" << std::endl << std::endl;
		}
		else
		{
			std::cout << "not equal" << std::endl << std::endl;
		}
	}
	return 0;
}

bool AreEqual(int arrayFirstMatrix[][10], int arraySecondMatrix[][10], int rows, int cols)
{
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			if (arrayFirstMatrix[r][c] != arraySecondMatrix[r][c])
			{
				return false;
			}
		}
	}
	return true;
}