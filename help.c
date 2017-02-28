#include <stdio.h>
#include <stdlib.h>

#include "help.h"

void help(void)
{
    printf("\
Usage:\n\
     asco file [options]...\n\
Options:\n\
     -o, --output file         specify a custom output file name\n\
     -h, --help                show this help\n\
     -a, --atbash              use Atbash cipher\n\
     -v, --vigenere cipher     use Vigenere cipher, requires\n\
     --encipher                encipher mode, set by default\n\
     --decipher                switch to decipher mode\n");
    exit(0);
}
