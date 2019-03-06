#include <iostream>
#include <fstream> //getline
#include <string>  //stoi
#include "ReadWrite.h" 
#include "Donut.h"
#include <ctime>
#include <cmath>



using namespace std;


//	A. Action: Reads an array/pointer and prints the array
//	B. Arguement/s: Name of the array/pointer and length of the array


void PrintArr_V(char* arr, int length)
{
	//cout << "\nPrinting Array\n";
	for (int i = 0; i < length; i++)
	{
		//cout <<"Row: " << i << " " << arr[i] << "\n";
		cout << arr[i];
	}
	//cout << "\nFinished Printing\n";
	cout << "\n";
}


// A. Action: Reads an pointer to an array/pointer and prints the array
// B. Arguement/s: Name of the pointer to the array/pointer, number of arrays held in array, and length of the arrays within the array


void Print2DArr_V(char** arr, int height, int length)
{
	cout <<"\n";
	for (int i = 0; i < height; i++)
    {
        //cout <<"\nRow " << i << ":";
        PrintArr_V(arr[i], length);
    }
    cout <<"\n";
}


//	A. Action: Reads from a textfile, updates given variables, and *RETURNS* a 2D array
//	B. Arguement/s: text file to read, and variables to update


char** Create2DArray_P(string myFile, int &h, int &w)
{
	string content;
	ifstream inFileStream; //ifstream object

	inFileStream.open(myFile);

	getline(inFileStream, content); //reads content until a break
	h = stoi(content); //turns string into an int
	getline(inFileStream, content);
	w = stoi(content);

	char** Another2D_Array = 0; //create a char pointer 
	Another2D_Array = new char*[h];

	for (int i = 0; i < h; i++)
	{
		Another2D_Array[i] = new char[w];
		getline(inFileStream, content);

		for (int j = 0; j < w; j++)
		{
			Another2D_Array[i][j] = content[j];
			// if(content[j] == 'X')
			// else if(content[j] == '-')
		}
	}

	inFileStream.close();
    
	//cout << "\nArrays Read From Text File. - 2DArray Returned (From Create2DArray Method)\n";
	return Another2D_Array;
}

//	A. Action: Reads from a textfile, updates given variables, and *RETURNS* a 2D array
//	B. Arguement/s: height 2D array, width of each array within 2D array, population density

char** Create2DRandArray(int h, int w, double pop)
{
	srand(time(0));
	int tracker = pop*h*w;
	string content;

	char** Another2D_Array = 0; //create a char pointer 
	Another2D_Array = new char*[h];

	for (int i = 0; i < h; i++)
	{
		Another2D_Array[i] = new char[w];

		for (int j = 0; j < w; j++)
		{
			int randomGen = rand() % 2;
			if(tracker>=0)
			{
				switch (randomGen)
				{
					case 1:
					{
						Another2D_Array[i][j] = 'X';
						tracker--;
						break;
					}
					case 0:
					{
						Another2D_Array[i][j] = '-';
						break;
					}
					default:
					{
						Another2D_Array[i][j] = '-';
						break;
					}
				}
			}
			else
			{
				Another2D_Array[i][j] = '-';
			}
		}
	}

	return Another2D_Array;
}


//	A. Action: Reads how many neighbors a cells index has and *RETURNS* how many are alive
//	B. Arguement/s: A reference to a donut to access and its index [col][row]


int ReadNeighborsClassic(Donut &donut, int col, int row) //algorithm
{
	int alive = 0;

	// cout << "\nReading Neighbors\n";
	// cout << "\nCols: " << col;
 //    cout << "\nRows: " <<  row << "\n";

	/*Top Left Corner*/
	if(col == 0 && row == 0)
	{
		// cout << "\n--------------------------\n";
		// cout << "\nEvaluating Top Left Corner: "; 
		// cout << donut.array[col][row] << "\n";

		if(donut.array[col+1][row]=='X')

		 {

		   alive++;

		 }

		 if(donut.array[col+1][row+1]=='X')

		 {

		   alive++;

		 }

		 if(donut.array[col][row+1]=='X')

		 {

		   alive++;

		 }

		 return alive;
	}

	/*Top Right Corner*/
	
	else if(col == 0 && row == 19)
	{
		// cout << "\n--------------------------\n";
		// cout << "\nEvaluating Top Right Corner: "; 
		// cout << donut.array[col][row] << "\n";

		if(donut.array[col][row-1]=='X')

		 {

		   alive++;

		 }

		 if(donut.array[col+1][row-1]=='X')

		 {

		   alive++;

		 }

		 if(donut.array[col+1][row]=='X')

		 {

		   alive++;

		 }
		 return alive;
	}

	/*Bottom Left Corner*/
	
	else if(col == 9 && row == 0)
	{
		// cout << "\n--------------------------\n";
		// cout << "\nEvaluating Bottom Left Corner: "; 
		// cout << donut.array[col][row] << "\n";

		if(donut.array[col-1][row]=='X')

		 {

		   alive++;

		 }

		 if(donut.array[col-1][row+1]=='X')

		 {

		   alive++;

		 }

		 if(donut.array[col][row+1]=='X')

		 {

		   alive++;

		 }
		 return alive;
	}

	/*Bottom Right Corner*/
	
	else if(col == 9 && row == 19)
	{
		// cout << "\n--------------------------\n";
		// cout << "\nEvaluating Bottom Right Corner: "; 
		// cout << donut.array[col][row] << "\n";

		if(donut.array[col-1][row]=='X')
		 {

		   alive++;

		 }

		 if(donut.array[col-1][row-1]=='X')

		 {

		   alive++;

		 }

		 if(donut.array[col][row-1]=='X')

		 {

		   alive++;

		 }

		 return alive;
	}


	/*Top Side*/
	
	else if(col == 0)
	{
		// cout << "\nEvaluating Top Sides: "; 
		// cout << donut.array[col][row] << "\n";

	if(donut.array[col][row-1]=='X')

	 {

	   alive++;

	 }

	 if(donut.array[col][row+1]=='X')

	 {

	   alive++;

	 }

	 if(donut.array[col+1][row-1]=='X')

	 {

	   alive++;

	 }

	 if(donut.array[col+1][row]=='X')

	 {

	   alive++;

	 }

	 if(donut.array[col+1][row+1]=='X')

	 {

	   alive++;

	 }

	 return alive;
	}

	/*Right Side*/
	
	else if(row == 19)
	{	
		// cout << "\nEvaluating Right Sides: "; 
		// cout << donut.array[col][row] << "\n";

	if(donut.array[col-1][row]=='X')

	 {

	   alive++;

	 }

	 if(donut.array[col-1][row-1]=='X')

	 {

	   alive++;

	 }

	 if(donut.array[col][row-1]=='X')

	 {

	   alive++;

	 }

	 if(donut.array[col+1][row-1]=='X')

	 {

	   alive++;

	 }

	 if(donut.array[col+1][row]=='X')

	 {

	   alive++;

	 }

	 return alive;
	}


	/*Bottom Side*/
	
	else if(col == 9)
	{
		// cout << "\nEvaluating Bottom Sides: "; 
		// cout << donut.array[col][row] << "\n";

	if(donut.array[col][row-1]=='X')

	 {

	   alive++;

	 }

	 if(donut.array[col][row+1]=='X')

	 {

	   alive++;

	 }

	 if(donut.array[col-1][row-1]=='X')

	 {

	   alive++;

	 }

	 if(donut.array[col-1][row]=='X')

	 {

	   alive++;

	 }

	 if(donut.array[col-1][row+1]=='X')

	 {

	   alive++;

	 }

	 return alive;
	}

	/*Left Side*/
	
	else if(row == 0)
	{	
		// cout << "\nEvaluating Left Sides: "; 
		// cout << donut.array[col][row] << "\n";


	if(donut.array[col-1][row]=='X')

	 {

	   alive++;

	 }

	 if(donut.array[col-1][row+1]=='X')

	 {

	   alive++;

	 }

	 if(donut.array[col][row+1]=='X')

	 {

	   alive++;

	 }

	 if(donut.array[col+1][row+1]=='X')

	 {

	   alive++;

	 }

	 if(donut.array[col+1][row]=='X')

	 {

	   alive++;

	 }

	 return alive;
	}


	else if (col != 0  &&  col!= 9 && row != 0 && row != 19)
	{

		// cout << "\nCentral Chars: "; 
		// cout << donut.array[col][row] << "\n";

	if(donut.array[col-1][row-1] == 'X') {alive++;} 	if(donut.array[col-1][row] == 'X') {alive++;} 	if(donut.array[col-1][row+1] == 'X') {alive++;}
	
	if(donut.array[col][row-1] == 'X') {alive++;} 		/*CELL BEING EVALUATED: donut.array[COL][ROW]*/	if(donut.array[col][row+1] == 'X') {alive++;}
	
	if(donut.array[col+1][row-1] == 'X') {alive++;} 	if(donut.array[col+1][row] == 'X') {alive++;} 	if(donut.array[col+1][row+1] == 'X') {alive++;}
	
	return alive;
	}

	//return alive;
}

int ReadNeighborsDonut(Donut &donut, int row, int col) //algorithm
{
	int alive = 0;
	
	// cout << "\nReading Donut Neighbors\n";

	// cout << "\nRows: " << row;
 // 	cout << "\nCols: " <<  col << "\n";

 	if(row == 0 && col == 0)
 	{
 		// cout << "\nReading Left Corner\n";
 		alive = DonutTopLeftCorner(donut, row, col);
 		// cout << alive;
 		// cin.get();
 		return alive;
 	}

 	if(row == 0 && col != donut.rowSize-1)
 	{
 		// cout << "\nReading Top Side\n";
 		alive = DonutTopSide(donut, row, col);
 		//cout << "Top Side Alive: " << alive;
 		// cin.get();
 		return alive;
 	}

 	if(row == 0 && col == donut.rowSize-1)
 	{
 		// cout << "\nReading Right Corner\n";
 		alive = DonutTopRightCorner(donut, row, col);
 		//cout << "Right Corner Alive: " << alive;
 		// cin.get();
 		return alive;
 	}

 	if(row > 0 && row < donut.colSize-1 && col == 0)
 	{
 		// cout << "\nReading Left Side\n";
 		alive = DonutLeftSide(donut, row, col);
 		//cout << "Left Side Alive: " << alive;
 		// cin.get();
 		return alive;
 	}

 	if(row > 0 && row < donut.colSize-1 && col == donut.rowSize-1)
 	{
 		// cout << "\nReading Right Side\n";
 		alive = DonutRightSide(donut, row, col);
 		//cout << "Right Side Cells Alive: " << alive;
 		// cin.get();
 		return alive;
 	}

 	if(row == donut.colSize-1 && col == 0)
 	{
 		// cout << "\nReading Bottom Left Corner\n";
 		alive = DonutBottomLeftCorner(donut, row, col);
 		//cout << "Bottom Left Corner Cells Alive: " << alive;
 		// cin.get();
 		return alive;
 	}

 	if(row == donut.colSize-1 && col != donut.rowSize-1)
 	{
 		// cout << "\nReading Bottom Side\n";
 		alive = DonutBottomSide(donut, row, col);
 		//cout << "Bottom Bottom Side Cells Alive: " << alive;
 		// cin.get();
 		return alive;
 	}

 	if(row == donut.colSize-1 && col == donut.rowSize-1)
 	{
 		// cout << "\nReading Bottom Right Corner\n";
 		alive = DonutBottomRightCorner(donut, row, col);
 		//cout << "Bottom Right Corner Cells Alive: " << alive;
 		// cin.get();
 		return alive;
 	}

 	else if(row != 0 && row != donut.colSize-1 && col != 0 && col != donut.rowSize-1)
 	{
 		// cout << "\nReading Cental Cells\n";
 		alive = DonutCentral(donut, row, col);
 		//cout << "Central Cells Alive: " << alive;
 		// cin.get();
 		return alive;
 	}
}

int ReadNeighborsMirror(Donut &donut, int row, int col) //algorithm
{
                int alive = 0;

               if(row == 0 && col == 0)
               {
                               // cout << "\nReading Left Corner\n";
                               alive = MirrorTopLeftCorner(donut, row, col);
                               // cout << alive;
                               // cin.get();
                               return alive;
               }

               if(row == 0 && col != donut.rowSize-1)
               {
                               // cout << "\nReading Top Side\n";
                               alive = MirrorTopSide(donut, row, col);
                               //cout << "Top Side Alive: " << alive;
                               // cin.get();
                               return alive;
               }

               if(row == 0 && col == donut.rowSize-1)
               {
                               // cout << "\nReading Right Corner\n";
                               alive = MirrorTopRightCorner(donut, row, col);
                               //cout << "Right Corner Alive: " << alive;
                               // cin.get();
                               return alive;
               }

               if(row > 0 && row < donut.colSize-1 && col == 0)
               {
                               // cout << "\nReading Left Side\n";
                               alive = MirrorLeftSide(donut, row, col);
                               //cout << "Left Side Alive: " << alive;
                               // cin.get();
                               return alive;
               }

               if(row > 0 && row < donut.colSize-1 && col == donut.rowSize-1)
               {
                               // cout << "\nReading Right Side\n";
                               alive = MirrorRightSide(donut, row, col);
                               //cout << "Right Side Cells Alive: " << alive;
                               // cin.get();
                               return alive;
               }

               if(row == donut.colSize-1 && col == 0)
               {
                               // cout << "\nReading Bottom Left Corner\n";
                               alive = MirrorBottomLeftCorner(donut, row, col);
                               //cout << "Bottom Left Corner Cells Alive: " << alive;
                               // cin.get();
                               return alive;
               }

               if(row == donut.colSize-1 && col != donut.rowSize-1)
               {
                               // cout << "\nReading Bottom Side\n";
                               alive = MirrorBottomSide(donut, row, col);
                               //cout << "Bottom Bottom Side Cells Alive: " << alive;
                               // cin.get();
                               return alive;
               }

               if(row == donut.colSize-1 && col == donut.rowSize-1)
               {
                               // cout << "\nReading Bottom Right Corner\n";
                               alive = MirrorBottomRightCorner(donut, row, col);
                               //cout << "Bottom Right Corner Cells Alive: " << alive;
                               // cin.get();
                               return alive;
               }

               else if(row != 0 && row != donut.colSize-1 && col != 0 && col != donut.rowSize-1)
               {
                               // cout << "\nReading Cental Cells\n";
                               alive = MirrorCentral(donut, row, col);
                               //cout << "Central Cells Alive: " << alive;
                               // cin.get();
                               return alive;
               }
}


//	A. Action: Reads how many neighbors are alive and *RETURNS* an 'X' or '-'' depending on set rules
//	B. Arguement/s: number of neighbors alive


char DeadOrAliveClassic(Donut &donut, int col, int row) //rules
{
	//cout << "\nDetermining Whether Dead or Alive\n";
	int alive = 0;
	alive = ReadNeighborsClassic(donut, col, row);

	if (alive <= 1)
	{
		return '-';
	}

	else if (alive == 2)
	{
		return donut.array[col][row];
	}

	else if (alive == 3)
	{
		return 'X';
	}

	else if (alive >= 4)
	{
		return '-';
	}
}

char DeadOrAliveDonut(Donut &donut, int col, int row) //rules
{
	//cout << "\nDetermining Whether Dead or Alive\n";
	int alive = 0;
	alive = ReadNeighborsDonut(donut, col, row);

	if (alive <= 1)
	{
		return '-';
	}

	else if (alive == 2)
	{
		return donut.array[col][row];
	}

	else if (alive == 3)
	{
		return 'X';
	}

	else if (alive >= 4)
	{
		return '-';
	}
}

char DeadOrAliveMirror(Donut &donut, int col, int row)
{
	//cout << "\nDetermining Whether Dead or Alive\n";
	int alive = 0;
	alive = ReadNeighborsMirror(donut, col, row);

	if (alive <= 1)
	{
		return '-';
	}

	else if (alive == 2)
	{
		return donut.array[col][row];
	}

	else if (alive == 3)
	{
		return 'X';
	}

	else if (alive >= 4)
	{
		return '-';
	}
}


//	A. Action: Reads 2 Donuts and accesses the specific index and modifies it according to appropriate rules
//	B. Arguement/s: 2 Donuts, the index being modified


void TransformClassic(Donut &current, Donut &next, int col, int row)
{
	//cout << "\nTransforming\n";
	next.array[col][row] = DeadOrAliveClassic(current, col, row);
}

void TransformDonut(Donut &current, Donut &next, int col, int row)
{
	//cout << "\nTransforming\n";
	next.array[col][row] = DeadOrAliveDonut(current, col, row);
}

void TransformMirror(Donut &current, Donut &next, int col, int row)
{
	next.array[col][row] = DeadOrAliveMirror(current, col, row);
}




//	Below are helper functions used to read specific neighbors accoding to different game modes




int DonutTopLeftCorner(Donut &donut, int row, int col)
{
	int alive = 0;
	
	/*Top Left Corner*/
	
		if(donut.array[row][col+1]=='X') //R
		{
			alive++;			
		}

		if(donut.array[row+1][col+1]=='X') //DR
		{
			alive++;
		}

		if(donut.array[row+1][col]=='X') // D
		{
			alive++;
		}

		if(donut.array[row+1][donut.rowSize-1]=='X') // DL
		{
			alive++;
		}

		if(donut.array[row][donut.rowSize-1]=='X') // L
		{
			alive++;
		}

		if(donut.array[donut.colSize-1][donut.rowSize-1]=='X') // UL
		{
			alive++;
		}

		if(donut.array[donut.colSize-1][col]=='X') // U
		{
			alive++;
		}

		if(donut.array[donut.colSize-1][col+1]=='X') // UR
		{
			alive++;
		}
		return alive;
}

int DonutTopSide(Donut &donut, int row, int col)
{
	int alive = 0;
	
	/*Top Side*/
	
		if(donut.array[row][col+1]=='X') //R
		{
			// cout <<"A";
			alive++;
			// cout << alive; 
			// cin.get();
		
		}

		if(donut.array[row+1][col+1]=='X') //DR
		{
			// cout <<"B";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[row+1][col]=='X') // D
		{
			// cout <<"C";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[row+1][col-1]=='X') // DL
		{
			// cout <<"D";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[row][col-1]=='X') // L
		{
			// cout <<"E";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[donut.colSize-1][col-1]=='X') // UL
		{
			// cout <<"F";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[donut.colSize-1][col]=='X') // U
		{
			// cout <<"G";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[donut.colSize-1][col+1]=='X') // UR
		{
			// cout <<"H";
			alive++;
			// cout << alive; 
			// cin.get();

		}
		return alive;	
}

int DonutTopRightCorner(Donut &donut, int row, int col)
{
	int alive = 0;
	
	/*Top Right Corner*/
	
		if(donut.array[row][0]=='X') //R
		{
			// cout <<"A";
			alive++;
			// cout << alive; 
			// cin.get();
		
		}

		if(donut.array[row+1][0]=='X') //DR
		{
			// cout <<"B";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[row+1][col]=='X') // D
		{
			// cout <<"C";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[row+1][col-1]=='X') // DL
		{
			// cout <<"D";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[row][col-1]=='X') // L
		{
			// cout <<"E";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[donut.colSize-1][col-1]=='X') // UL
		{
			// cout <<"F";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[donut.colSize-1][col]=='X') // U
		{
			// cout <<"G";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[donut.colSize-1][0]=='X') // UR
		{
			// cout <<"H";
			alive++;
			// cout << alive; 
			// cin.get();

		}
		return alive;	
}

int DonutLeftSide(Donut &donut, int row, int col)
{
	int alive = 0;
	
	/*Left Side*/
	
		if(donut.array[row][col+1]=='X') //R
		{
			// cout <<"A";
			alive++;
			// cout << alive; 
			// cin.get();
		
		}

		if(donut.array[row+1][col+1]=='X') //DR
		{
			// cout <<"B";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[row+1][col]=='X') // D
		{
			// cout <<"C";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[row+1][donut.rowSize-1]=='X') // DL
		{
			// cout <<"D";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[row][donut.rowSize-1]=='X') // L
		{
			// cout <<"E";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[row-1][donut.rowSize-1]=='X') // UL
		{
			// cout <<"F";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[row-1][col]=='X') // U
		{
			// cout <<"G";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[row-1][col+1]=='X') // UR
		{
			// cout <<"H";
			alive++;
			// cout << alive; 
			// cin.get();

		}
		return alive;	
}

int DonutCentral(Donut &donut, int row, int col)
{
	int alive = 0;
	
	/*Central*/
	
		if(donut.array[row][col+1]=='X') //R
		{
			// cout <<"A";
			alive++;
			// cout << alive; 
			// cin.get();
		
		}

		if(donut.array[row+1][col+1]=='X') //DR
		{
			// cout <<"B";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[row+1][col]=='X') // D
		{
			// cout <<"C";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[row+1][col-1]=='X') // DL
		{
			// cout <<"D";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[row][col-1]=='X') // L
		{
			// cout <<"E";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[row-1][col-1]=='X') // UL
		{
			// cout <<"F";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[row-1][col]=='X') // U
		{
			// cout <<"G";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[row-1][col+1]=='X') // UR
		{
			// cout <<"H";
			alive++;
			// cout << alive; 
			// cin.get();

		}
		return alive;	
}

int DonutRightSide(Donut &donut, int row, int col)
{
	int alive = 0;
	
	/*Right Side*/
	
		if(donut.array[row][0]=='X') //R
		{
			// cout <<"A";
			alive++;
			// cout << alive; 
			// cin.get();
		
		}

		if(donut.array[row+1][0]=='X') //DR
		{
			// cout <<"B";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[row+1][col]=='X') // D
		{
			// cout <<"C";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[row+1][col-1]=='X') // DL
		{
			// cout <<"D";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[row][col-1]=='X') // L
		{
			// cout <<"E";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[row-1][col-1]=='X') // UL
		{
			// cout <<"F";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[row-1][col]=='X') // U
		{
			// cout <<"G";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[row-1][0]=='X') // UR
		{
			// cout <<"H";
			alive++;
			// cout << alive; 
			// cin.get();

		}
		return alive;	
}

int DonutBottomLeftCorner(Donut &donut, int row, int col)
{
	int alive = 0;
	
	/*Bottom Left Corner*/
	
		if(donut.array[row][col+1]=='X') //R
		{
			// cout <<"A";
			alive++;
			// cout << alive; 
			// cin.get();
		
		}

		if(donut.array[0][col+1]=='X') //DR
		{
			// cout <<"B";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[0][col]=='X') // D
		{
			// cout <<"C";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[0][donut.rowSize-1]=='X') // DL
		{
			// cout <<"D";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[row][donut.rowSize-1]=='X') // L
		{
			// cout <<"E";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[0][donut.rowSize-1]=='X') // UL
		{
			// cout <<"F";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[row-1][col]=='X') // U
		{
			// cout <<"G";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[row-1][col+1]=='X') // UR
		{
			// cout <<"H";
			alive++;
			// cout << alive; 
			// cin.get();

		}
		return alive;	
}

int DonutBottomSide(Donut &donut, int row, int col)
{
	int alive = 0;
	
	/*Bottom Side*/
	
		if(donut.array[row][col+1]=='X') //R
		{
			// cout <<"A";
			alive++;
			// cout << alive; 
			// cin.get();
		
		}

		if(donut.array[0][col+1]=='X') //DR
		{
			// cout <<"B";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[0][col]=='X') // D
		{
			// cout <<"C";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[0][col-1]=='X') // DL
		{
			// cout <<"D";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[row][col-1]=='X') // L
		{
			// cout <<"E";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[row-1][col-1]=='X') // UL
		{
			// cout <<"F";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[row-1][col]=='X') // U
		{
			// cout <<"G";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[row-1][col+1]=='X') // UR
		{
			// cout <<"H";
			alive++;
			// cout << alive; 
			// cin.get();

		}
		return alive;	
}

int DonutBottomRightCorner(Donut &donut, int row, int col)
{
	int alive = 0;
	
	/*Bottom Right Corner*/
	
		if(donut.array[row][0]=='X') //R
		{
			// cout <<"A";
			alive++;
			// cout << alive; 
			// cin.get();
		
		}

		if(donut.array[0][0]=='X') //DR
		{
			// cout <<"B";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[0][col]=='X') // D
		{
			// cout <<"C";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[0][col-1]=='X') // DL
		{
			// cout <<"D";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[row][col-1]=='X') // L
		{
			// cout <<"E";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[row-1][col-1]=='X') // UL
		{
			// cout <<"F";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[row-1][col]=='X') // U
		{
			// cout <<"G";
			alive++;
			// cout << alive; 
			// cin.get();

		}

		if(donut.array[row-1][0]=='X') // UR
		{
			// cout <<"H";
			alive++;
			// cout << alive; 
			// cin.get();

		}
		return alive;	
}



int MirrorTopLeftCorner(Donut &donut, int row, int col)
{
                int alive = 0;

                /*Top Left Corner*/

                                if(donut.array[row][col+1]=='X') //R
                                {
                                                alive++;
                                }

                                if(donut.array[row+1][col+1]=='X') //DR
                                {
                                                alive++;
                                }

                                if(donut.array[row+1][col]=='X') // D
                                {
                                                alive++;
                                }

                                if(donut.array[row+1][donut.rowSize-1]=='X') // DL
                                {
                                                alive++;
                                }

                                if(donut.array[row][donut.rowSize-1]=='X') // L
                                {
                                                alive++;
                                }

                                if(donut.array[donut.colSize-1][donut.rowSize-1]=='X') // UL
                                {
                                                alive++;
                                }

                                if(donut.array[donut.colSize-1][col]=='X') // U
                                {
                                                alive++;
                                }

                                if(donut.array[donut.colSize-1][col+1]=='X') // UR
                                {
                                                alive++;
                                }
                                return alive;
}

int MirrorTopSide(Donut &donut, int row, int col)
{
                int alive = 0;

                /*Top Side*/

                                if(donut.array[row][col+1]=='X') //R
                                {
                                                // cout <<"A";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[row+1][col+1]=='X') //DR
                                {
                                                // cout <<"B";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[row+1][col]=='X') // D
                                {
                                                // cout <<"C";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[row+1][col-1]=='X') // DL
                                {
                                                // cout <<"D";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[row][col-1]=='X') // L
                                {
                                                // cout <<"E";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[donut.colSize-1][col-1]=='X') // UL
                                {
                                                // cout <<"F";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[donut.colSize-1][col]=='X') // U
                                {
                                                // cout <<"G";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[donut.colSize-1][col+1]=='X') // UR
                                {
                                                // cout <<"H";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }
                                return alive;
}

int MirrorTopRightCorner(Donut &donut, int row, int col)
{
                int alive = 0;

                /*Top Right Corner*/

                                if(donut.array[row][0]=='X') //R
                                {
                                                // cout <<"A";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[row+1][0]=='X') //DR
                                {
                                                // cout <<"B";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[row+1][col]=='X') // D
                                {
                                                // cout <<"C";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[row+1][col-1]=='X') // DL
                                {
                                                // cout <<"D";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[row][col-1]=='X') // L
                                {
                                                // cout <<"E";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[donut.colSize-1][col-1]=='X') // UL
                                {
                                                // cout <<"F";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[donut.colSize-1][col]=='X') // U
                                {
                                                // cout <<"G";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[donut.colSize-1][0]=='X') // UR
                                {
                                                // cout <<"H";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }
                                return alive;
}

int MirrorLeftSide(Donut &donut, int row, int col)
{
                int alive = 0;

                /*Left Side*/

                                if(donut.array[row][col+1]=='X') //R
                                {
                                                // cout <<"A";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[row+1][col+1]=='X') //DR
                                {
                                                // cout <<"B";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[row+1][col]=='X') // D
                                {
                                                // cout <<"C";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[row+1][donut.rowSize-1]=='X') // DL
                                {
                                                // cout <<"D";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[row][donut.rowSize-1]=='X') // L
                                {
                                                // cout <<"E";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[row-1][donut.rowSize-1]=='X') // UL
                                {
                                                // cout <<"F";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[row-1][col]=='X') // U
                                {
                                                // cout <<"G";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[row-1][col+1]=='X') // UR
                                {
                                                // cout <<"H";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }
                                return alive;
}

int MirrorCentral(Donut &donut, int row, int col)
{
                int alive = 0;

                /*Central*/

                                if(donut.array[row][col+1]=='X') //R
                                {
                                                // cout <<"A";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[row+1][col+1]=='X') //DR
                                {
                                                // cout <<"B";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[row+1][col]=='X') // D
                                {
                                                // cout <<"C";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[row+1][col-1]=='X') // DL
                                {
                                                // cout <<"D";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[row][col-1]=='X') // L
                                {
                                                // cout <<"E";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[row-1][col-1]=='X') // UL
                                {
                                                // cout <<"F";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[row-1][col]=='X') // U
                                {
                                                // cout <<"G";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[row-1][col+1]=='X') // UR
                                {
                                                // cout <<"H";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }
                                return alive;
}

int MirrorRightSide(Donut &donut, int row, int col)
{
                int alive = 0;

                /*Right Side*/

                                if(donut.array[row][0]=='X') //R
                                {
                                                // cout <<"A";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[row+1][0]=='X') //DR
                                {
                                                // cout <<"B";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[row+1][col]=='X') // D
                                {
                                                // cout <<"C";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[row+1][col-1]=='X') // DL
                                {
                                                // cout <<"D";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[row][col-1]=='X') // L
                                {
                                                // cout <<"E";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[row-1][col-1]=='X') // UL
                                {
                                                // cout <<"F";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[row-1][col]=='X') // U
                                {
                                                // cout <<"G";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[row-1][0]=='X') // UR
                                {
                                                // cout <<"H";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }
                                return alive;
}

int MirrorBottomLeftCorner(Donut &donut, int row, int col)
{
                int alive = 0;

                /*Bottom Left Corner*/

                                if(donut.array[row][col+1]=='X') //R
                                {
                                                // cout <<"A";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[0][col+1]=='X') //DR
                                {
                                                // cout <<"B";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[0][col]=='X') // D
                                {
                                                // cout <<"C";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[0][donut.rowSize-1]=='X') // DL
                                {
                                                // cout <<"D";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[row][donut.rowSize-1]=='X') // L
                                {
                                                // cout <<"E";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[0][donut.rowSize-1]=='X') // UL
                                {
                                                // cout <<"F";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[row-1][col]=='X') // U
                                {
                                                // cout <<"G";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[row-1][col+1]=='X') // UR
                                {
                                                // cout <<"H";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }
                                return alive;
}

int MirrorBottomSide(Donut &donut, int row, int col)
{
                int alive = 0;

                /*Bottom Side*/

                                if(donut.array[row][col+1]=='X') //R
                                {
                                                // cout <<"A";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[0][col+1]=='X') //DR
                                {
                                                // cout <<"B";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[0][col]=='X') // D
                                {
                                                // cout <<"C";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[0][col-1]=='X') // DL
                                {
                                                // cout <<"D";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[row][col-1]=='X') // L
                                {
                                                // cout <<"E";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[row-1][col-1]=='X') // UL
                                {
                                                // cout <<"F";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[row-1][col]=='X') // U
                                {
                                                // cout <<"G";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[row-1][col+1]=='X') // UR
                                {
                                                // cout <<"H";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }
                                return alive;
}

int MirrorBottomRightCorner(Donut &donut, int row, int col)
{
                int alive = 0;

                /*Bottom Right Corner*/

                                if(donut.array[row][0]=='X') //R
                                {
                                                // cout <<"A";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[0][0]=='X') //DR
                                {
                                                // cout <<"B";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[0][col]=='X') // D
                                {
                                                // cout <<"C";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[0][col-1]=='X') // DL
                                {
                                                // cout <<"D";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[row][col-1]=='X') // L
                                {
                                                // cout <<"E";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[row-1][col-1]=='X') // UL
                                {
                                                // cout <<"F";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[row-1][col]=='X') // U
                                {
                                                // cout <<"G";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }

                                if(donut.array[row-1][0]=='X') // UR
                                {
                                                // cout <<"H";
                                                alive++;
                                                // cout << alive;
                                                // cin.get();

                                }
                                return alive;
}
