#include "parse.h"

char **parse_line(char *line) {
    char **words;
    words = (char**)malloc(sizeof(void*)*MAX/2);
    if(words == NULL){
	perror("error when allocating");
	exit(1);
    }

    int windex = 0;
    while( (*(words+windex) = strsep(&line, " \n")) != 0x00)
	windex++;
    /*
     * getline adds \n at the end of the string, we don't want that
     */
    words[windex-1] = 0x00;
    return words;
}
