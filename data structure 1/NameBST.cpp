#pragma once

#include "NameBST.h"
#include <fstream>
#include <sstream>

NameBST::NameBST() : root(nullptr)
{

}

//return root
NameBSTNode* NameBST::getRoot()
{
	return root;
}
// Function to add a new node to NameBST in lexicographic order of names
NameBSTNode* NameBST::insert(NameBSTNode* node, const string& name, int age, const string& collectionDate, char agreementType) {
	if (node == nullptr) {
		return new NameBSTNode(name, age, collectionDate, agreementType);
	}
	if (name < node->name) {
		node->left = insert(node->left, name, age, collectionDate, agreementType);
	} //Comparing the lexicographic order of names
	else {
		node->right = insert(node->right, name, age, collectionDate, agreementType);
	}//if node find a node in an appropriate location, add it by calling insert()
	return node;
}
//Function to find the smallest node
NameBSTNode* NameBST::findmin(NameBSTNode* node) {
	while (node->left != nullptr) {
		node = node->left;
	}
	return node;
}
////Function that finds and removes the location of the node received as an argument.
NameBSTNode* NameBST::DELETE(NameBSTNode* node, const string& name) {
	if (node == nullptr) {
		return nullptr;
	}

	if (name < node->name) {
		node->left = DELETE(node->left, name);
	}

	else if (name > node->name) {
		node->right = DELETE(node->right, name);
	}
	else {
		if (node->left == nullptr) {
			NameBSTNode* temp = node->right;
			delete node;
			return temp;
		}
		else if (node->right == nullptr) {
			NameBSTNode* temp = node->left;
			delete node;
			return temp;
		}
		//Use the findmin function to traverse TermsBST and remove nodes before the expire date received as an argument.
		NameBSTNode* temp = findmin(node->right);
		node->name = temp->name;
		node->age = temp->age;
		node->collectionDate = temp->collectionDate;
		node->expireDate = temp->expireDate;
		node->agreementType = temp->agreementType;
		node->right = DELETE(node->right, temp->name);
	}
	return node;

}
//Insert new data into the root node
void NameBST::add(const string& name, int age, const string& collectionDate, char agreementType) {
	root = insert(root, name, age, collectionDate, agreementType);
}
//find and remove the location of the node received as an argument.
bool NameBST::DELETE(const string& name) {
	root = DELETE(root, name);
	return true;
}
//A function to find a node that has the name received as an argument as data by traversing the node.
void NameBST::inorderSearch(NameBSTNode* node, ostream& output, const string& searchName) {
	if (node == nullptr) {
		return;
	}

	inorderSearch(node->left, output, searchName); //call recursively

	//Output only when searchName is empty or the name of the current node matches searchName
	if (searchName.empty() || node->name == searchName) {
		output << "= = = = = SEARCH = = = = =" << endl << node->name << "/" << node->age << "/" << node->collectionDate << "/" << node->expireDate <<  endl << "= = = = = = = = = = = = = =" << endl;
	}
	inorderSearch(node->right, output, searchName); //call recursively
}

void NameBST::inorderPrint(NameBSTNode* node, ostream& output, const string& searchName) {
	if (node == nullptr) {
		return;
	}

	inorderPrint(node->left, output, searchName); //call recursively

	//Output only when searchName is empty or the name of the current node matches searchName
	if (searchName.empty() || node->name == searchName) {
		output << node->name << "/" << node->age << "/" << node->collectionDate << "/" << node->expireDate << endl;
	}

	inorderPrint(node->right, output, searchName); //call recursively
	
}
//Function to operate the command PRINT
void NameBST::PRINT(ostream& output, const string& searchName) {
	output << "= = = = = PRINT = = = = =" << endl;
	inorderPrint(root, output, searchName);
	output << "= = = = = = = = = = = = =" << endl;
}
//Function to operate the command SEARCH
void NameBST::SEARCH(ostream& output, const string& searchName) {
	inorderSearch(root, output, searchName);
}



//A function to find a node with the name received as an argument as data by calling the searchNode function
void NameBST::search(const string& name) {
	NameBSTNode* result = searchNode(root, name);
}
//A function that uses an expiredate to find a node that has that expiredate as data.
NameBSTNode* NameBST::searchNode(NameBSTNode* node, const string& name) {
	if (node == nullptr) {
		return nullptr;
	}

	if (name == node->name) {
		return node;
	}
	else if (name < node->name) {
		return searchNode(node->left, name);
	}
	else {
		return searchNode(node->right, name);
	}
}
