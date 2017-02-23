#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "vigenere.h"

int main(int argc, char *argv[])
{
    FILE *fp = fopen(argv[1], "r");
    FILE *fdp = fopen("output.txt", "w");

    if (fp == NULL)
    {
	fclose(fdp);
    }
    else
    {
	int c = 0, i = 0;
	char *cipher = argv[2];
	int clen = strlen(cipher);
	
	while ((c = getc(fp)) != EOF)
	{
	    if (isalpha(c))
	    {
		c = v_encipher(c, cipher[i++]);
	    }
	    putc(c, fdp);

	    i %= clen;
	}
	fclose(fp);
	fclose(fdp);
    }
}
