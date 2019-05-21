#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "execute.h"
#include "parse.h"
#include "read.h"

#define MAX_PATH 256

int main() {
    /*
     * can not ctrl+d (EOF) out of the terminal, because
     * in the read function we don't have
     * while( getline > 0 )
     */
    char *line;
    char **command;
    char *dir = malloc(MAX_PATH*sizeof(char));
 
    while(1){ 
	getcwd(dir, 256);
	printf("[ %s ]$ ", dir);
	line = read_line();
	command = parse_line(line);

	/* built-in commands, will move them somewhere, this is very bad */
	if ( !strcmp(command[0], "cd") ) {

	    chdir(command[1]);
	}
	else if ( !strcmp(command[0], "exit") ) {
	    return 1;
	}
	else
	    execute(command);

	free(line);
	free(command);
    }
    free(dir);
}
