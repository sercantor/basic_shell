#include "execute.h"

void execute_redir(char **first_part, char *second_part) {
    pid_t pid;
    pid = fork();

    if( pid == -1 ) {
	printf("\n Failed forking");
	return;
    } else if ( pid == 0 ) {
	int fd;
	if ( (fd = open(second_part, O_WRONLY | O_CREAT | O_TRUNC, 0600))
		== -1) {
	    perror("open outfile");
	    exit(2);
	}
	close(fileno(stdout));
	dup(fd);

	if( execvp(first_part[0], first_part) < 0 ) {
	    perror("failed executing");
	}

	exit(0);
    } else {
	/* waiting for the child to execute
	 */
	wait(NULL);
	return;
    }
}
