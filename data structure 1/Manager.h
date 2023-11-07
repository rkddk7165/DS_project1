#pragma once
#include "MemberQueue.h"
#include "TermsList.h"
#include "TermsBST.h"
#include "NameBST.h"

using namespace std;
// Manager class that manages commands and overall operations
class Manager
{
private:

	ifstream	fcmd; //command
	ofstream	flog; //log file

	MemberQueue memberQueue;

public:
	Manager();
	~Manager();

	void run(const char* command); //A function that implements the execution conditions and actions of the command and file input/output

	void PrintSuccess(const char* cmd);
	void PrintErrorCode(int num);
};