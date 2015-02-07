/*****

Name:			Matthew Saliba
Subject:		CSCI124
Student Num:	3284165
Title:			Assignment 5
Lab:			A: 0830 - 1030
Description:	Handles the display of menus and actions of the different menus of the program

Last Modified:	26th October 2013

NOTE:			USED ALLEN'S POST ORDER TRAVERSAL FUNCTION, A MODIFIED VERSION OF THE INSERT
				NODE TO BINARY TREE FUNCTION, CMP FUNCTION, DELETE NODE AND VISIT FUNCTION.
				
				THESE WERE USED AS THEY WERE THE SIMPLEST TO IMPLEMENT IN TERMS OF PERFORMING
				THE REQUIRED OPERATIONS FOR THIS TASK.

******/

#include "header.h"
#include "menus.h"
#include<iostream>
#include<fstream>
#include<cctype>
#include<cstring>
#include<cstdlib>

using namespace std;

// function displays the main menu text and available options
void displayMainMenu(){
	
	cout << endl;
	cout << '\t' << '\t' << "/*********************** MAIN MENU ***********************/" << endl;
	cout << endl;
	cout << "     I - Import the data from a data file. Prompt the user for the name of a file for import." << endl;
	cout << "     N - Display the number of molecules imported" << endl;
	cout << "     R - Generate a report to the display. A report contains the following information:" << endl;
	cout << '\t' << "1. total number of molecules" << endl;
	cout << '\t' << "2. number of lonely molecules" << endl;
	cout << '\t' << "3. average speed of the lonely molecules" << endl;
	cout << '\t' << "4. average energy of the lonely molecules" << endl;
	cout << "     q - quit the program" << endl;
	cout << endl;
	cout << "     Please enter your selection: ";
	
	return;
}

// retrieves the user's selection based on the options available in the main menu

bool getUserInput(mptr & root, int & molecules){
	
	char userInput;
	char validVals[4] = { 'I','N','R','q' };
	int duplicateMolecules = 0;
	
	// while the user has not selected the (q)uit option
	while(userInput != 'q'){
		
		displayMainMenu();
		
		// run a function to handle the input and validation of the selection requested from the user
		userInput = validateInput(validVals, 4);
		cin.clear();
		cin.ignore(1000,'\n');
		
		// enter the appropriate statement based on the user's choice
		switch(userInput){
			
			case 'I':
				// function adds a list of molecules to a list and increases the count
				addToList(root, molecules, duplicateMolecules);	
				cout << endl;
				cout << "---------- IMPORT COMPLETE!!!! ----------" << endl;
				cout << endl;
			break;
			
			case 'N':
				// outputs the number of molecules if there is an existing list
				if(molecules == 0){
					cout << endl;
					cout << "---------- There are no imported molecule records. Please upload some first!! ----------" << endl;
					cout << endl;
				}else {
					displayMCount(root, molecules, duplicateMolecules);
				}
			break;
			
			case 'R':
				//outputs a report based on the number of lonely molecules provided that there are any
				if(molecules == 0){
					cout << endl;
					cout << "---------- There are no imported molecule records. Please upload some first!! ----------" << endl;
					cout << endl;
				}else {
					generateReport(root, molecules, duplicateMolecules);
				}
			break;
			
			case 'q':
				// quits the program and deletes the current list
				cout << endl;
				cout << '\t' << '\t' << "/*********************** You Quit the program! ***********************/" << endl;
				cout << endl;
				removeTree(root);
			break;
		}
	}
	return true;
}


// displays the number of imported molecules in the current list
void displayMCount(mptr & root, int molecules, int & duplicateMolecules){
	
	cout << endl;
	cout << "/******************** THE TOTAL NUMBER OF MOLECULES IMPORTED WAS: " << molecules << " ********************/" << endl;
	cout << endl;
	
	if(duplicateMolecules > 0){
		cout << "There were duplicated Finger Print IDs found in the following number of records: " << duplicateMolecules << endl;
	}
	
	// outputs the data of all nodes in the list
	postorderTraversal (root, 1);
	
	

	return;
}
