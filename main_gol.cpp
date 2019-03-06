/*
  a. Name: Elmer Camargo
  b. Student ID: 2291367
  c. Chapman email: camargop@chapman.edu
  d. Course number and section: 350-02
  e. Assignment Number: 2 - Game of Life

  a. Name: Mark Hyun
  b. Student ID: 2277731
  c. Chapman email: hyun107@mail.chapman.edu
  d. Course number and section: 350-02
  e. Assignment Number: 2 - Game of Life
*/



#include <string>
#include <iostream>
#include <fstream>
#include "ReadWrite.h"
#include "Donut.h"
#include <unistd.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int decision = 0;
  	int userMode = 0;
  	int outputChoice = 0;
  	int genCount = 0;
  	int genEnd = 21; 

  	int userRows = 0;
  	int userCols = 0;
  	double userPopDensity = 0.0;
  	string userMapFile = "";
  	string userTextFile = "";
  
  	cout<<"\nWelcome to the Game of Life !"<<endl;
  	cout<<"\nWould you like to map a file or create a simulation with random assignment?"<<endl;
  	cout<<"\nType 1 for Mapping File || Type 0 for Random Assignment"<< endl;

  	cin >> decision;

  	if(decision == 1)
  	{
    	cout << "\nPlease type the name of the file."<<endl;
    	cout << "*end file name with .txt"<<endl;
    	cin >> userMapFile;
	
	    cout<<"\n\nWhat mode would you like to see?"<<endl;
	    cout<< "\nType 1 - Classic Mode | Type 2 - Donut Mode | Type 3 - Mirror Mode| "<<endl;
	    cin>>userMode;

	    cout<<"\n\nPress 1 if you would like a brief pause between each generation\n";
	    cout<<"Press 2 if you would like to press enter between each generation\n";
	    cout<<"Press 3 if you would like all output to be written to a .txt file\n\n";

	    cin >> outputChoice;


	    switch (userMode)
	    {
	      	case 1: //Classic Mode
	      	{

	      		cout << "\nUser Selected Classic Mode\n";

	      		char** CurrentArray = Create2DArray_P(userMapFile, userCols, userRows);
	    		Donut CurrentDonut = Donut(CurrentArray, userRows, userCols);

	    		char** NextArray = CurrentDonut.CreateNextGen_P();
	    		Donut NextDonut = Donut(NextArray, userRows, userCols);

	    		if(outputChoice == 1)
	    		{
	    			cout << "\nOriginal Classic Array\n";
	    			CurrentDonut.printDonut();
	    			sleep(1);
	    		}

	    		else if(outputChoice == 2)
	    		{
	    			cout << "\nOriginal Classic Array\n";
	    			CurrentDonut.printDonut();
	    			cin.get();
	    		}

	    		else if (outputChoice ==3)
	    		{
	    			cout << "What would you like to name the new file?: ";
	    			cin >> userTextFile;
	    			userTextFile = userTextFile+".txt";
	    			CurrentDonut.WriteToFile(userTextFile);
	    			cout << "Writing to file. Please Wait.";
	    		}

	    		for(genCount = 1; genCount != genEnd; genCount++)
	    		{
	    			int currentAliveCount = 0;
	    			int nextAliveCount = 0;
	    			int killCount = 0;


	    			//TRANSFORM!
	    			for(int i = 0; i < userCols; i++)
	     			{
	       				for(int j = 0; j < userRows; j++)
	       				{
	         				TransformClassic(CurrentDonut, NextDonut, i, j);
	       				}
	     			}

	     			if(outputChoice == 1)
	       			{	
	       				cout << "\nClassic Generation Number: " << genCount<<"\n";
	       				NextDonut.printDonut();
		    			CurrentDonut.array = NextDonut.array;
		    			sleep(1);
		    			
		    		}

		    		else if(outputChoice == 2)
	       			{	
	       				cout << "\nClassic Generation Number: " << genCount<<"\n";
	       				NextDonut.printDonut();
		    			CurrentDonut.array = NextDonut.array;
		    			cin.get();    			
		    		}

		    		else if(outputChoice == 3)
		    		{
		    			
		    			NextDonut.WriteToFile(userTextFile);
		    			CurrentDonut.array = NextDonut.array;
		    		}
	    			
				}


	      		break;
	      	}
	      	case 2: //Donut Mode
	      	{
	      		cout << "\nUser Selected Doughnut Mode\n";
	      		char** CurrentArray = Create2DArray_P(userMapFile, userCols, userRows);
	    		Donut CurrentDonut = Donut(CurrentArray, userRows, userCols);

	    		char** NextArray = CurrentDonut.CreateNextGen_P();
	    		Donut NextDonut = Donut(NextArray, userRows, userCols);

	    		if(outputChoice == 1)
	    		{
	    			cout << "\nOriginal Donut\n";
	    			CurrentDonut.printDonut();
	    			sleep(1);
	    		}

	    		else if(outputChoice == 2)
	    		{
	    			cout << "\nOriginal Donut\n";
	    			CurrentDonut.printDonut();
	    			cin.get();
	    		}

	    		else if (outputChoice ==3)
	    		{
	    			cout << "What would you like to name the new file?: ";
	    			cin >> userTextFile;
	    			userTextFile = userTextFile+".txt";
	    			cout << "Writing to file. Please wait, this may take a moment";
	    			CurrentDonut.WriteToFile(userTextFile);
	    		}

	    		for(genCount = 1; genCount != genEnd; genCount++)
	    		{
	    			//TRANSFORM!
	    			for(int i = 0; i < userCols; i++)
	     			{
	       				for(int j = 0; j < userRows; j++)
	       				{
	         				TransformDonut(CurrentDonut, NextDonut, i, j);
	       				}
	     			}

	     			if(outputChoice == 1)
	       			{	
	       				cout << "\nDonut Generation Number: " << genCount<<"\n";
	       				NextDonut.printDonut();
		    			CurrentDonut.array = NextDonut.array;
		    			sleep(1);
		    			//CurrentDonut.printDonut();
		    		}

		    		else if(outputChoice == 2)
	       			{	
	       				cout << "\nDonut Generation Number: " << genCount<<"\n";
	       				NextDonut.printDonut();
		    			CurrentDonut.array = NextDonut.array;
		    			cin.get();
		    			//CurrentDonut.printDonut();
		    		}

		    		else if(outputChoice == 3)
		    		{
		    			//cout << userTextFile;
		    			NextDonut.WriteToFile(userTextFile);
		    			CurrentDonut.array = NextDonut.array;
		    		}
	    			
				}

	      		break;
	  		}

	      	case 3: //Mirror Mode
	      	{
	      		cout << "\nUser Selected Mirror Mode\n";
	      		char** CurrentArray = Create2DArray_P(userMapFile, userCols, userRows);
	    		Donut CurrentDonut = Donut(CurrentArray, userRows, userCols);

	    		char** NextArray = CurrentDonut.CreateNextGen_P();
	    		Donut NextDonut = Donut(NextArray, userRows, userCols);

	    		if(outputChoice == 1)
	    		{
	    			cout << "\nOriginal Mirror Array\n";
	    			CurrentDonut.printDonut();
	    			sleep(1);
	    		}

	    		else if(outputChoice == 2)
	    		{
	    			cout << "\nOriginal Mirror Array\n";
	    			CurrentDonut.printDonut();
	    			cin.get();
	    		}

	    		else if (outputChoice ==3)
	    		{
	    			cout << "What would you like to name the new file?: ";
	    			cin >> userTextFile;
	    			userTextFile = userTextFile+".txt";
	    			cout << "Writing to file. Please wait, this may take a moment";
	    			CurrentDonut.WriteToFile(userTextFile);
	    		}

	    		for(genCount = 1; genCount != genEnd; genCount++)
	    		{
	    			//TRANSFORM!
	    			for(int i = 0; i < userCols; i++)
	     			{
	       				for(int j = 0; j < userRows; j++)
	       				{
	         				TransformMirror(CurrentDonut, NextDonut, i, j);
	       				}
	     			}

	     			if(outputChoice == 1)
	       			{	
	       				cout << "\nMirror Generation Number: " << genCount<<"\n";
	       				NextDonut.printDonut();
		    			CurrentDonut.array = NextDonut.array;
		    			sleep(1);
		    		}

		    		else if(outputChoice == 2)
	       			{	
	       				cout << "\nMirror Generation Number: " << genCount<<"\n";
	       				NextDonut.printDonut();
		    			CurrentDonut.array = NextDonut.array;
		    			cin.get();
		    		}

		    		else if(outputChoice == 3)
		    		{
		    			NextDonut.WriteToFile(userTextFile);
		    			CurrentDonut.array = NextDonut.array;
		    		}
	    			
				}

	      		break;
	  		}

	      	default: //Classic Mode
	      	{

	      		cout << "\nUser Selected Classic Mode\n";

	      		char** CurrentArray = Create2DArray_P(userMapFile, userCols, userRows);
	    		Donut CurrentDonut = Donut(CurrentArray, userRows, userCols);

	    		char** NextArray = CurrentDonut.CreateNextGen_P();
	    		Donut NextDonut = Donut(NextArray, userRows, userCols);

	    		if(outputChoice == 1)
	    		{
	    			cout << "\nOriginal Classic Array\n";
	    			CurrentDonut.printDonut();
	    			sleep(1);
	    		}

	    		else if(outputChoice == 2)
	    		{
	    			cout << "\nOriginal Classic Array\n";
	    			CurrentDonut.printDonut();
	    			cin.get();
	    		}

	    		else if (outputChoice ==3)
	    		{
	    			cout << "What would you like to name the new file?: ";
	    			cin >> userTextFile;
	    			userTextFile = userTextFile+".txt";
	    			CurrentDonut.WriteToFile(userTextFile);
	    			cout << "Writing to file. Please Wait.";
	    		}

	    		for(genCount = 1; genCount != genEnd; genCount++)
	    		{
	    			int currentAliveCount = 0;
	    			int nextAliveCount = 0;
	    			int killCount = 0;


	    			//TRANSFORM!
	    			for(int i = 0; i < userCols; i++)
	     			{
	       				for(int j = 0; j < userRows; j++)
	       				{
	         				TransformClassic(CurrentDonut, NextDonut, i, j);
	       				}
	     			}

	     			if(outputChoice == 1)
	       			{	
	       				cout << "\nClassic Generation Number: " << genCount<<"\n";
	       				NextDonut.printDonut();
		    			CurrentDonut.array = NextDonut.array;
		    			sleep(1);
		    			
		    		}

		    		else if(outputChoice == 2)
	       			{	
	       				cout << "\nClassic Generation Number: " << genCount<<"\n";
	       				NextDonut.printDonut();
		    			CurrentDonut.array = NextDonut.array;
		    			cin.get();		
		    		}

		    		else if(outputChoice == 3)
		    		{
		    			
		    			NextDonut.WriteToFile(userTextFile);
		    			CurrentDonut.array = NextDonut.array;
		    		}
	    			
				}


	      		break;
	      	}
	    }  
  	}
  
  	else
  	{
    cout<<"\nHow many rows do you want"<<endl;
    cin>>userRows;
    cout<<"\nHow many columns do you want?"<<endl;
    cin>>userCols;
    cout<<"\nWhat do you want to make the population density at?"<<endl;
    cout<<"*Please put in decimal format from 0.1- .99"<<endl;
    cin>> userPopDensity;

    cout<<"\n\nWhat mode would you like to see?"<<endl;
	cout<< "\n\nType 1 - Classic Mode | Type 2 - Donut Mode | Type 3 - Mirror Mode| "<<endl;
    cin>>userMode;

	cout<<"\n\nPress 1 if you would like a brief pause between each generation\n";
	cout<<"Press 2 if you would like to press enter between each generation\n";
	cout<<"Press 3 if you would like all output to be written to a .txt file\n\n";
	cin >> outputChoice;
	cout<<endl;

    switch (userMode)
    {
      case 1: //Classic Mode
	      	{

	      		cout << "\nUser Selected Classic Mode\n";

	      		char** CurrentArray = Create2DRandArray(userRows, userCols, userPopDensity);

	    		Donut CurrentDonut = Donut(CurrentArray, userCols, userRows);

	    		char** NextArray = CurrentDonut.CreateNextGen_P();
	    		Donut NextDonut = Donut(NextArray, userCols, userRows);

	    		if(outputChoice == 1)
	    		{
	    			cout << "\nOriginal Classic Array\n";
	    			CurrentDonut.printDonut();
	    			sleep(1);
	    		}

	    		else if(outputChoice == 2)
	    		{
	    			cout << "\nOriginal Classic Array\n";
	    			CurrentDonut.printDonut();
	    			cin.get();
	    		}

	    		else if (outputChoice ==3)
	    		{
	    			cout << "What would you like to name the new file?: ";
	    			cin >> userTextFile;
	    			userTextFile = userTextFile+".txt";
	    			CurrentDonut.WriteToFile(userTextFile);
	    			cout << "Writing to file. Please Wait.";
	    		}

	    		for(genCount = 1; genCount != genEnd; genCount++)
	    		{
	    			int currentAliveCount = 0;
	    			int nextAliveCount = 0;
	    			int killCount = 0;


	    			//TRANSFORM!
	    			for(int i = 0; i < userRows; i++)
	     			{
	       				for(int j = 0; j < userCols; j++)
	       				{
	         				TransformClassic(CurrentDonut, NextDonut, i, j);
	       				}
	     			}

	     			if(outputChoice == 1)
	       			{	
	       				cout << "\nClassic Generation Number: " << genCount<<"\n";
	       				NextDonut.printDonut();
		    			CurrentDonut.array = NextDonut.array;
		    			sleep(1);
		    			
		    		}

		    		else if(outputChoice == 2)
	       			{	
	       				cout << "\nClassic Generation Number: " << genCount<<"\n";
	       				NextDonut.printDonut();
		    			CurrentDonut.array = NextDonut.array;
		    			cin.get();	
		    		}

		    		else if(outputChoice == 3)
		    		{
		    			
		    			NextDonut.WriteToFile(userTextFile);
		    			CurrentDonut.array = NextDonut.array;
		    		}
	    			
				}
	       		break;

	      	}

      case 2: //Donut Mode
      		{

	      		cout << "\nUser Selected Donut Mode\n";

	      		char** CurrentArray = Create2DRandArray(userRows, userCols, userPopDensity);

	    		Donut CurrentDonut = Donut(CurrentArray, userCols, userRows);

	    		char** NextArray = CurrentDonut.CreateNextGen_P();
	    		Donut NextDonut = Donut(NextArray, userCols, userRows);

	    		if(outputChoice == 1)
	    		{
	    			cout << "\nOriginal Donut Array\n";
	    			CurrentDonut.printDonut();
	    			sleep(1);
	    		}

	    		else if(outputChoice == 2)
	    		{
	    			cout << "\nOriginal Donut Array\n";
	    			CurrentDonut.printDonut();
	    			cin.get();
	    		}

	    		else if (outputChoice ==3)
	    		{
	    			cout << "What would you like to name the new file?: ";
	    			cin >> userTextFile;
	    			userTextFile = userTextFile+".txt";
	    			CurrentDonut.WriteToFile(userTextFile);
	    			cout << "Writing to file. Please Wait.";
	    		}

	    		for(genCount = 1; genCount != genEnd; genCount++)
	    		{
	    			int currentAliveCount = 0;
	    			int nextAliveCount = 0;
	    			int killCount = 0;


	    			//TRANSFORM!
	    			for(int i = 0; i < userRows; i++)
	     			{
	       				for(int j = 0; j < userCols; j++)
	       				{
	         				TransformDonut(CurrentDonut, NextDonut, i, j);
	       				}
	     			}

	     			if(outputChoice == 1)
	       			{	
	       				cout << "\nClassic Generation Number: " << genCount<<"\n";
	       				NextDonut.printDonut();
		    			CurrentDonut.array = NextDonut.array;
		    			sleep(1);
		    			
		    		}

		    		else if(outputChoice == 2)
	       			{	
	       				cout << "\nClassic Generation Number: " << genCount<<"\n";
	       				NextDonut.printDonut();
		    			CurrentDonut.array = NextDonut.array;
		    			cin.get();	
		    		}

		    		else if(outputChoice == 3)
		    		{
		    			
		    			NextDonut.WriteToFile(userTextFile);
		    			CurrentDonut.array = NextDonut.array;
		    		}
	    			
				}
	       		break;
	       		
	    	}


      case 3: //Mirror Mode
      		{

	      		cout << "\nUser Selected Mirror Mode\n";

	      		char** CurrentArray = Create2DRandArray(userRows, userCols, userPopDensity);

	    		Donut CurrentDonut = Donut(CurrentArray, userCols, userRows);

	    		char** NextArray = CurrentDonut.CreateNextGen_P();
	    		Donut NextDonut = Donut(NextArray, userCols, userRows);

	    		if(outputChoice == 1)
	    		{
	    			cout << "\nOriginal Mirror Array\n";
	    			CurrentDonut.printDonut();
	    			sleep(1);
	    		}

	    		else if(outputChoice == 2)
	    		{
	    			cout << "\nOriginal Mirror Array\n";
	    			CurrentDonut.printDonut();
	    			cin.get();
	    		}

	    		else if (outputChoice ==3)
	    		{
	    			cout << "What would you like to name the new file?: ";
	    			cin >> userTextFile;
	    			userTextFile = userTextFile+".txt";
	    			CurrentDonut.WriteToFile(userTextFile);
	    			cout << "Writing to file. Please Wait.";
	    		}

	    		for(genCount = 1; genCount != genEnd; genCount++)
	    		{
	    			int currentAliveCount = 0;
	    			int nextAliveCount = 0;
	    			int killCount = 0;


	    			//TRANSFORM!
	    			for(int i = 0; i < userRows; i++)
	     			{
	       				for(int j = 0; j < userCols; j++)
	       				{
	         				TransformMirror(CurrentDonut, NextDonut, i, j);
	       				}
	     			}

	     			if(outputChoice == 1)
	       			{	
	       				cout << "\nClassic Generation Number: " << genCount<<"\n";
	       				NextDonut.printDonut();
		    			CurrentDonut.array = NextDonut.array;
		    			sleep(1);
		    			
		    		}

		    		else if(outputChoice == 2)
	       			{	
	       				cout << "\nClassic Generation Number: " << genCount<<"\n";
	       				NextDonut.printDonut();
		    			CurrentDonut.array = NextDonut.array;
		    			cin.get();	
		    		}

		    		else if(outputChoice == 3)
		    		{
		    			
		    			NextDonut.WriteToFile(userTextFile);
		    			CurrentDonut.array = NextDonut.array;
		    		}
	    			
				}
	       		break;
	       		
	    	}

      default: //Classic Mode
	      	{

	      		cout << "\nUser Selected Classic Mode\n";

	      		char** CurrentArray = Create2DRandArray(userRows, userCols, userPopDensity);

	    		Donut CurrentDonut = Donut(CurrentArray, userCols, userRows);

	    		char** NextArray = CurrentDonut.CreateNextGen_P();
	    		Donut NextDonut = Donut(NextArray, userCols, userRows);

	    		if(outputChoice == 1)
	    		{
	    			cout << "\nOriginal Classic Array\n";
	    			CurrentDonut.printDonut();
	    			sleep(1);
	    		}

	    		else if(outputChoice == 2)
	    		{
	    			cout << "\nOriginal Classic Array\n";
	    			CurrentDonut.printDonut();
	    			cin.get();
	    		}

	    		else if (outputChoice ==3)
	    		{
	    			cout << "What would you like to name the new file?: ";
	    			cin >> userTextFile;
	    			userTextFile = userTextFile+".txt";
	    			CurrentDonut.WriteToFile(userTextFile);
	    			cout << "Writing to file. Please Wait.";
	    		}

	    		for(genCount = 1; genCount != genEnd; genCount++)
	    		{
	    			int currentAliveCount = 0;
	    			int nextAliveCount = 0;
	    			int killCount = 0;


	    			//TRANSFORM!
	    			for(int i = 0; i < userRows; i++)
	     			{
	       				for(int j = 0; j < userCols; j++)
	       				{
	         				TransformClassic(CurrentDonut, NextDonut, i, j);
	       				}
	     			}

	     			if(outputChoice == 1)
	       			{	
	       				cout << "\nClassic Generation Number: " << genCount<<"\n";
	       				NextDonut.printDonut();
		    			CurrentDonut.array = NextDonut.array;
		    			sleep(1);
		    			
		    		}

		    		else if(outputChoice == 2)
	       			{	
	       				cout << "\nClassic Generation Number: " << genCount<<"\n";
	       				NextDonut.printDonut();
		    			CurrentDonut.array = NextDonut.array;
		    			cin.get();	
		    		}

		    		else if(outputChoice == 3)
		    		{
		    			
		    			NextDonut.WriteToFile(userTextFile);
		    			CurrentDonut.array = NextDonut.array;
		    		}
	    			
				}
	       		break;

	      	}
    }
  }

  return 0;
}