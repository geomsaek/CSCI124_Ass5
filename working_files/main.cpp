/*****

Name:			Matthew Saliba
Subject:		CSCI124
Student Num:	3284165
Title:			Assignment 5
Lab:			A: 0830 - 1030

Description:	Contains the main calling function of the program as well as the declaration of the binary tree pointer
				
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

int main(){
	
	// creates a new instance of the molecule structure
	molecule * userList = NULL;
	// holds the total number of molecules
	int totalMolecules = 0;
	
	// controls the while loop
	bool userQuit = false;
	
	// controls the overall function of the program
	// displaying the main menu
	while(userQuit == false){
		// return value determines whether then main menu is to
		// stop of keep going
		// function passes the first instance of the structure to be used in the list
		userQuit = getUserInput(userList, totalMolecules);
	}
	
	
	
	return 0;
}
