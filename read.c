#include <stdio.h>
#include "execute.h"
#include "parse.h"

char *read_line(){
    char *line = NULL;
    size_t size;

    /* if EOF, exit the program */
    if( getline(&line, &size, stdin) == -1 ) {
	exit(0);
    }

    return line;
}
