#include "execute.h"

void execute(char **command) {
    pid_t pid;
    pid = fork();

    if(pid == 0){
	if(execvp(command[0], command) == -1)
	    printf("you entered a wrong command\n");
    }
    else if(pid == -1){
	perror("error when forking");
    }
}
