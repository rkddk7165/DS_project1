#pragma once
#include "NameBSTNode.h"

class NameBST
{
private:
	NameBSTNode* root;
public:
	NameBST();
	
	//return root
	NameBSTNode* getRoot();

	// Function to add a new node to NameBST in lexicographic order of names
	NameBSTNode* insert(NameBSTNode* node, const string& name, int age, const string& collectionDate, char agreementType);

	//Find the smallest node
	NameBSTNode* findmin(NameBSTNode* node);

	//Find and remove nodes that have the name received as an argument as data.
	NameBSTNode* DELETE(NameBSTNode* node, const string& name);

	//Insert new data into the root node
	void add(const string& name, int age, const string& collectionDate, char agreementType);

	//find and remove the location of the node received as an argument.
	bool DELETE(const string& name);

	//A function to find a node that has the name received as an argument as data by traversing the node.
	void inorderSearch(NameBSTNode* node, ostream& output, const string& searchName = "");

	//A function that traverses in-order to find a node that has the name received as an argument as data and outputs the data.
	void inorderPrint(NameBSTNode* node, ostream& output, const string& searchName = "");

	//Function to operate the command SEARCH
	void SEARCH(ostream& output, const string& searchName = "");

	//Function to operate the command PRINT
	void PRINT(ostream& output, const string& searchName = "");	

	//Function to operate the command PRINT
	void search(const string& name);

	//A function that uses an expiredate to find a node that has that expiredate as data.
	NameBSTNode* searchNode(NameBSTNode* node, const string& name);
};
