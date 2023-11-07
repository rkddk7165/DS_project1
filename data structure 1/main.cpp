#include "Manager.h"

//In the main function, call the run function, which implements command operations and manages overall operations
int main()
{
	Manager manager; //Create an object of manager class
	manager.run("command.txt"); //Execute run with command.txt as the argument to read the command file and output the results

	return 0;
}