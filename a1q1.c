#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[]){
	// will hold PIDs for each level
	int grandParentPID, parentPID, childPID;
	
	// get process id of our main process (grandparent)
	grandParentPID = getpid();
	
	// create child process (parent)
	int parentpid = fork();
	
	if (parentpid == 0){
		// get pid of parent
		parentPID = getpid();
		
		// create new child of parent
		int grandchildpid = fork();
		
		if (grandchildpid == 0){
			childPID = getpid();
			// output
			printf("My process id is %d, my parent's id is %d, and my Grandparent's id is %d\n", childPID, parentPID,  grandParentPID);
		}
	}
	
	return 0;
}
