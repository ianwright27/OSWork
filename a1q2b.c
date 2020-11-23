/*

    ---------------------
    Here we shall use only File Handling concept in C programming and
    We'll use system calls in the exec() family to execute programs

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
    char *line_arg[] = {"", "--help", NULL};

    // get line by line from file
    while (fgets(line, sizeof(line), file)) {
		line_arg[0] = line;
        lineCount++;
        execv(line_arg[0], line_arg);
        printf("-> Finished executing %s", line);
    }


    // close file  
    fclose(file);

    return 0;
}
