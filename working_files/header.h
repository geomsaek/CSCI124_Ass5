/*****

Name:			Matthew Saliba
Subject:		CSCI124
Student Num:	3284165
Title:			Assignment 5
Lab:			A: 0830 - 1030

Description:	Contains the prototypes of the functions used in the functions.cpp file
				
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

struct molecule;
typedef molecule * mptr;

struct molecule{
	float position;
	float speed;
	float energy;
	char fingerPrint[9];
	int dupCount;
	mptr parent, left, right;

};


// function receives the file name to import and tests if its valid or not
// repeats input until a valid file is found
void addToList(mptr &, int &, int &);

// function checks whether the extension of the file name is correct
// and returns a boolean depending this
bool fileNameCheck(char [], int, char [], int);

//function checks whether the correct choice has been entered
// and compares it to a selection of valid values
// otherwise returns an error message and repeats input
char validateInput(char [], int);

// function opens the file given the correct name that has been
// entered and populates a list via the read in of the values in the file
void openFileImport(char [], mptr &, int&, int &);

// NOTE: Allen Function, function creates a new node to insert into a tree
mptr createNode(float, float, float, char[]);

// NOTE: Allen Function, function decides where to insert a node into the binary tree based on the passed values
void insert(mptr &, float, float, float, char [], int &);

// NOTE: Allen Function, function returns the difference of two floating point values
float cmp(float &, float &);

// NOTE: Allen Function, function removes a node a binary search tree
void removeTree(mptr & root);

// NOTE: Allen Function, function performs a post order traversal in a binary search tree
void postorderTraversal (mptr &, int);

// NOTE: Allen Function, function performs a particular operation upon visit to a node in a binary tree
void visit(mptr & root, int);

// function performs the comparison's that are needed to output the lonely molecule report
void reportTraversal(mptr &, int, int&, float &, float &);

// function finds whether a file name exists or not
bool findExist(char []);

// function generates the report to display to the user based
// on the location of lonely molecules given the current list
void generateReport(mptr &, int &, int &);
