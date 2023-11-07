#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

class TermsBSTNode
{
private:
	TermsBSTNode* left;
	TermsBSTNode* right;

	friend class TermsBST;
	friend class TemrsLIST;
public:
	string name;
	int age;
	string collectionDate;
	string expireDate;
	char agreementType;

	//calculate expire date by adding the number of months corresponding to collection date to agreement
	string calculateExpireDate(string& collectionDate, char agreementType) {
		//Parse collectionDate and separate it into year, month, and day
		int year, month, day;
		sscanf_s(collectionDate.c_str(), "%d-%d-%d", &year, &month, &day);


		//Calculate personal information expire date according to agreementType
		int monthsToAdd = 0;
		switch (agreementType) {
		case 'A':
			monthsToAdd = 6;
			break;
		case 'B':
			monthsToAdd = 12;
			break;
		case 'C':
			monthsToAdd = 24;
			break;
		case 'D':
			monthsToAdd = 36;
			break;
		}

		// calculate expireDate
		year += (month + monthsToAdd - 1) / 12;
		month = (month + monthsToAdd - 1) % 12 + 1;

		
		char expireDate[11];
		snprintf(expireDate, sizeof(expireDate), "%04d-%02d-%02d", year, month, day); //Convert the calculated year, month, and day back to a string

		return string(expireDate);
	}

	//constructor that initializes variables of TemrsBSTNode class
	TermsBSTNode(string&name, int age,  string &collectionDate, char agreementType)
		: name(name), age(age), collectionDate(collectionDate), agreementType(agreementType), left(nullptr), right(nullptr) {
		// calculate expireDate
		expireDate = calculateExpireDate(collectionDate, agreementType);
	}

	TermsBSTNode* getLeft() {
		return left;
	}
	TermsBSTNode* getRight() {
		return right;
	}

	void setLeft(TermsBSTNode* left) {
		this->left = left;
	}
	void setRight(TermsBSTNode* right) {
		this->right = right;
	}
};
