#include "Manager.h"


Manager::Manager()
{
}

Manager::~Manager()
{
}

void Manager::run(const char* command)
{
    MemberQueue memberQueue; //creating instance of MemberQueue class
    TermsLIST termsList; //creating instance of TermsLIST class
    NameBST nameBST; //creating instance of NameBST class

    // Read data.txt and store datas in MemberQueue
    ifstream inputFile("data.txt");
    if (!inputFile.is_open()) {
        return ;
    }
    string line;
    while (getline(inputFile, line)) {
        memberQueue.push(line);
    }
    inputFile.close();

    // Open command.txt to read the commands
    // Open log.txt, the file to output the results
    fcmd.open(command);
    flog.open("log.txt");
    if (!fcmd)
    {
        exit(-1);
    }

  
    // Run command
    while (true)
    {
        string cmd;
        if (!getline(fcmd, cmd))
        {
            break;
        }
        //command EXIT to end the program
        if (cmd == "EXIT")
        {
            PrintSuccess("EXIT");
            break;
        }

        // command LOAD to print all member information in MemberQueue
        else if (cmd == "LOAD")
        {
            if (!memberQueue.empty())
            {
                flog << "= = = = = LOAD = = = = =" << endl;
                flog << memberQueue.getQueueData();
                flog << "= = = = = = = = = = = = =" << endl;
            }
            else
            {
                PrintErrorCode(100);
            }
        }
        //command ADD to add new member information to MemberQueue
        else if (cmd.substr(0, 3) == "ADD")
        {
            string data = cmd.substr(4);
            memberQueue.push(data);

            flog << "= = = = = ADD = = = = =" << endl << data << endl << "= = = = = = = = = = = = =" << endl;
        }
        //command QPOP that removes all information of MemberQueue and stores in NameBST, TermsBST, and increasese the number of members of the node with the corresponding agreementType in Termslist
        else if (cmd == "QPOP")
        {
            if(memberQueue.empty())
            {
                PrintErrorCode(300);
            }
            while (!memberQueue.empty())
            {
                string poppedData = memberQueue.peek();
                char lastLetter = poppedData.back(); // To extract the agreement, which is the last letter of popped datas

                termsList.updateCount(lastLetter);

                string data = memberQueue.peek();
                istringstream iss(data);
                string name, collectionDate;
                int age;
                char agreementType;

                if (iss >> name >> age >> collectionDate >> agreementType)
                {
                    nameBST.add(name, age, collectionDate, agreementType);

                    termsList.addNode(name, age, collectionDate, agreementType); // add agreement ny calling addNode function
                } 
                memberQueue.pop(); 
            }
            PrintSuccess("QPOP");
        }
        //command SEARCH is used in SEARCH 'name' format, and retrieves and outputs data on members with tjat name from NameBST
        else if (cmd.substr(0, 6) == "SEARCH")
        {
            string nameToSearch = cmd.substr(7);
            nameBST.search(nameToSearch);
            nameBST.SEARCH(flog, nameToSearch); // save SEARCH results to logfile
        }
        else if (cmd == "PRINT NAME")
        {
            nameBST.PRINT(flog);
        }
        else if (cmd.substr(0, 5) == "PRINT")
        {
            if (cmd.length() < 8)
            {
                // 가입약관을 추출
                string agreement = cmd.substr(6, 1);
                flog << "= = = = = PRINT " << agreement << " = = = = =" << endl;
                termsList.print(*agreement.c_str(), flog);
                flog << "= = = = = = = = = = = = = =" << endl;

            }
            
            else if (cmd == "PRINT NAME")
            {
                nameBST.PRINT(flog); // output in lexicographic order of names
            }
            else
            {
                PrintErrorCode(500);
            }
        }
        //command DELETE NAME to search NameBST to find and remove the name read from the command
        else if (cmd.substr(0, 11) == "DELETE NAME")
        {
            string nameToDelete = cmd.substr(12); //extract name and store it in string variable
            bool success = nameBST.DELETE(nameToDelete);

            if (success)
            {
                PrintSuccess("DELETE");
            }
            else
            {
                PrintErrorCode(600);
            }
        }

        else
        {
            PrintErrorCode(1000);
        }
    }

    // close txt files
    fcmd.close();
    flog.close();
    return;
}
//output success message
void Manager::PrintSuccess(const char* cmd)
{
    flog << "= = = = = " << cmd << " = = = = =" << endl;
    flog << "Success" << endl;
    flog << "= = = = = = = = = = = = = =" << endl << endl;
}
//output error message
void Manager::PrintErrorCode(int num)
{
    flog << "= = = = = ERROR = = = = =" << endl;
    flog << num << endl;
    flog << "= = = = = = = = = = = = =" << endl << endl;
}
