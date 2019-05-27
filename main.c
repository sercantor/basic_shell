#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "execute.h"
#include "parse.h"
#include "read.h"

#define MAX_PATH 256
#define MAX_STR 64



/* reads, parses and executes, no pipes for now */
int main() {
    char *line;
    char **command;
    char *dir = (char*)malloc(MAX_PATH*sizeof(char));


    
    /*main loop */
    while( 1 ){ 
	getcwd(dir, 256);
	printf("[ %s ]$ ", dir);
	fflush(NULL); /* get ready to take input */
	line = read_line();
	command = parse_line(line);

	/* checking if any redirection exists */
	int redirect_flag = 0;
	int len = -1;
	while( command[++len] != NULL );
	for( int i = 0; i < len; i++ ) {
	    if( !strcmp(command[i], ">") ) {
		redirect_flag= 1;
		}
	    }


	/* built-in commands, will move them somewhere, this is very bad */
	if ( !strcmp(command[0], "cd") ) {
	    chdir(command[1]);
	}
	else if ( !strcmp(command[0], "exit") ) {
	    return 1;
	}
	/*if redirection exists, quickly parse the command
	 * and send it to new execute_redir function
	 */
	else if( redirect_flag ){
	    char **first_part = malloc(20 * sizeof(char*));
	    for( int i = 0; i < 20; i++ ) {
		first_part[i] = malloc(64*sizeof(char));
	    }
	    char *second_part = malloc(64*sizeof(char));
	    int counter = 0;
	    while( strcmp(command[counter], ">") ) {
		strcpy(first_part[counter], command[counter]);
		counter++;
	    }
	    first_part[counter] = 0x00;
	    strcpy(second_part, command[counter + 1]);
	    execute_redir(first_part, second_part);
	}
	else {
	    execute(command);
	}

	free(line);
	free(command);
	}
    free(dir);
}

