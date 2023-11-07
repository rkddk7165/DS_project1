#pragma once
#include "TermsListNode.h"

class TermsLIST {
private:
    

    TermsListNode* head;

  
  
public:
    
    TermsLIST();
  

    TermsListNode* getHead(); //return head node

    //Find nodes with the corresponding agreement and increase the count
    void updateCount(char lastLetter);

    //While adding a new node, TermsBSTNode of the corresponding agreement is also created
    void addNode(string& name, int age, string& collectionDate, char agreementType);

    // Outputs the data of the nodes of the corresponding agreement in TermsList.
    void print(char agreement, ofstream &flog);
};
