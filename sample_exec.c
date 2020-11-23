#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	
	char * programs[] = {"/bin/ls .", "/bin/neofetch", "/bin/grep"};
	
	char * exec_args[] = {"", "", NULL};
	
	for (int i=0; i<3; ++i){
		pid_t pid = fork();
		
		if (pid == 0){
			// child
			exec_args[i] = programs[i];
			execv(exec_args[0], exec_args);
		}else{
			// main program
			wait(NULL);
			printf("\nFinished executing %s command\n", programs[i]);
		}
	}

	return 0;
}
