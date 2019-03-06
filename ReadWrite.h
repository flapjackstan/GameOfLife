#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Donut.h"

using namespace std;

/*
	A. Action: Reads an array/pointer and prints the array
	B. Arguement/s: Name of the array/pointer and length of the array
*/

void PrintArr_V(char* arr, int length);

/*
	-Author Comments: 
______________________________________________________________________________________________________________________
*/

/*
______________________________________________________________________________________________________________________

	A. Action: Reads a (2D Array) array of pointers and prints the array
	B. Arguement/s: Name of the array/pointer and length of the array
*/

void Print2DArr_V(char** arr, int height, int length);

/*
	-Author Comments: 
______________________________________________________________________________________________________________________
*/

/*
______________________________________________________________________________________________________________________

	A. Action: Reads from a textfile, updates given variables, and *RETURNS* a 2D array
	B. Arguement/s: text file to read
*/

char** Create2DArray_P(string myFile, int &h, int &w);
char** Create2DRandArray(int h, int w, double pop);

/*
	-Author Comments: variables are passed by reference so that they can be updated within the function
______________________________________________________________________________________________________________________
*/



/*
______________________________________________________________________________________________________________________

	A. Action: Reads a char and *RETURNS* an X or - depending on its neighbors (aka the rules)
	B. Arguement/s: a char to evaluate
*/

char DeadOrAliveClassic(Donut &donut, int col, int row);
char DeadOrAliveDonut(Donut &donut, int col, int row);
char DeadOrAliveMirror(Donut &donut, int col, int row);



/*
	-Author Comments:
______________________________________________________________________________________________________________________
______________________________________________________________________________________________________________________

	A. Action: Reads how many neighbors a cells index has and *RETURNS* how many are alive (aka the algorithm)
	B. Arguement/s: A reference to a donut to access and its index [][]
*/

int ReadNeighbors(Donut &donut, int col, int row);
int ReadNeighborsDonut(Donut &donut, int row, int col);
int ReadNeighborsMirror(Donut &donut, int row, int col);

/*
	-Author Comments: A reference is needed because if a donut obj is passed by value, a new donut obj is created
______________________________________________________________________________________________________________________



	A. Action: Reads 2 Donuts and accesses the specific index and modifies it according to appropriate rules
	B. Arguement/s: 2 Donuts, the index being modified
*/

void TransformClassic(Donut &current, Donut &next, int col, int row);
void TransformDonut(Donut &current, Donut &next, int col, int row);
void TransformMirror(Donut &current, Donut &next, int col, int row);


/*
	-Author Comments: A reference is needed because if a donut obj is passed by value, a new donut obj is created
______________________________________________________________________________________________________________________



	A. Action: Reads 2 Donuts and accesses the specific index and modifies it according to appropriate rules
	B. Arguement/s: 
*/

int DonutTopLeftCorner(Donut &donut, int row, int col);
int DonutTopSide(Donut &donut, int row, int col);
int DonutTopRightCorner(Donut &donut, int row, int col);
int DonutLeftSide(Donut &donut, int row, int col);
int DonutCentral(Donut &donut, int row, int col);
int DonutRightSide(Donut &donut, int row, int col);
int DonutBottomLeftCorner(Donut &donut, int row, int col);
int DonutBottomSide(Donut &donut, int row, int col);
int DonutBottomRightCorner(Donut &donut, int row, int col);

int MirrorTopLeftCorner(Donut &donut, int row, int col);
int MirrorTopSide(Donut &donut, int row, int col);
int MirrorTopRightCorner(Donut &donut, int row, int col);
int MirrorLeftSide(Donut &donut, int row, int col);
int MirrorCentral(Donut &donut, int row, int col);
int MirrorRightSide(Donut &donut, int row, int col);
int MirrorBottomLeftCorner(Donut &donut, int row, int col);
int MirrorBottomSide(Donut &donut, int row, int col);
int MirrorBottomRightCorner(Donut &donut, int row, int col);