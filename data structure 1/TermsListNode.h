#pragma once
#include <iostream>
#include <string>
#include "TermsBST.h"

// Termslist node class
class TermsListNode {
public:
    char lastLetter; //agreement (lastletter of data)
    int count; //the number of members
    TermsListNode* next; //next node pointer
    TermsBST* termsBST; // TemrsBST pointer

    TermsListNode(char letter) : lastLetter(letter), count(1), next(nullptr), termsBST(nullptr) {} //constructor that initializes variables of TermsListNode class
};
