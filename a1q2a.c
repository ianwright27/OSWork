/*
    Author: Ian Wright
    -------------------

    README:
    ---------------------
    Here we shall use File Handling concept in C programming.
    We'll use system calls in the exec() family to execute programs
    captured from file handling alongside fork() and wait(), line by line.

    ------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char* argv[])
{

	// main parent PID
	printf("\n\nmain() PID: %d\n", getpid());
	printf("Executing these programs: \n\n\n");
	
	int lineCount = 0;

    // take filename from system arguments
    char* fileName = argv[1];

    // open file pointer
    FILE* file = fopen(fileName, "r");
    char line[1000]; // will hold line

    // get line by line from file
    while (fgets(line, sizeof(line), file)) {
        printf("-> Executing %s", line);
        lineCount++;
        pid_t pid = fork();
        if (pid == 0) {	
			printf("child PID: %d, (program %d)\n\n", getpid(), lineCount);
			execlp(line, line, NULL);
		}else{
			wait(NULL);
		}
    }


    // close file  
    fclose(file);

    return 0;
}
