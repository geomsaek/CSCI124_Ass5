/*****

Name:			Matthew Saliba
Subject:		CSCI124
Student Num:	3284165
Title:			Assignment 5
Lab:			A: 0830 - 1030

Description:	File contains all the functions that handle file object, reading, and population
				to a binary search tree. File also decides whether a function is lonely or not
				
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

// function opens the checks for the appropriate file and opens it if the name exists
// then passes the file object along with the tree ptr and molecule count to another
// to handle the import and create the binary tree
void addToList(mptr & head, int & molecules, int & duplicateMolecules){
	
	char fileName[21] = { '\0' };
	bool validF = false;
	
	char ext[5] = { ".txt" };
	bool getFileName = false;
	
	cout << "Please enter a file to import your data from: ";
	while(getFileName == false){
	
		cin.getline(fileName, 20, '\n');
		
		getFileName = fileNameCheck(fileName, strlen(fileName), ext, strlen(ext));
		
		validF = findExist(fileName);
		
		if(getFileName == false || validF == false){
			cout << "Please enter a valid file name: ";
			cin.clear();
			validF = false;
			getFileName = false;
		}
	}
	
	openFileImport(fileName, head, molecules, duplicateMolecules);

	return;
}

// function checks whether the name of the file contains the correct characters
// given a passed set of valid values

bool fileNameCheck(char userName[], int length, char check[], int vldLen){

	int countMatch = 0;
	
	for(int i = 0; i < length; i++){
		for(int k = 0; k < vldLen; k++){
			if(userName[i] == check[k]){
				countMatch = countMatch + 1;
				k = vldLen + 1;
			}
		}
		
	}
	
	if(countMatch == vldLen){
		return true;
	}else {
		return false;
	}
}


// function checks whether the set of values is within a set of matched values and
// returns the valid choice
char validateInput(char validVals[], int vldLen){
	
	bool invalid = false;
	char choice;
	
	while(invalid == false){
		cin >> choice;
		
		for(int i = 0; i <vldLen; i++){
			if(choice == validVals[i]){
				invalid = true;
			}
		}
		if(invalid == false){
			cin.clear();
			cin.ignore(1000,'\n');
			cout << "     " <<  "Please enter a valid value: ";
		}
	}
	
	return choice;
}

// function opens a given a valid name, retrieves the values of the molecules and calls
// the another to place the extracted values in a binary search tree
// function also passes the molecule count to the called function

void openFileImport(char fileName[], mptr & root, int& molecules, int & duplicateMolecules){
	
	ifstream file;
	char line[51];
	int counter = 0;
	bool hold = true;
	
	float posVal = 0;
	float speedVal = 0;
	float energyVal = 0;
	
	
	file.open(fileName);
	
	while(!file.eof()){
		file.getline(line, 50,'\n');
		
		if(strcmp(line, "#") != 0){
			
			switch(counter){
				case 0: {
					posVal = atof(line);
					hold = true;
				}
				break;
		
				case 1: {
					speedVal = atof(line);
					}
				break;
		
				case 2:
					energyVal = atof(line);
				break;
				
				case 3:
					insert(root, posVal, speedVal, energyVal, line, duplicateMolecules);
					
					hold = false;
					molecules = molecules + 1;
					posVal = 0;
					speedVal = 0;
					counter = 0;
				break;
				
			}
			if(hold){
				counter = counter + 1;	
			}
		}else {
			
		}
	}

	return;
}

// function creates a new node to insert to a binary search tree

mptr createNode(float posVal, float speedVal, float energyVal, char tempPrint[]){
	
	mptr tmp = new molecule;
	tmp->position = posVal;
	tmp->speed = speedVal;
	tmp->energy = energyVal;
	strcpy(tmp->fingerPrint, tempPrint);
	tmp->dupCount = 0;
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->parent = NULL;
	
	return tmp;
}

// function assesses where to put a node in a binary search tree
// if there is a duplicate the function updates the dupCount property of the molecule

void insert(mptr & root, float posVal, float speedVal, float energyVal, char tempPrint[], int & duplicateMolecules){
	
	
	if(root == NULL){
		root = createNode(posVal, speedVal, energyVal, tempPrint);
		root->parent = NULL;
	}
	else if(strcmp(root->fingerPrint, tempPrint) == 0){
		root->dupCount = root->dupCount + 1;
		duplicateMolecules = duplicateMolecules + 1;
	}	
	else if(cmp(posVal, root->position) > 0){
	
		if(root->right == NULL){
			root->right = createNode(posVal, speedVal, energyVal, tempPrint);
			(root->right)->parent = root;
		}else {
			insert(root->right, posVal, speedVal, energyVal, tempPrint, duplicateMolecules);
		}
		
	}else if(cmp(posVal, root->position) < 0){
	
		if(root->left == NULL){
			root->left = createNode(posVal, speedVal, energyVal, tempPrint);
			(root->left)->parent = root;
		}else {
			insert(root->left, posVal, speedVal, energyVal, tempPrint, duplicateMolecules);
		}
		
	}else {
		insert(root->left, posVal, speedVal, energyVal, tempPrint, duplicateMolecules);
	}
	
	return;
}

// function returns the difference of the position value between two molecules

float cmp(float & posA, float & posB){
	
	return(posA - posB);
}


// function finds whether a file name exists or not
bool findExist(char fileName[]){

	ifstream check;
	
	check.open(fileName);
	if(check.good()){
		check.close();
		return true;
	}
	else {
		return false;
	}
}

// function performs a post order traversal in the binary search tree
// function calls the visit function to display the details of each node
void postorderTraversal (mptr & root, int method){
	
	if(root != NULL){
		postorderTraversal(root->left, method);
		postorderTraversal(root->right, method);
		visit(root, method);
	}
	
	return;
}

// function calls the function to visit the binary tree in a post order traversal
// and delete each node upon each visit
void removeTree(mptr & root){

	postorderTraversal(root, 2);
	
	
	return;
}

// the function visits a particular node and performs a series of methods
// based on a value that is passed to it:
// 1 - outputs the details of a molecule, 2- deletes a particular node
void visit(mptr & root, int method){

	switch(method){
	
		case 1:
			cout << endl;
			cout << "Position: " << root->position << endl;
			cout << "Speed: " << root->speed << endl;
			cout << "Energy: " << root->energy << endl;
			cout << "Finger Print: " << root->fingerPrint << endl;
			cout << endl;
			break;
		break;
		
		case 2:
			if(root != NULL){
				delete root;
			}
			root = NULL;
		break;
		
		default:
			cout << "Undefined method!" << endl;
		break;
	}
}



// function generates the report to display to the user based
// on the location of lonely molecules given the current list
void generateReport(mptr & root, int & molecules, int &duplicateMolecules){
	
	int lonelyCount = 0;
	float averageSpeed = 0;
	float averageEnergy = 0;
	int reduceMolecule = 0;
	
	
	cout << endl;
	reportTraversal(root, -1, lonelyCount, averageSpeed, averageEnergy);
	if(lonelyCount > 0){
		cout << "/************************* MOLECULE REPORT *************************/" << endl;
		cout << endl;
		averageSpeed = averageSpeed / lonelyCount;
		averageEnergy = averageEnergy / lonelyCount;
		
		cout << endl;
		cout << "Total number of molecules (excluding discarded): " << duplicateMolecules << endl;
		cout << "Total Number of Lonely Molecules: " << lonelyCount << endl;
		cout << "AverageSpeed: " << averageSpeed << endl;
		cout << "AverageEnergy: " << averageEnergy << endl;
	}else {
		cout << "/********** Sorry!! There were no lonely molecules in your selection **********/" << endl;
	}
		
	return;
}

// function traverses a binary search tree in a post order style and compares the values of the 
// molecule to decide whether the molecule is lonely or not

void reportTraversal(mptr & root, int current, int & lonelyCount, float & averageSpeed, float & averageEnergy){
	
	bool initial = false;
	
	if(current == -1){
		if(root->left != NULL){
			if(root->left->dupCount == 0 && root->dupCount == 0){
				if(root->position >= (root->left->position + 100) || root->position <= (root->left->position -100)){
					initial = true;
				}
			}else {
				if(root->dupCount == 0){
					initial = true;
				}
			}
		}
		
		if(root->right != NULL){
			if(root->right->dupCount == 0 && root->dupCount == 0){
				if(root->position >= (root->right->position + 100) || root->position <= (root->right->position -100)){
					initial = true;
				}
			}else {
				if(root->dupCount == 0){
					initial = true;
				}
				
			}
		}
		
		if(initial){
			lonelyCount = lonelyCount + 1;
			averageSpeed = averageSpeed + root->speed;
			averageEnergy = averageEnergy + root->energy;
		}
		
		reportTraversal(root->right, root->position, lonelyCount, averageSpeed, averageEnergy);
		reportTraversal(root->left, root->position, lonelyCount, averageSpeed, averageEnergy);
	}else {
		if(root != NULL){
		
			if(root->dupCount == 0){
				if(root->position >= (current + 100) || root->position <= (current -100)){
				
					lonelyCount = lonelyCount + 1;
					averageSpeed = averageSpeed + root->speed;
					averageEnergy = averageEnergy + root->energy;
				}
			}
		
			reportTraversal(root->right, root->position, lonelyCount, averageSpeed, averageEnergy);
			reportTraversal(root->left, root->position, lonelyCount, averageSpeed, averageEnergy);
		}
	}
	
	
	return;
}
