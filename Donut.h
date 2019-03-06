#pragma once 

#include <iostream>
#include <fstream>


using namespace std;

class Donut
{
public:
	Donut();
	Donut(char** TDArray, int userRows, int userCols);
	~Donut();

	void printDonut();
	char** CreateNextGen_P();
	void WriteToFile(string newFile);

	char** array;
	char** nextArray;

	int rowSize;
	int colSize;
	double popDensity;
};