# include <stdio.h>
# include <pthread.h>

void *sum_of_integers(void *arguments){
    struct sum_args *args = (struct sum_args *)arguments;
    int n = args->n;
    int m = args->m;

    // sum integers between n and m
    for(int i = n; i <= m; ++i){
        pthread_mutex_lock(&mVar);
        total = total + i;
        pthread_mutex_unlock(&mVar);
    }

    // now we access total once more
    pthread_mutex_lock(&mVar);
    printf("[+] Total is :%d", total);
    pthread_mutex_unlock(&mVar);

    //exit
    pthread_exit(NULL);
}

// all arguments for sum function
struct sum_args {
    int n;
    int m;
};


// global for total sum
int total=0;

// To prevent segmentation fault since each thread might be trying to access Total
pthread_mutex_t mVar=PTHREAD_MUTEX_INITIALIZER;

int main(int argc, char* argv[]){
    int n, m;

    // number of threads to create
    int numThreads;

    // grab arguments (typecast to int)
    n = (int)argv[0];
    m = (int)argv[1];
    numThreads = (int)argv[2];

    // assign arguments to struct
    struct sys_args *args = (struct sys_args *)args;
    args -> n = n;
    args -> n = m;

    // create pthread array of "numThread" elements
    pthread_t thread[numThreads];

    for (int i=0; i<numThreads; ++i){

       int thread_status = pthread_create(&thread[i], NULL, &sum_of_integers, (void*)&args);

       // was pthread_create successful?
       if (thread_status !=0)
       {
            printf("Error creating thread %d", i);
       }
    }

    //Join all threads
    for(int i = 0; i < numThreads; ++i){
     pthread_join(thread[i], NULL);
    }

    cout << "All threads completed." ;

    return 0;
}
