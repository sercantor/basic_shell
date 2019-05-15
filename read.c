#include <stdio.h>
#include "execute.h"
#include "parse.h"

void read_line(){
    char *line = NULL;
    size_t size;
    char **command;

    getline(&line, &size, stdin);
    command = parse_line(line);
    execute(command);
}
