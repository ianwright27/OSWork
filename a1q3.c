#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


// all arguments for sum function
struct sum_args {
    int n;
    int m;
};


// global for total sum
int total=0;


// To prevent segmentation fault since each thread might be trying to access Total
pthread_mutex_t MUT=PTHREAD_MUTEX_INITIALIZER;


// function to sum integers
void *sum_of_integers(void *arguments){
    struct sum_args *args = (struct sum_args *)arguments;
    int n = args->n;
    int m = args->m;

    // sum integers between n and m
    for(int i = n; i <= m; ++i){
        pthread_mutex_lock(&MUT);
        total = total + i;
        pthread_mutex_unlock(&MUT);
    }
    
    // now we access total once more
    pthread_mutex_lock(&MUT);
    printf("[+] Total is :%d", total);
    pthread_mutex_unlock(&MUT);
    
    //exit
    pthread_exit(NULL);
}


int main(int argc, char* argv[]){
    int n, m;
	
	// to capture the integers
	long int_n, int_m, int_x;
	int_n = strtol(argv[0], NULL, 10);
	int_m = strtol(argv[1], NULL, 10);
	int_x = strtol(argv[2], NULL, 10);
	
    // number of threads to create
    int numThreads;

    // grab arguments (typecast to int)
    n = int_n;
    m = int_m;
    numThreads = int_x;


	// Debugging
	printf("\nassignments to int versions of sys args");
	
    // assign arguments to struct
    struct sum_args *args;
    args->n = n;
    args->n = m;


	// Debugging
	printf("\nsum_args struct assigned");

    // create pthread array of "numThread" elements
    pthread_t thread[numThreads];
	
	/*	
	// Debugging
	printf("\narray of threads created");
	*/
    
    for (int i=0; i<numThreads; ++i){

       int thread_status = pthread_create(&thread[i], NULL, &sum_of_integers, (void*)&args);

       // was pthread_create successful?
       if (thread_status !=0){
		   
            printf("\nError creating thread %d", i);

       }
       
    }

    //Join all threads
    for(int i = 0; i < numThreads; ++i){

     pthread_join(thread[i], NULL);

    }
    

    printf("All threads completed.");

    return 0;
}
