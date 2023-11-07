#include "TermsList.h"
#include "TermsBST.h"
#include "MemberQueue.h"

TermsLIST::TermsLIST()
{

}



////return head node
TermsListNode* TermsLIST::getHead()
{
	return head;
}

//Find nodes with the corresponding agreement and increase the count
void TermsLIST::updateCount(char lastLetter) {
    TermsListNode* current = head;
    while (current != nullptr) {
        if (current->lastLetter == lastLetter) {
            current->count++;
            return;
        } //Traverse TermsList until the relevant agreement is found.
        current = current->next;
    }
}



// While adding a new node, the NameBST pointed to by the agreement is also created.
void TermsLIST::addNode(string& name, int age, string& collectionDate, char agreementType) {

    TermsListNode* prev = nullptr;
    for (TermsListNode* tmp = head; tmp; tmp = tmp->next) {
        prev = tmp;
        if (tmp->lastLetter == agreementType) {
            tmp->termsBST->add(name, age, collectionDate, agreementType);
            return;
        }
    }


    TermsListNode* newNode = new TermsListNode(agreementType);

    // create TemrsBST for the relevant agreement
    newNode->termsBST = new TermsBST(); //create new TermsBST node
    newNode->termsBST->add(name, age, collectionDate, agreementType); //calling add to store datas

    if (prev) {
        prev->next = newNode;
        return;
    }
    head = newNode;
}

// Outputs the data of the nodes of the corresponding agreement in TermsList.
//command PRINT is operated through this function
void TermsLIST::print(char agreement, ofstream &flog){
    TermsListNode* prev = nullptr;
    for (TermsListNode* tmp = head; tmp; tmp = tmp->next) {
        prev = tmp;
        if (tmp->lastLetter == agreement) {
            tmp->termsBST->PRINT(flog); //outputs all data related to the agreement to logfile
            return;
        }
    }
    flog << "= = = = = ERROR = = = = =" << endl << "500" << endl << "= = = = = = = = = = = = =" << endl; //Error message  
}