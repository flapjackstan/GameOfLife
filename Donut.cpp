#include "Donut.h"
#include "ReadWrite.h"
#include <iostream>
#include <fstream>

using namespace std;

Donut::Donut()
{
	cout << "You created an empty Donut";

	//
}

Donut::~Donut()
{
	cout << "\nDonut Deleted\n";

	for (int i = 0; i < colSize; i++)

      {
        delete[] array[i];
      }

    array = 0; //restting pointer to 0;
}

Donut::Donut(char** TDArray, int userRows, int userCols)
{

	array = TDArray;
	rowSize = userRows;
	colSize = userCols;
	cout << "\nDonut Created\n";
}

void Donut::printDonut()
{	
	Print2DArr_V(array, colSize, rowSize);
}

char** Donut::CreateNextGen_P()
{

	nextArray = new char*[colSize];
	for (int i = 0; i < colSize; i++)
	{
		nextArray[i] = new char[rowSize];

		for (int j = 0; j < rowSize; j++)
		{
			nextArray[i][j] = array[i][j];
		}
	}

	return nextArray;
}

void Donut::WriteToFile(string newFile)
{
	ofstream outFileStream;
	outFileStream.open(newFile,fstream::app);
	for(int i = 0; i < colSize; i++)
	{
		for(int j = 0; j < rowSize; j++)
		{
			outFileStream << array[i][j];
		}
			outFileStream << endl;
	//outFileStream.write(array[i] ,rowSize);
	}
	outFileStream.close();
}
