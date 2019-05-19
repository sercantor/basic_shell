#include "execute.h"

void execute(char **command) {
    pid_t pid;
    pid = fork();

    if( pid == -1 ) {
	printf("\n Failed forking");
	return;
    } else if ( pid == 0 ) {
	if ( execvp(command[0], command) < 0 ) {
	    printf("\nCould not execute command\n");
	}
	exit(0);
    } else {
	wait(NULL);
	return;
    }


}
