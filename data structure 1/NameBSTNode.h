#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class NameBSTNode {
private:
	string name;
	int age;
	string collectionDate;
	string expireDate;
	char agreementType;

	NameBSTNode* left; //left child node pointer
	NameBSTNode* right; //right child node pointer

	friend class NameBST; //Declare NameBST as a friend class to access the private part of NameBST
public:
	//calculate expire date by adding the number of months corresponding to collection date to agreement
	NameBSTNode(const string& name, int age, const string& collectionDate, char agreementType)
		: name(name), age(age), collectionDate(collectionDate), agreementType(agreementType), left(nullptr), right(nullptr) {
		expireDate = calculateExpireDate(collectionDate, agreementType);
	}
	//calculate expire date by adding the number of months corresponding to collection date to agreement
	string calculateExpireDate(const string& collectionDate, char agreementType) {
		//Parse collectionDate and separate it into year, month, and day
		int year, month, day;
		sscanf_s(collectionDate.c_str(), "%d - %d - %d", &year, &month, &day);

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

		

		NameBSTNode* getLeft() {
			return left;
	}
		NameBSTNode* getRight() {
			return right;
		}
		void setLeft(NameBSTNode* left) {
			this->left;
		}
		void setRight(NameBSTNode* right) {
			this->right;
		}
};

