/*****

Name:			Matthew Saliba
Subject:		CSCI124
Student Num:	3284165
Title:			Assignment 5
Lab:			A: 0830 - 1030

Description:	Contains the prototypes of the functions contained within the menus.cpp file

Last Modified:	26th October 2013

NOTE:			USED ALLEN'S POST ORDER TRAVERSAL FUNCTION, A MODIFIED VERSION OF THE INSERT
				NODE TO BINARY TREE FUNCTION, CMP FUNCTION, DELETE NODE AND VISIT FUNCTION.
				
				THESE WERE USED AS THEY WERE THE SIMPLEST TO IMPLEMENT IN TERMS OF PERFORMING
				THE REQUIRED OPERATIONS FOR THIS TASK.

******/

#include<iostream>
#include<fstream>
#include<cctype>
#include<cstring>
#include<cstdlib>

using namespace std;

// function displays the main menu text and available options
void displayMainMenu();

// returns a boolean value based on the input from the selection of values from the main menu
bool getUserInput(mptr &, int &);

// displays the number of imported molecules in the list
void displayMCount(mptr &, int, int &);
