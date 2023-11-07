#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//Node class
class MemberQueueNode {
public:
    string data;
    MemberQueueNode* next; //pointer to the next node

    MemberQueueNode(string& value) : data(value), next(nullptr) {} //Constructor that initializes the value of the MemberQueue and the next pointer
    ~MemberQueueNode(){} //destructor
};
