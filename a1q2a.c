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
#include <pthread.h>


void *execute_program(void *value){

	printf("Hello from the second thread\n");
    // incase there's nothing
    return NULL;
}


int main(int argc, char* argv[])
{
	pthread_t thread;

	int num = 123;
	int lineCount = 0;

	printf("Hellow from the first thread");

	pthread_create(&thread, NULL, execute_program, NULL);
	pthread_join(thread, NULL);

    // take filename from system arguments
    char* fileName = argv[1];

    // open file pointer
    FILE* file = fopen(fileName, "r");
    char line[1000]; // will hold line

    // get line by line from file
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
        lineCount++;
    }


    // close file  
    fclose(file);

    return 0;
}
