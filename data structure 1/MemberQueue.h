
#include "MemberQueueNode.h"

class MemberQueue {
private:
    MemberQueueNode* front;
    MemberQueueNode* rear;
    const int maxsize;

public:
    MemberQueue(int size = 100); //constructor that sets size = 100

    ~MemberQueue(); //destructor

    //Check if MemberQueue is empty
    bool empty()const;

    //Add datas to MemberQueue
    bool push(string& value);

    //Remove data from front node from MemberQueue
    void pop();

    //Return first data from MemberQueue
    string peek();
   
    //Return size of MemberQueue
    int size() const;

    //Return all data in the current MemberQueue
    string getQueueData();
};



