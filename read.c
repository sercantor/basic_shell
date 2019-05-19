#include <stdio.h>
#include "execute.h"
#include "parse.h"

char *read_line(){
    char *line = NULL;
    size_t size;

    getline(&line, &size, stdin);
    return line;
}
