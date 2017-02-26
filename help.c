#include <stdio.h>
#include <stdlib.h>

#include "help.h"

void help(void)
{
    printf("\
Usage:\n\
\t asco file [options]...\n\
Options:\n\
\t -o, --output file\t specify a custom output file name\n\
\t -h, --help\t show this help\n");
    exit(0);
}
