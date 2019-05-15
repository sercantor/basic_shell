#include <stdio.h>
#include <unistd.h>
#include "execute.h"
#include "parse.h"
#include "read.h"

#define PATH_MAX 256

int main() {
    char dir[PATH_MAX];
    getcwd(dir, sizeof(dir));
    while(1){
	printf("%s> ", dir);
	read_line();
    }
}
