#pragma once
#include "MemberQueue.h"



MemberQueue::MemberQueue(int size):front(nullptr), rear(nullptr), maxsize(size) {} //MemberQueue constructor that initializes tha values of variables

MemberQueue::~MemberQueue(){}

//Check if MemberQueue is empty
bool MemberQueue::empty()const{
    return front == nullptr;
}

//Add datas to MemberQueue
bool MemberQueue::push(string& value) {
    if (size() >= maxsize) {
        return false;
    }
    MemberQueueNode* newNode = new MemberQueueNode(value);
    if (empty()) {
        front = rear = newNode; //First node in MemberQueue
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
    return true;
}

//Remove data from front node from MemberQueue
void MemberQueue::pop() {
    if (empty()) {
        
        return;
    }
    //The front node is removed by declaring a temp pointer, which is a temporary node.
    MemberQueueNode* temp = front;
    front = front->next;
    delete temp;
}

//Return first data from MemberQueue
string MemberQueue::peek(){
     if (empty()) {
        
        return "";

    }
    return front->data;
}
//Return size of MemberQueue
int MemberQueue::size() const{
    int count = 0;
    MemberQueueNode* current = front;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

//Return all data in the current MemberQueue
string MemberQueue::getQueueData() {
    string queueData;
    MemberQueueNode* current = front;
    while (current != nullptr) {
        queueData += current->data + "\n";
        current = current->next;
    } //Data is stored in queueData until the rear node of MemberQueue is encountered
    return queueData;
}