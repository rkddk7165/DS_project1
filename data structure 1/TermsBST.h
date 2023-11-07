#pragma once
#include "TermsBSTNode.h"

class TermsBST
{
private:
	TermsBSTNode* root;
public:
	TermsBST();

	//return root
	TermsBSTNode* getRoot();

	// Function to add a new node to TermsBST
	TermsBSTNode* insert(TermsBSTNode* node, string& name, int age, string& collectionDate, char agreementType);

	//Function to find the smallest node
	TermsBSTNode* findmin(TermsBSTNode* node);

	//Function that finds and removes the location of the node received as an argument.
	TermsBSTNode* DELETE(TermsBSTNode* node, const string& name);

	//Insert new data into the root node
	void add( string name, int age, string& collectionDate, char agreementType);

	//find and remove the location of the node received as an argument.
	bool DELETE(const string& name);

	//A function to find a node that has the name received as an argument as data by traversing the node.
	void inorderSearch(TermsBSTNode* node, ostream& output, const string& searchName = "");

	//A function that traverses in-order to find a node that has the name received as an argument as data and outputs the data.
	void inorderPrint(TermsBSTNode* node, ostream& output);

	//Function to operate the command SEARCH
	void SEARCH(ostream& output, const string& searchName = "");

	//Function to operate the command PRINT
	void PRINT(ostream& output);

	//A function that uses an expiredate to find a node that has that expiredate as data.
	TermsBSTNode* searchNode(TermsBSTNode* node, const string& name);
};
