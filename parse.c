#include "parse.h"

char **parse_line(char *line) {
    char **command = (char**)malloc(sizeof(void*)*MAX/2);
    if( command == NULL ){
	perror("error when allocating");
	exit(1);
    }

    int cindex = 0;
    while( (*(command+cindex) = strsep(&line, STR_DELIMS) ) != 0x00 )
	cindex++;
     /* getline adds \n at the end of the string, we don't want that */
    command[cindex-1] = 0x00;
    return command;
}
