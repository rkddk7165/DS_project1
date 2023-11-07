#pragma once

#include "TermsList.h"
#include "TermsBSTNode.h"

TermsBST::TermsBST() : root(nullptr)
{

}

//return root
TermsBSTNode* TermsBST::getRoot()
{
	return root;
}
// Function to add a new node to TermsBST
TermsBSTNode* TermsBST::insert(TermsBSTNode* node, string& name, int age, string& collectionDate, char agreementType) {
	string expireDate = node->calculateExpireDate(collectionDate, agreementType);
	
	if (node == nullptr) {
		return new TermsBSTNode(name, age, collectionDate, agreementType);
	}
	if (expireDate < node->expireDate) {
		node->left = insert(node->left, name, age, collectionDate, agreementType);
	}
	else {
		node->right = insert(node->right, name, age, collectionDate, agreementType);
	}
	return node;
}

//Function to find the smallest node
TermsBSTNode* TermsBST::findmin(TermsBSTNode* node) {
	while (node->left != nullptr) {
		node = node->left;
	}
	return node;
}

////Function that finds and removes the location of the node received as an argument.
TermsBSTNode* TermsBST::DELETE(TermsBSTNode* node, const string& expireDate) {
	if (node == nullptr) {
		return nullptr;
	}

	if (expireDate < node->expireDate) {
		node->left = DELETE(node->left, expireDate);
	}

	else if (expireDate > node->expireDate) {
		node->right = DELETE(node->right, expireDate);
	}
	else {
		if (node->left == nullptr) {
			TermsBSTNode* temp = node->right;
			delete node;
			return temp;
		}
		else if (node->right == nullptr) {
			TermsBSTNode* temp = node->left;
			delete node;
			return temp;
		}
		//Use the findmin function to traverse TermsBST and remove nodes before the expire date received as an argument.
		TermsBSTNode* temp = findmin(node->right); 
		node->expireDate = temp->expireDate;
		node->age = temp->age;
		node->collectionDate = temp->collectionDate;
		node->expireDate = temp->expireDate;
		node->agreementType = temp->agreementType;
		node->right = DELETE(node->right, temp->expireDate); 
	}
	return node;

}
//Insert new data into the root node
void TermsBST::add( string name, int age, string& collectionDate, char agreementType) {
	root = insert(root, name, age, collectionDate, agreementType);
}
//find and remove the location of the node received as an argument.
bool TermsBST::DELETE(const string& expireDate) {
	root = DELETE(root, expireDate);
	return true;
}
//A function to find a node that has the name received as an argument as data by traversing the node.
void TermsBST::inorderSearch(TermsBSTNode* node, ostream& output, const string& searchName) {
	if (node == nullptr) {
		return;
	}

	inorderSearch(node->left, output, searchName); //call recursively

	//Output only when searchName is empty or the name of the current node matches searchName
	if (searchName.empty() || node->name == searchName) {
		output << "= = = = = SEARCH = = = = =" << endl << node->name << "/" << node->age << "/" << node->collectionDate << "/" << node->expireDate << endl << "= = = = = = = = = = = = = =" << endl;
	}
	else output << "= = = = = ERROR = = = = =" << endl << "400" << endl << "= = = = = = = = = = = = =" << endl;

	inorderSearch(node->right, output, searchName); //call recursively
}
//A function that traverses in-order to find a node that has the name received as an argument as data and outputs the data.
void TermsBST::inorderPrint(TermsBSTNode* node, ostream& output) {
	if (node == nullptr) {
		return;
	}

	inorderPrint(node->left, output); //call recursively
	//Output only when searchName is empty or the name of the current node matches searchName
	output << node->name << "/" << node->age << "/" << node->collectionDate << "/" << node->expireDate << endl;
	inorderPrint(node->right, output); //call recursively
}
//Function to operate the command PRINT
void TermsBST::PRINT(ostream& output) {
	inorderPrint(root, output);
}

//Function to operate the command SEARCH
void TermsBST::SEARCH(ostream& output, const string& searchName) {
	inorderSearch(root, output, searchName);
}

//A function that uses an expiredate to find a node that has that expiredate as data.
TermsBSTNode* TermsBST::searchNode(TermsBSTNode* node, const string& expireDate) {
	if (node == nullptr) {
		return nullptr;
	}

	if (expireDate == node->expireDate) {
		return node;
	}
	else if (expireDate < node->expireDate) {
		return searchNode(node->left, expireDate);
	}
	else {
		return searchNode(node->right, expireDate);
	}
}

